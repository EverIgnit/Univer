using System;
namespace AisdLab4_v2
{
    class Quick
    {
        private static long swaps = 0, compares = 0;
        public static void quick_sort_func(int[] array, int low, int high)
        {
            DateTime Jan1st1970 = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
            if (low >= high)
            {
                compares++;
                return;
            }
            int opora = array[low + (high - low) / 2], i = low, j = high;
            while (i <= j)
            {
                while (array[i] < opora)
                {
                    i++;
                    compares++;
                }
                while (array[j] > opora)
                {
                    j--;
                    compares++;
                }
                if (i <= j)
                {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    i++;
                    j--;
                    compares++;
                    swaps++;
                }
            }
            compares++;
            if (low < j)
                quick_sort_func(array, low, j);
            compares++;
            if (high > i)
                quick_sort_func(array, i, high);
        }

        public static void sort(int[] array)
        {
            DateTime Jan1st1970 = new DateTime(1970, 1, 1, 0, 0, 0, DateTimeKind.Utc);
            int[] arr = array;
            long start = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;
            quick_sort_func(arr, 0, arr.Length - 1);
            long finish = (long)(DateTime.UtcNow - Jan1st1970).TotalMilliseconds;
            long time = finish - start;
            Console.WriteLine("Sorted: ");
            for (int i = 0; i < arr.Length; i++)
                Console.Write(arr[i] + "  ");
            Console.WriteLine("\nTime: " + time + "ms");
            Console.WriteLine("Swaps: " + swaps);
            Console.WriteLine("Compares: " + compares);
            swaps = 0;
            compares = 0;

        }
    }
}