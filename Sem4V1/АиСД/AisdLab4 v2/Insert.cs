using System;
using System.Runtime.ConstrainedExecution;

namespace AisdLab4_v2
{
    class Insert
    {
        
        public static void sort(int[] array)
        {
            DateTime Jan1st1970 = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
            int[] arr = array;
            long start = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;
            long swaps = 0, compares = 0;
            for (int left = 0; left < arr.Length; left++)
            {
                int value = arr[left];
                int i = left - 1;
                for (; i >= 0; i--)
                {
                    compares++;
                    if (value <= arr[i])
                        break;
                    swaps++;
                    arr[i + 1] = arr[i];
                }
                arr[i + 1] = value;
            }

            long final = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;
            long time = final - start;
            Console.WriteLine("Sorted: ");
            for (int i = 0; i < arr.Length; i++)
                Console.Write(arr[i] + "  ");
            Console.WriteLine("\nTime: " + time + "ms");
            Console.WriteLine("Swaps: " + swaps);
            Console.WriteLine("Compares: " + compares);
        }
    }
}