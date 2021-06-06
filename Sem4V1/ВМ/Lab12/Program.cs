using System;
using System.Collections.Generic;

namespace MVLab12_v2
{
    class Program
    {
        static readonly double eps = 0.001;
        static readonly List<double> roots = new List<double>();
        static readonly double dx = Math.Pow(10, -10);
        static double root = 0.0;
        static void Main()
        {
            double start, step, end;
            do
            {
                Console.WriteLine("Enter interval start and end, then enter a step:");
                start = Convert.ToDouble(Console.ReadLine());
                end = Convert.ToDouble(Console.ReadLine());
                step = Convert.ToDouble(Console.ReadLine());
                if (start < end && step < end - start && step > 0)
                    break;
                Console.WriteLine("Invalid format!");
            } while (true);
            Method(new Interval(start, end), step);
        }
        static double ValueAt(double x)
        {
            return 5 * x * x * x + 2 * x * x - 15 * x - 6;
        }
        static int Sign(double x)
        {
            return x < 0 ? -1 : x > 0 ? 1 : 0;
        }
        static double DF(double x)
        {
            return (ValueAt(x + dx) - ValueAt(x - dx)) / 2;
        }
        static double FluxAt(double x)
        {
            return DF(x) / dx;
        }
        static double GetAbsMaxFluxOn(Interval i, double step)
        {
            double x = i.GetBegin;
            double AbsMaxFlux = FluxAt(x);
            while (x < i.GetEnd)
            {
                x += step;
                if (AbsMaxFlux < Math.Abs(FluxAt(x)))
                    AbsMaxFlux = Math.Abs(FluxAt(x));
            }
            return AbsMaxFlux;
        }
        static void Method(Interval i, double step)
        {
            double x = i.GetCentre + i.GetRadius * (new Random().Next(1000) + 1) / 1000;
            double t = GetAbsMaxFluxOn(i, step);
            double x0 = x - 1;
            int j = 0;
            Console.WriteLine("Method x(k+1) = x(k)-sign(f'(x(k))*f(x(k))/" + Math.Round(1000 * t) / 1000);
            while (Math.Abs(x - x0) > eps)
            {
                x0 = x;
                j++;
                Console.WriteLine(x);
                x -= Sign(FluxAt(x)) * ValueAt(x) / t;
            }
            root = x;
            if (i.Contains(root))
            {
                Console.WriteLine(root);
                Console.WriteLine(j+" iterations");
                Console.WriteLine("The root is: " + Math.Round(root * 1000000) / 1000000.0);
                roots.Add(root);
            }
        }
    }
}
