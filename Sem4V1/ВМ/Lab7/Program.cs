using System;
/*
2.048
0.086
1.065
-0.65
*/
namespace MVLab7
{
    class Program
    {        
        static void Main(string[] args)
        {
            double eps = 0.001;
            byte n = 4;
            double[,] a =  {{ -0.77, -0.04, 0.21, -0.18 },
                            { 0.45, -1.23, 0.06, 0 },
                            { 0.26, 0.34, -1.11, 0 },
                            {0.05, -0.26, 0.34, -1.12 } };
            double[] b = { -1.24, 0.88, -0.62, 1.17 }, Xn = new double[n], res = new double[n];
            for (byte i = 0; i < n; i++)
                res[i] = b[i] / a[i, i];
            while (true)
            {
                for (byte i = 0; i < n; i++)
                {
                    Xn[i] = b[i] / a[i, i];

                    for (byte j = 0; j < n; j++)
                    {
                        if (i == j) continue;
                        else
                        {
                            Xn[i] -= a[i, j] / a[i, i] * res[j];
                        }
                    }
                }
                bool NeedToBreak = true;
                for (byte i = 0; i < n - 1; i++)
                {
                    if (Math.Abs(Xn[i] - res[i]) > eps)
                    {
                        NeedToBreak = false;
                        break;
                    }
                }
                for (byte i = 0; i < n; i++)
                {
                    res[i] = Xn[i];
                }
                if (NeedToBreak) break;
            }
            for (byte i = 0; i < n; i++)
            {
                Console.WriteLine(res[i]);
            }
        }
    }
}