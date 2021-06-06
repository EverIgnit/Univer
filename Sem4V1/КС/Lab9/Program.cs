using System;
using System.IO;
using System.Net.Security;
using System.Net.Sockets;
using System.Text;

class Program
{
    static void Main()
    {
        Console.WriteLine("Enter an e-mail:");
        string[] email = Console.ReadLine().Split('@');
        if (email.Length != 2 || (!email[0].Contains('.') && !email[1].Contains('.')))
        {
            Console.WriteLine("Invalid email");
            return;
        }
        string addr = email[0], host = email[1];
        Console.WriteLine("Password:");
        string pass = Console.ReadLine();
        Stream stream = null;
        SslStream sslStream= null;
        TcpClient client = null;
        ushort port = 110;
        try
        {
            Console.WriteLine("If uses SSL press Enter, else type anything");
            bool ssl = Console.ReadKey().Key == ConsoleKey.Enter;
            if (ssl) {
                host = $"pop.{host}";
                port = 995;
                addr = $"{email[0]}@{email[1]}";
            }
            Console.WriteLine("Connecting...");
            Connect(ref stream, ref sslStream, ref client, host, port, ssl);
            Console.WriteLine("Successfully connected");
            LogIn(addr, pass, stream);
            Console.WriteLine("Logged in");
            uint nLetters = NLetters(stream);
            Console.WriteLine($"{nLetters} letters are currently in a mailbox");
            Console.WriteLine("Awaiting new ones...");
            while (true)
            {
                uint newNLetters = NLetters(stream);
                if (newNLetters > nLetters)
                {
                    for(uint i=nLetters+1;i<=newNLetters;i++)
                        Console.WriteLine($"New letter recieved:\n{Letter(i, stream)}");
                    nLetters = newNLetters;
                }
                Send(Encoding.ASCII.GetBytes("QUIT\r\n"), stream);
                Connect(ref stream, ref sslStream, ref client, host, port, ssl);
                LogIn(addr, pass, stream);
            }
        }
        catch(SocketException e)
        {
            Console.WriteLine(e.Message);
        }
    }
    static string Letter(uint id, Stream stream)
    {
        byte[] commandBytes = Encoding.UTF8.GetBytes("RETR " + id + "\r\n");
        stream.Write(commandBytes, 0, commandBytes.Length);
        stream.Flush();

        StreamReader sr = new StreamReader(stream);
        string response = "", line;
        try
        {
            Check(sr.ReadLine());
            
            while ((line = sr.ReadLine()) != ".")
            {
                if (!line.Contains("Subject:") && !line.Contains("From:"))
                    continue;
                string text = line.Substring(0, line.IndexOf(':') + 2);

                int whitespace = line.IndexOf(" ", text.Length + 4);
                if (whitespace == -1)
                    whitespace = line.Length;
                string encoded = line.Substring(text.Length + 10, whitespace - text.Length - 12);

                response += text;
                encoded = Encoding.UTF8.GetString(Convert.FromBase64String(encoded));
                response += encoded;
                response += $"{line.Substring(whitespace)}\n";
            }
        }
        catch (Exception e)
        {
            throw new Exception(e.Message);
        }
        return response;
    }
    static uint NLetters(Stream stream)
    {
        return Convert.ToUInt32(Send(Encoding.ASCII.GetBytes("STAT\r\n"), stream).Split(' ')[1]);
    }
    static void Check(string response)
    {
        if (!response.Contains('+'))
            throw new Exception("The server did not respond with a + response");
    }
    static void LogIn(string addr, string pass, Stream stream)
    {
        Send(Encoding.ASCII.GetBytes($"USER {addr}\r\n"), stream);
        Send(Encoding.ASCII.GetBytes($"PASS {pass}\r\n"), stream);
    }
    static string Send(byte[] cmd, Stream stream)
    {
        stream.Write(cmd, 0, cmd.Length);
        stream.Flush();
        string response = new StreamReader(stream).ReadLine();
        Check(response);
        return response;
    }
    static void Connect(ref Stream stream, ref SslStream sslStream, ref TcpClient client, string host, ushort port, bool ssl)
    {
        const ushort defaultTimeout = 60000;
        client = new TcpClient(host, port)
        {
            ReceiveTimeout = defaultTimeout,
            SendTimeout = defaultTimeout
        };
        if (ssl)
        {
            sslStream = new SslStream(client.GetStream(), false)
            {
                ReadTimeout = defaultTimeout,
                WriteTimeout = defaultTimeout
            };
            sslStream.AuthenticateAsClient(host);
            stream = sslStream;
        }
        else
            stream = client.GetStream();
        StreamReader streamReader = new StreamReader(stream);
        string response = streamReader.ReadLine();
        Check(response);
    }
}
