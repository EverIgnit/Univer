using System;
using System.Collections.Generic;
using System.Linq;

namespace MVLab13
{
    class Function
    {
        readonly double eps = 0.001;
        readonly List<Interval> rootIntervals = new List<Interval>();
        readonly List<double> roots = new List<double>();
        double step = 0.01;
        double root = 0.0;
        public double ValueAt(double x)
        {
            return Math.Tan(0.58 * x + 0.1) - x * x;
        }
        public void SetStep(double step)
        {
            this.step = step;
        }
        public double FluxAt(double x)
        {
            return 3 + Math.Sin(x);
        }
        public double FluxFluxAt(double x)
        {
            return Math.Cos(x);
        }
        public double GetRootWithNewtonMethodOn(Interval i)
        {
            double x;
            if (FluxFluxAt(i.GetBegin * FluxAt(i.GetBegin)) > 0)
                x = i.GetBegin;
            else
                x = i.GetEnd;
            int j = 0;
            while (Math.Abs(ValueAt(x)) > eps)
            {
                j++;
                x -= ValueAt(x) / FluxAt(x);
                Console.WriteLine(x);
            }
            root = x;
            if (i.Сontains(root))
            {
                Console.WriteLine("Число итераций : " + j);
                Console.WriteLine("Корень в интервале  " + i + "  : " + root);
                roots.Add(root);
            }
            else
                Console.WriteLine("В интервале " + i + "  нет корней ");
            return root;
        }
        public double GetRootWithChordMethodOn(Interval i)
        {
            double x0, x1;
            if (FluxFluxAt(i.GetBegin * FluxAt(i.GetBegin)) > 0)
            {
                x0 = i.GetBegin;
                x1 = x0 + 2 * eps;
            }
            else
            {
                x0 = i.GetEnd;
                x1 = x0 - 2 * eps;
            }
            Console.WriteLine("Начальное  приближение :" + Math.Round(x0 * 1000000) / 1000000.0);
            int j = 0;
            Console.WriteLine("Второе начальное значение:" + Math.Round(x1 * 1000000) / 1000000.0);
            double x = x1 - ValueAt(x1) * (x1 - x0) / (ValueAt(x1) - ValueAt(x0));
            Console.WriteLine(x);
            while (Math.Abs(x - x1) >= eps)
            {
                x0 = x1;
                x1 = x;
                x = x1 - ValueAt(x1) * (x1 - x0) / (ValueAt(x1) - ValueAt(x0));
                j++;
                Console.WriteLine(x);
            }
            root = x;
            if (i.Сontains(root))
            {
                Console.WriteLine("Число итераций : " + (j + 1));
                Console.WriteLine("Корень в интервале  " + i + "  : " + +Math.Round(root * 1000000) / 1000000.0);
                roots.Add(root);
            }
            else
                Console.WriteLine("В интервале " + i + "  нет корней ");
            return root;
        }
        public void GetRootIntervals(Interval interval)
        {
            double x = interval.GetBegin;
            while (x < interval.GetEnd)
            {
                double x1 = x + step;
                if (ValueAt(x) * ValueAt(x1) < 0 && FluxAt(x) * FluxAt(x1) >= 0)
                    rootIntervals.Add(new Interval(x, x1));
                x = x1;
            }
        }
        public void GetRoots(Interval interval)
        {
            GetRootIntervals(interval);
            for (int i = 0; i < rootIntervals.Count; i++)
                GetRootWithNewtonMethodOn(rootIntervals.ElementAt(i));
        }
        public void OutRootIntervals()
        {
            if (rootIntervals.Count != 0)
            {
                Console.WriteLine("Интервалы которые могут содержать корни : ");
                for (int i = 0; i < rootIntervals.Count; i++)
                    Console.WriteLine(rootIntervals.ElementAt(i));
            }
        }
        public List<Interval> GetRootIntervals()
        {
            return rootIntervals;
        }
        private double Geteps(double root)
        {
            return ValueAt(root) / FluxAt(root);
        }
        public void OutRoots()
        {
            if (roots.Count != 0)
            {
                Console.WriteLine("Корни : ");
                for (int i = 0; i < roots.Count; i++)
                    Console.WriteLine(roots.ElementAt(i) + "  с  погрешностью " + Geteps(roots.ElementAt(i)));
            }
            else
                Console.WriteLine("Функция не имеет корней в данном интервале ");
        }
        public void Out()
        {
            OutRootIntervals();
            OutRoots();
        }
        public void Solve(Interval interval)
        {
            GetRoots(interval);
            Out();
        }
    }
}