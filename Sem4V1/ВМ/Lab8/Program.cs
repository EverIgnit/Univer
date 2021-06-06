using System;

namespace MVLab8
{
    class Program
    {
        static void Main(string[] args)
        {

            double[,] a =  {{ 2.7, 0.3, 1.3},
                            { 0.5, -3.7, 2.8},
                            { 1.1, 2.8, -5.8}};
            double[] b = { 2.1, 1.7, 0.8 }, res = new double[3], Xn = new double[3];
            double eps = 0.001, max = eps + 1;
            for (byte i = 0; i < 3; i++)
                res[i] = b[i] / a[i, i];
            for (byte k = 0; max > eps; k++)
            {
                for (byte i = 0; i < 3; i++)
                {
                    double sum = 0;
                    for (byte j = 0; j <= i - 1; j++)
                        if (j != i)
                            sum -= a[i, j] * (Xn[j]) / a[i, i];
                    double sum2 = 0;
                    for (byte j = i; j < 3; j++)
                        if (j != i)
                            sum -= a[i, j] * (res[j]) / a[i, i];
                    Xn[i] = sum + sum2 + b[i] / a[i, i];
                }
                max = Math.Abs(Xn[0] - res[0]);
                for (byte i = 1; i < 3; i++)
                    if (Math.Abs(Xn[i] - res[i]) > max)
                        max = Math.Abs(Xn[i] - res[i]);
                if (max < eps)
                {
                    for (byte i = 0; i < 3; i++)
                        Console.Write("X" + (i + 1) + ": " + res[i] +"\n");
                    Console.WriteLine("Iterations: " + k);
                    return;
                }
                for (byte i = 0; i < 3; i++)
                    res[i] = Xn[i];
            }
        }
    }
}
