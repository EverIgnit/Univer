using System;
using System.IO;
using System.Text;

namespace KR1_3
{
	static class Program
	{
		// Nothing to comment
		public static void IsOkResponse(string response)
		{
			if (response == null)
				throw new Exception("The stream used to retrieve responses from was closed");

			if (response.StartsWith($"+", StringComparison.OrdinalIgnoreCase))
				return;
			throw new Exception($"The server did not respond with a + response. The response was: \"{response}\"");
		}
		public static void SendCommand(string command, Stream ns)
		{
			// Convert the command with CRLF afterwards as per RFC to a byte array which can be written
			byte[] commandBytes = Encoding.ASCII.GetBytes(command + "\r\n");

			// Write the command to the server
			ns.Write(commandBytes, 0, commandBytes.Length);
			// Flush the content as we now wait for a response
			ns.Flush();

			// Read the response from the server
			StreamReader sr = new StreamReader(ns);
			string LastServerResponse = sr.ReadLine();

			try
			{
				IsOkResponse(LastServerResponse);
			}
			catch (Exception e)
			{
				throw new Exception(e.Message);
			}
		}
		public static int SendStat(Stream ns)
		{
			byte[] commandBytes = Encoding.ASCII.GetBytes("STAT\r\n");


			ns.Write(commandBytes, 0, commandBytes.Length);
			ns.Flush(); // Flush the content as we now wait for a response

			StreamReader sr = new StreamReader(ns);
			string LastServerResponse = sr.ReadLine();

			try
			{
				IsOkResponse(LastServerResponse);
				return int.Parse(LastServerResponse.Split(' ')[1]); // return amout of messages
			}
			catch (Exception e)
			{
				throw new Exception(e.Message);
			}
		}
		public static string SendRetr(int msg_pos, Stream ns)
		{
			byte[] commandBytes = Encoding.UTF8.GetBytes("RETR " + msg_pos + "\r\n");


			ns.Write(commandBytes, 0, commandBytes.Length);
			ns.Flush(); // Flush the content as we now wait for a response

			StreamReader sr = new StreamReader(ns);
			try
			{
				string LastServerResponse = sr.ReadLine();
				IsOkResponse(LastServerResponse);

				string response = "", line;
				while ((line = sr.ReadLine()) != ".")
				{
					if (line.IndexOf("Subject:") != -1 || line.IndexOf("From:") != -1)
					{
						//get only needed lines and split them into 3 or 2 parts

						//Console.WriteLine("OG:" + line);

						string base_ = line.Substring(0, line.IndexOf(':') + 2);
						//Console.WriteLine("base:" + base_);

						int whitespace = line.IndexOf(" ", base_.Length + 4);
						if (whitespace == -1)
						{
							whitespace = line.Length;
						}
						string encoded = line.Substring(base_.Length + 10, whitespace - base_.Length - 12);
						//Console.WriteLine("encoded:" + encoded);

						string email = line.Substring(whitespace); // From: only
																   //Console.WriteLine("email:" + email);

						response += base_;
						encoded = Base64Decode(encoded);
						response += encoded;
						response += email + "\n";
					}
					//Console.WriteLine(line);
				}
				return response;
			}

			catch (Exception e)
			{
				throw new Exception(e.Message);
			}
		}
		private static string Base64Decode(string base64EncodedData)
		{
			return Encoding.UTF8.GetString(Convert.FromBase64String(base64EncodedData));
		}
	}
}
