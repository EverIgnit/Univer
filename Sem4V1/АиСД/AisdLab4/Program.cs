using System;

namespace AisdLab4
{
	class Program
	{
		static void sort(int[] arr, int b, int e)
		{
			int l = b, r = e, temp,  piv = arr[(l + r) / 2];
			do
			{
				while (arr[l] < piv)
					l++;
				while (arr[r] > piv)
					r--;
				if (l <= r)
				{
					temp = arr[l];
					arr[l] = arr[r];
					arr[r] = temp;
					l++;
					r++;
				}
			} while (l <= r);
			if (b < r)
				sort(arr, b, r);
			if (e > l)
				sort(arr, l, e);
		}
		static void sort1(int[] arr, int b, int e, int ifes, int swaps)
		{
			int l = b, r = e, piv = arr[(l + r) / 2], temp;
			do
			{
				ifes++;
				while (arr[l] < piv)
				{
					l++;
					ifes++;
				}
				ifes++;
				while (arr[r] > piv)
				{
					r--;
					ifes++;
				}
				if (l <= r)
				{
					temp = arr[l];
					arr[l] = arr[r];
					arr[r] = temp;
					l++;
					r++;
					swaps++;
				}
			} while (l <= r);
			if (b < r)
				sort1(arr, b, r, ifes, swaps);
			if (e > l)
				sort1(arr, l, e, ifes, swaps);
		}
		static void Main(string[] args)
		{
			int a;
			a = Convert.ToInt32(Console.ReadLine());
			int[] mas3 = new int[a];
			int[] mas4 = new int[a];
			int[] mas5 = new int[a];
			int[] mas = new int[a];
			for (int i = 0; i < a; i++)
			{
				mas3[i] = i;
				mas[i] = i;
			}
			DateTime Jan1st1970 = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
			long time, start, finish;
			start = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;;
			sort(mas, 0, a);
			finish = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;;
			time = finish - start;
			Console.WriteLine("TIME:" + time );

			int[] mas1 = new int[a];
			int k = a;
			for (int i = 0; i < a; i++)
			{
				mas4[i] = k;
				mas1[i] = k;
				k--;
			}
			start = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;;
			sort(mas1, 0, a);
			finish = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;;
			time = finish - start;
			Console.WriteLine("TIME:" + time );
			var rand = new Random();
			int[] mas2 = new int[a];
			for (int i = 0; i < a; i++)
			{
				mas5[i] = mas2[i] = (int)rand.NextDouble()*100;
			}
			start = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;;
			sort(mas2, 0, a);
			finish = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;;
			time = finish - start;
			Console.WriteLine("TIME:" + time );

			int ifes = 0;
			int swap = 0;
			start = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;;
			sort1(mas3, 0, a, ifes, swap);
			finish = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;;
			time = finish - start;
			Console.WriteLine("IF:" + ifes);
			Console.WriteLine("SWAP:" + swap );

			ifes = 0;
			swap = 0;

			start = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;;
			sort1(mas4, 0, a, ifes, swap);
			finish = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;;
			time = finish - start;
			Console.WriteLine("IF:" + ifes );
			Console.WriteLine("SWAP:" + swap );

			ifes = 0;
			swap = 0;
			start = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;;
			sort1(mas5, 0, a, ifes, swap);
			finish = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;;
			time = finish - start;
			Console.WriteLine("IF:" + ifes );
			Console.WriteLine("SWAP:" + swap );
		}
	}
}
