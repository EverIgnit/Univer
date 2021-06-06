using System;

namespace AisdLab4_v2
{
    class Exchange
    { 
        public static void sort(int[] array)
        {
            DateTime Jan1st1970 = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
            int[] arr = array;
            long compares = 0, swaps = 0;
            long start =  (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;
            bool isSorted = false;
            int buf;
            while (!isSorted)
            {
                isSorted = true;
                for (int i = 0; i < arr.Length - 1; i++, compares++)
                    if (arr[i] > arr[i + 1])
                    {
                        isSorted = false;
                        buf = arr[i];
                        arr[i] = arr[i + 1];
                        arr[i + 1] = buf;
                        swaps++;
                    }
            }
            long finish =  (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;
            long time = finish - start;
            Console.WriteLine("Sorted: ");
            for (int i = 0; i < arr.Length; i++)
                Console.Write(arr[i] + "  ");
            Console.WriteLine("\nTime: " + time + "ms");
            Console.WriteLine("Swaps: " + swaps);
            Console.WriteLine("Compares: " + compares);



        }
    }
}