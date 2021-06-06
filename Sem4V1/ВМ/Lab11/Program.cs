using System;

namespace MVLab11
{
    class Program
    {
        static void Main(string[] args)
        {
            /*
             Лабораторная воспроизводит пример из презентации к этой работе.
             Точное условие было непонятно без другого примера.
             */
            Console.WriteLine("ВВЕДИТЕ 1, чтобы запустить стандартный интервал (-5;5)\nЛибо введите свой интервал");
            double eps = 0.01, a, b;
            a = Convert.ToInt32(Console.ReadLine());
            if (a != 1)
                b = Convert.ToInt32(Console.ReadLine());
            else
            {
                a = -5;
                b = 5;
            }
            Console.WriteLine(DivideInHalf(a, b, eps, 1));
            Console.WriteLine(DivideInHalf(a, b, eps, 2));
        }
        static double DivideInHalf(double a, double b, double eps, byte task)
        {
            double x, taskDouble;
            if (a > b)
            {
                a += b;
                b = a - b;
                a -= b;
            }
            do
            {
                x = (a + b) / 2;
                if (task == 1)
                    taskDouble = fx(b) * fx(x);
                else
                    taskDouble = fx2(b) * fx2(x);
                if (taskDouble < 0)
                    a = x;
                else
                    b = x;
            } while (b - a > eps);
            return (a + b) / 2;
        }
        static double fx(double x) {
            return Math.Pow(2, x) + 5 * x - 3;
        }
        static double fx2(double x)
        {
            return 3 * x * x * x * x + 4 * x * x * x * -12 * x * x - 5;
        }
    }
}
