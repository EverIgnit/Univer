using System;

namespace AisdLab4_v2
{
    class Pick
    {
        public static void sort(int[] array)
        {
            DateTime Jan1st1970 = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
            int[] arr = array;
            long compares = 0, swaps = 0;
            long start =  (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;
            for (int min = 0; min < arr.Length - 1; min++)
            {
                int least = min;
                for (int j = min + 1; j < arr.Length; j++, compares++)
                    if (arr[j] < arr[least])
                        least = j;
                int tmp = arr[min];
                arr[min] = arr[least];
                arr[least] = tmp;
                swaps++;
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