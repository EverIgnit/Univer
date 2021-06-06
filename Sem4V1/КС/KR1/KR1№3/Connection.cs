using System;
using System.IO;
using System.Net.Security;
using System.Net.Sockets;

namespace KR1_3
{
	static class Connector
	{
		private const int defaultTimeOut = 60000;

		public static void Connect(ref Stream ns, ref SslStream SSLStream, ref TcpClient clientSocket, string host, int port, bool UseSSL)
		{
			// Socket initialisation
			clientSocket = new TcpClient(host, port)
			{
				ReceiveTimeout = defaultTimeOut,
				SendTimeout = defaultTimeOut
			};

			// At this point socket should have connected to the server

			// If SSL usage is required, open a new SSLStream on top of the open TCP stream.
			if (UseSSL == true)
			{
				SSLStream = new SslStream(clientSocket.GetStream(), false)
				{
					ReadTimeout = defaultTimeOut,
					WriteTimeout = defaultTimeOut
				};

				// Authenticate the server
				SSLStream.AuthenticateAsClient(host);
				ns = SSLStream;
			}
			else
				// Use default tcp stream
				ns = clientSocket.GetStream();

			// Fetch the server one-line welcome greeting
			StreamReader sr = new StreamReader(ns);
			string response = sr.ReadLine();

			Program.IsOkResponse(response);
		}

		public static void SendSignature(string login, string pass, Stream ns)
		{
			Console.WriteLine("Sending username to server");
			Program.SendCommand($"USER {login}", ns);

			Console.WriteLine("Succsess\nSending password to server");

			Program.SendCommand($"PASS {pass}", ns);
			Console.WriteLine("Succsess");
		}
		public static void SilentSignature(string login, string pass, Stream ns)
		{
			Program.SendCommand("USER " + login, ns);
			Program.SendCommand("PASS " + pass, ns);
		}
	}
}
