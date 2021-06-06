using System;
using System.IO;
using System.Net.Security;
using System.Net.Sockets;

namespace KR1_3
{
	class Client
	{
		static void Main()
		{
			// TCP no UseSSL POP3 port
			int port = 110;
			Console.Write("Enter a mail address (eg. username@mail.ru):\n->\t");

			// Check email
			string[] s = Console.ReadLine().Split('@');
			if (s.Length != 2)
			{
				Console.WriteLine("Invalid input: Not an email address");
				return;
			}
			if (s[1].IndexOf('.') == -1)
			{
				Console.WriteLine("Invalid input: are you missing a dot in mail server?");
				return;
			}


			Console.Write("If the mail server uses UseSSL/TSL type 1, else type anything\n->\t");
			bool UseSSL = Console.ReadLine() == "1";

			string login, host;

			if (UseSSL == true)
			{
				host = "pop." + s[1];
				login = s[0] + '@' + s[1];
				port = 995;
				UseSSL = true;
			}
			else
			{
				host = s[1];
				login = s[0];
			}

			Console.Write("Enter the password:\n->\t");
			string pass = Console.ReadLine();

			Console.WriteLine($"Connecting to {host}...");
			try
			{
				Stream ns = null;
				SslStream SSLStream = null;
				TcpClient clientSocket = null;

				Connector.Connect(ref ns, ref SSLStream, ref clientSocket, host, port, UseSSL);
				Console.WriteLine($"Connected to {host}");

				Connector.SendSignature(login, pass, ns);

				// Connection is set
				// Amout of letters in mailbox
				int LettersAm = Program.SendStat(ns);
				int NewLettersAm;
				Console.WriteLine($"Letters in a mailbox: {LettersAm}\nAwaiting new letters...\n");

				while (true)
				{
					NewLettersAm = Program.SendStat(ns);
					// if there are new letters, add them
					if (NewLettersAm > LettersAm)
					{
						for (int i = LettersAm + 1; i <= NewLettersAm; i++)
							Console.WriteLine($"New Letter:\n{Program.SendRetr(i, ns)}");
						// Refresh the data
						LettersAm = NewLettersAm;
					}

					// Restart the session to forse update STAT
					Program.SendCommand("QUIT", ns);
					Connector.Connect(ref ns, ref SSLStream, ref clientSocket, host, port, UseSSL);
					Connector.SilentSignature(login, pass, ns);
				}
			}
			// Manage Exception
			catch (SocketException e)
			{
				Console.WriteLine($"Communication error: {e.Message}");
			}
		}
	}
}