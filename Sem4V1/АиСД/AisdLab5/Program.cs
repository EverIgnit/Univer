using System;
using System.IO;
using System.Collections.Generic;

class Program
{
	static int j = 0;
	static int step = 0;
	static long time = 0;
	static int compare = 0;
	static int file = 0;
	static int quantity = 0;
	static int length = 0;
	static int size = 0;
	static string writePath = "text.txt";
	static string writePathf1 = "f1.txt";
	static string writePathf2 = "f2.txt";
	static string writePathf3 = "f3.txt";
	static string writePathf4 = "f4.txt";
	static string writePathf5 = "f5.txt";
	static string writePathf6 = "f6.txt";
	static void Main(string[] args)
	{
		Console.WriteLine("Enter amount:");
		size = Convert.ToInt32(Console.ReadLine());
		Console.WriteLine("'1' for random\n'2' for rising\n'3' for descending");
		byte choice = Convert.ToByte(Console.ReadLine());
		switch (choice)
		{
			case 1:
				random(size);
				break;
			case 2:
				rising(size);
				break;
			default:
				descending(size);
				break;
		}
		DateTime Jan1st1970 = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
		long begin = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;
		sort(size);
		time = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds - begin;
		Console.WriteLine("Time: " + time + " mls");
		Console.WriteLine("File: " + file);
		Console.WriteLine("Compare: " + compare);
	}

	public static void random(int size)
	{
		try
		{
			using (StreamWriter writer = new StreamWriter(writePath, false, System.Text.Encoding.Default))
				for (int i = 0; i < size; i++)
				{
					var rand = new Random();
					int temp = (int)(rand.NextDouble() * 1000);
					writer.Write(Convert.ToString(temp) + " ");
				}
		}
		catch (Exception e)
		{
			Console.WriteLine(e.Message);
		}
	}

	public static void rising(int size)
	{
		try
		{
			using (StreamWriter writer = new StreamWriter(writePath, false, System.Text.Encoding.Default))
				for (int i = 1; i <= size; i++)
					writer.Write(Convert.ToString(i) + " ");
		}
		catch (Exception e)
		{
			Console.WriteLine(e.Message);
		}
	}

	public static void descending(int size)
	{
		try
		{
			using (StreamWriter writer = new StreamWriter(writePath, false, System.Text.Encoding.Default))
				for (int i = size; i > 0; i--)
					writer.Write(Convert.ToString(i) + " ");
		}
		catch (Exception e)
		{
			Console.WriteLine(e.Message);
		}
	}

