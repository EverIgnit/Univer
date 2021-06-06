using System;
namespace MVLab14
{
    class Program
    {
        const double eps = 0.001;
        public delegate double Function(double x);
        public delegate double Function2(double x, double y);
        static void Lab14num1MPI(Function xFunc, Function yFunc)
        {
            Console.Write("Начальное приближение x0: ");
            double x0 = Convert.ToDouble(Console.ReadLine());
            Console.Write("Начальное приближение y0: ");
            double y0 = Convert.ToDouble(Console.ReadLine());
            double x = x0;
            double y = y0;
            int counter = 0;
            do
            {
                counter++;
                x0 = x;
                y0 = y;
                x = xFunc(y);
                y = yFunc(x);
            } while (Math.Max(Math.Abs(x0 - x), Math.Abs(y0 - y)) > eps);
            Console.WriteLine("Кол-во итераций: " + counter);
            Console.WriteLine("Корень x: {0,10:0.00000}", x);
            Console.WriteLine("Корень y: {0,10:0.00000}", y);
        }
        static void Lab14num2(Function2 xFunc, Function2 yFunc)
        {
            Console.Write("Начальное приближение x0: ");
            double x_0 = Convert.ToDouble(Console.ReadLine());
            Console.Write("Начальное приближение y0: ");
            double y_0 = Convert.ToDouble(Console.ReadLine());
            double x = x_0;
            double y = y_0;
            int counter = 0;
            do
            {
                counter++;
                x_0 = x;
                y_0 = y;
                x = xFunc(x, y);
                y = yFunc(x, y);
            } while (Math.Max(Math.Abs(x_0 - x), Math.Abs(y_0 - y)) > eps);
            Console.WriteLine("Кол-во итераций: " + counter);
            Console.WriteLine("Корень x: {0,10:0.00000}", x);
            Console.WriteLine("Корень y: {0,10:0.00000}", y);
        }
        static public void DrawMenu()
        {
            Console.WriteLine("1 - метод МПИ для системы");
            Console.WriteLine("2 - метод Ньютона для системы");
        }
        static double Origin1Func(double x, double y)
        {
            return Math.Cos(y + 0.5) + x - 0.8;
        }
        static double Origin2Func(double x, double y)
        {
            return Math.Sin(x - 1) + y - 0.7;
        }
        static double P1xFunc(double x)
        {
            return -Math.Sin(x);
        }
        static double P1yFunc()
        {
            return 1;
        }
        static double P2xFunc()
        {
            return 2;
        }
        static double P2yFunc(double y)
        {
            return -Math.Cos(y - 0.5);
        }
        static double Jfunc(double x, double y)
        {
            return P1xFunc(x) * P2yFunc(y) - P1yFunc() * P2xFunc();
        }
        static double Ax(double x, double y)
        {
            return Origin1Func(x, y) * P2yFunc(y) - P1yFunc() * Origin2Func(x, y);
        }
        static double Ay(double x, double y)
        {
            return P1xFunc(x) * Origin2Func(x, y) - Origin1Func(x, y) * P2xFunc();
        }
        static double XFunc(double x, double y)
        {
            return x - (Ax(x, y) / Jfunc(x, y));
        }
        static double YFunc(double x, double y)
        {
            return y - (Ay(x, y) / Jfunc(x, y));
        }
        static double YFunc(double y)
        {
            return 1.5 - Math.Cos(y);
        }
        static double XFunc(double x)
        {
            return (1 + Math.Sin(x - 0.5)) / 2;
        }
        static void Main()
        {
            DrawMenu();
            byte menu = Convert.ToByte(Console.ReadLine());
            switch (menu)
            {
                case 1:
                    Lab14num1MPI(XFunc, YFunc);
                    break;
                case 2:
                    Lab14num2(XFunc, YFunc);
                    break;
                default:
                    Console.WriteLine("Некоректный ввод");
                    break;
            }
        }
    }
}
