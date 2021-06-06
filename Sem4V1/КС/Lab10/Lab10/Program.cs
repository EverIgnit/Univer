using System;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;

namespace Lab10
{
    class Program
    {
        static void Main()
        {
            Start();
            Run();
            Console.ReadKey();
        }
        static void Start()
        {
            DirectoryInfo directoryInfo = new DirectoryInfo(@"..\..\..\Logs");
            log = File.Create($"{directoryInfo.FullName}\\log{directoryInfo.GetFiles().Length+1}.txt");
            server.Start();
            Console.WriteLine($"Server is running. Type http://localhost:8000/ in a browser tab.\n" +
                "You can also add:");
            foreach(var file in SourseFiles)
                Console.WriteLine(file.Name);
        }
        static void Run()
        {
            try
            {
                while (!server.Pending()) ;
                TcpClient client = server.AcceptTcpClient();
                clientStream = client.GetStream();
                StreamReader clientSR = new StreamReader(clientStream);
                while (true)
                {
                    string request = clientSR.ReadLine(), response= File.ReadAllText("404.html");
                    log.Write(Encoding.UTF8.GetBytes(request.ToCharArray(), 0, request.Length), 0, request.Length);
                    clientStream.Flush();
                    request = request.Substring(5, request.IndexOf(' ', 5)-5);
                    if (request == ""||request=="/")
                        response = File.ReadAllText("index.html");
                    else
                        foreach (var file in SourseFiles)
                            if (file.Name == request)
                            {
                                response = File.ReadAllText(file.FullName);
                                break;
                            }
                    log.Write(Encoding.UTF8.GetBytes(response.ToCharArray(), 0, response.Length), 0, response.Length);
                    byte[] resp;
                    string temp = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: ";
                    if (response == File.ReadAllText(@"..\..\..\Sources\404.html"))
                        temp = "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\nContent-Length: ";
                    temp += response.Length + "\r\n\r\n";
                    resp = Encoding.UTF8.GetBytes(temp);
                    clientStream.Write(resp, 0, resp.Length);
                    clientStream.Flush();
                    temp = response;
                    resp = Encoding.UTF8.GetBytes(temp);
                    log.Write(Encoding.UTF8.GetBytes(temp.ToCharArray(), 0, temp.Length), 0, temp.Length);
                    clientStream.Write(resp, 0, resp.Length);
                    clientStream.Flush();
                }
                server.Stop();
                Console.WriteLine("Server stopped");
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }
        static readonly TcpListener server = new TcpListener(IPAddress.Loopback, 9090);
        static Stream clientStream;
        static FileStream log;
        static readonly FileInfo[] SourseFiles = new DirectoryInfo(@"..\..\..\Sources").GetFiles();
    }
}
