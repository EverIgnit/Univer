using System;
using System.Collections.Specialized;
using System.ComponentModel;

namespace MVLab6
{
    class Program
    {
        static void Main(string[] args)
        {
            double[,] a =  {{ 3.14, -0.12, 0 },
                        { -0.12, 2.32, -1.45},
                        { 0, -1.45, 5.18}};
            double[] b = { 1.27, 2.13, 3.14 };
            double[] x = new double[2], y = new double[2], res = new double[3];
            x[0] = (-1) * a[0, 1] / a[0, 0];
            y[0] = b[0] / a[0, 0];
            for(byte i = 1; i < 2; i++)
            {
                x[i] = (-1) * a[i, i + 1] / (x[i - 1] * a[i, i - 1] + a[i, i]);
                y[i] = (b[i] - a[i, i - 1] * y[i - 1]) / (x[i - 1] * a[i, i - 1]+a[i,i]);
            }
            res[2] = (b[2] - a[2, 1] * y[1]) / (a[2, 2] + a[2, 1] * x[1]);
            for (sbyte i = 1; i >= 0; i--)
                res[i] = x[i] * res[i + 1] + y[i];
            for (byte i = 0; i < 3; i++)
                Console.WriteLine(res[i]);
        }
    }
}