	public static void sort(int size)
	{
		string line;

		try
		{
			using (StreamReader f = new StreamReader(writePath, System.Text.Encoding.Default))
			using (StreamWriter f1 = new StreamWriter(writePathf1, false, System.Text.Encoding.Default))
			using (StreamWriter f2 = new StreamWriter(writePathf2, false, System.Text.Encoding.Default))
			using (StreamWriter f3 = new StreamWriter(writePathf3, false, System.Text.Encoding.Default))
				while ((line = f.ReadLine()) != null)
				{
					f1.Write(Convert.ToString(line) + " ");
					file += 2;
					if ((line = f.ReadLine()) != null)
					{
						f2.Write(Convert.ToString(line) + " ");
						file += 2;
					}
					if ((line = f.ReadLine()) != null)
					{
						f3.Write(Convert.ToString(line) + " ");
						file += 2;
					}
				}
		}
		catch (Exception e)
		{
			Console.WriteLine(e.Message);
		}


		try
		{
			using (StreamReader f = new StreamReader(writePath, System.Text.Encoding.Default))
			using (StreamReader r12 = new StreamReader(writePathf1, System.Text.Encoding.Default))
			using (StreamReader r13 = new StreamReader(writePathf2, System.Text.Encoding.Default))
			using (StreamReader r14 = new StreamReader(writePathf3, System.Text.Encoding.Default))
			using (StreamWriter f42 = new StreamWriter(writePathf4, false, System.Text.Encoding.Default))
			using (StreamWriter f52 = new StreamWriter(writePathf5, false, System.Text.Encoding.Default))
			using (StreamWriter f62 = new StreamWriter(writePathf6, false, System.Text.Encoding.Default))
				step = size / 3;
			if (size % 3 != 0)
				step++;
			length = 1;
			quantity = 3;
		}
		catch (Exception e)
		{
			Console.WriteLine(e.Message);
		}
		quantity = 9;
		length = 3;

		while (true)
		{
			try
			{
				using (StreamReader r24 = new StreamReader(writePathf1, System.Text.Encoding.Default))
				using (StreamReader r25 = new StreamReader(writePathf2, System.Text.Encoding.Default))
				using (StreamReader r26 = new StreamReader(writePathf3, System.Text.Encoding.Default))
				using (StreamWriter f13 = new StreamWriter(writePathf4, false, System.Text.Encoding.Default))
				using (StreamWriter f23 = new StreamWriter(writePathf5, false, System.Text.Encoding.Default))
				{
					using (StreamWriter f33 = new StreamWriter(writePathf6, false, System.Text.Encoding.Default))
					{
						step = size / quantity;
						if (size % quantity != 0)
							step++;
						j = 0;

						outputFile(r24, r25, r26, f13, f23, f33);

					}
				}
				using (StreamReader r23 = new StreamReader(writePathf5, System.Text.Encoding.Default))
				using (StreamReader r33 = new StreamReader(writePathf6, System.Text.Encoding.Default))
					if (r23.ReadLine() == null && r33.ReadLine() == null)
						break;
				quantity *= 3;
				length *= 3;


			}
			catch (Exception e)
			{
				Console.WriteLine(e.Message);
			}
			quantity *= 3;
			step = size / quantity;
			if (size % quantity != 0)
				step++;

			length *= 3;
			j = 0;

			try
			{
				using (StreamReader r14 = new StreamReader(writePathf1, System.Text.Encoding.Default))
				using (StreamReader r24 = new StreamReader(writePathf2, System.Text.Encoding.Default))
				using (StreamReader r34 = new StreamReader(writePathf3, System.Text.Encoding.Default))
				using (StreamWriter f44 = new StreamWriter(writePathf4, false, System.Text.Encoding.Default))
				using (StreamWriter f54 = new StreamWriter(writePathf5, false, System.Text.Encoding.Default))
				{
					using (StreamWriter f64 = new StreamWriter(writePathf6, false, System.Text.Encoding.Default))
					{
						outputFile(r14, r24, r34, f44, f54, f64);

					}
				}
				using (StreamReader r54 = new StreamReader(writePathf5, System.Text.Encoding.Default))
				{
					using (StreamReader r64 = new StreamReader(writePathf6, System.Text.Encoding.Default))
					{
						if (r54.ReadLine() == null && r64.ReadLine() == null)
							break;
						quantity *= 3;
						length *= 3;
					}
				}
			}
			catch (Exception e)
			{
				Console.WriteLine(e.Message);
			}
		}

		static void outputFile(StreamReader r12, StreamReader r13, StreamReader r14, StreamWriter f42, StreamWriter f52, StreamWriter f62)
		{
			string line;
			string[] sline;
			int k = 0;
			for (int i = 0; i < step; i++)
			{
				List<int> list = new List<int>();
				if ((line = r13.ReadLine()) != null)
				{
					sline = r12.ReadLine().Split(' ');
					k = 0;
					foreach (string subl in sline)
					{
						list.Add(Convert.ToInt32(subl));
						if (k >= length)
							break;
						k++;
						file++;
					}
				}
				if ((line = r13.ReadLine()) != null)
				{
					sline = line.Split(' ');
					k = 0;
					foreach (string subl in sline)
					{
						list.Add(Convert.ToInt32(subl));
						if (k >= length)
							break;
						k++;
						file++;
					}
				}
				if ((line = r13.ReadLine()) != null)
				{
					sline = r14.ReadLine().Split(' ');
					k = 0;
					foreach (string subl in sline)
					{
						list.Add(Convert.ToInt32(subl));
						if (k >= length)
							break;
						k++;
						file++;
					}
				}

				list.Sort();

				if (list.Count > 1)
					compare += list.Count;

				if (j == 0)
					foreach (int temp in list)
					{
						f42.Write(Convert.ToString(temp) + " "); ;
						file++;
					}
				else if (j == 1)
					foreach (int temp in list)
					{
						f52.Write(Convert.ToString(temp) + " "); ;
						file++;
					}
				else
					foreach (int temp in list)
					{
						f62.Write(Convert.ToString(temp) + " "); ;
						file++;
					}
				j++;
				if (j == 3)
					j = 0;
			}
		}
	}
}