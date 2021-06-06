using System;
using System.Collections.Generic;

namespace AisdLab4_v2
{
    class Addr
    {
        public static void Algorithm(List<ushort> l, ushort n, ushort m, ushort size)
        {
            ushort[] a = new ushort[200];
            int left = 0, right = n;
            foreach(ushort x in l)
            {
                for (byte i = 0, t = 1; i < m / t; i++, t *= 2)
                    if (x < right / 2)
                        right /= 2;
                    else
                        left = right / 2;
            }
        }
        public  static void sort()
        {
            ushort n = Convert.ToUInt16(Console.ReadLine());
            List<ushort> a = new List<ushort>();
            for (int i = 0; i < n; i++)
                a.Add(Convert.ToUInt16(Console.ReadLine()));
            ushort m = (ushort)(Math.Sqrt(n) + 1);
            DateTime Jan1st1970 = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
            long start;
            start = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;
            Algorithm(a, n, m, (ushort)(n/m));
            Console.WriteLine("Time: " + ((long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds - start));

        }
    }
}