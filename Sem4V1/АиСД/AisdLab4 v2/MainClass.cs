using System;

namespace AisdLab4_v2
{
    class MainClass
    {
        private static int[] arr;
        public static void fill()
        {
            Console.Write("Array Size:\n-> ");
            int n = Convert.ToInt32(Console.ReadLine());
            arr = new int[n];
            var rand = new Random();
            for (int i = 0; i < arr.Length; i++)
                arr[i] = (int)((rand.NextDouble() * 20000) - 10000);
            Console.WriteLine("=-=-=-=-=-=-=-=-=-=-=-=-=");
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i] + "  ");
            }
            Console.WriteLine("\n=-=-=-=-=-=-=-=-=-=-=-=-=");
        }
        public static void Main(string[] args)
        {
            {
                /*
                 Время магическим образом перестало считаться коректно. Вероятно, ошибся, но так и не нашёл
                 */
                fill();
                Console.WriteLine("1 for Pick");
                Console.WriteLine("2 for Insert");
                Console.WriteLine("3 for exchange");
                Console.WriteLine("4 for quick");
                Console.Write("-> ");
                byte number = Convert.ToByte(Console.ReadLine());

                switch (number)
                {
                    case 1:
                            Pick.sort(arr);
                        break;
                    case 2:
                            Insert.sort(arr);
                        break;
                    case 3:
                            Exchange.sort(arr);
                        break;
                    default:
                            Quick.sort(arr);
                        break;
                        /*
                    case 5:
                            Addr.sort(arr);}
                        break;
                        */
                }
            }
        }
    }
}