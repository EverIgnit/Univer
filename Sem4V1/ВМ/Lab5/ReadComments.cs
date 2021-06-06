/* Маткад  и его скрины отказываются скидываться - server connection error
 */
using System;
class Program
{
    private static void Main(string[] args)
    {
        byte n = 3;
        double[,] a =  {{ 3.14, -0.12, 1.17 },
                        { -0.12, 2.32, -1.45},
                        { 1.17, -1.45, 5.18}}, s = new double[n, n];
        double[] b = { 1.27, 2.13, 3.14 }, x = new double[n], y = new double[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                s[i, j] = 0;
        double tmp;

        for (byte i = 0; i < n; i++)
        {
            tmp = 0;
            for (int k = 0; k < i; k++)
                tmp = tmp + s[k, i]*s[k,i];
            s[i, i] = Math.Sqrt(a[i, i] - tmp);
            for (int j = i; j < n; j++)
            {
                tmp = 0;
                for (byte k = 0; k < i; k++)
                    tmp = tmp + s[k, i] * s[k, j];
                s[i, j] = (a[i, j] - tmp) / s[i, i];
            }
        }
        for (byte i = 0; i < n; i++)
        {
            tmp = 0;
            for (int k = 0; k < i; k++)
                tmp = tmp + s[k, i] * y[k];
            y[i] = (b[i] - tmp) / s[i, i];
        }
        for (int i = n-1; i >=0; i--)
        {
            tmp = 0;
            for (int k = i+1; k < n; k++)
                tmp = tmp + s[i, k] * x[k];
            x[i] = (y[i] - tmp) / s[i, i];
        }
        for (byte i = 0; i < n; i++)
        {
            Console.WriteLine("x[" + i + "]=" + x[i]);
        }
    }
}
