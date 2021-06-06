using System;

namespace MVLab10
{
    class Program
    {
        static void Main(string[] args)
        {
            byte n = 3;
            double[,] A = { {2.1,1,1.1},
                            {1,2.6,1.1},
                            {1.1,1.1,3.1}};
            double[] w0 = new double[100], w = new double[100], w0norm = new double[100];
            double summ=0, e=1, d=0, d0, eps=0.001;
            w0[0] = 1;
            while (e > eps)
            {
                for (int i = 0; i < n; i++)
                    summ +=  w0[i] * w0[i];
                d0 = Math.Sqrt(summ);
                for (int i = 0; i < n; i++)
                    w0norm[i] = w0[i] / d0;
                for (int i = 0; i < n; i++)
                {
                    w[i] = 0;
                    for (int j = 0; j < n; j++)
                        w[i] = w[i] + A[i, j] * w0norm[j];
                }
                summ = 0;
                for (int i = 0; i < n; i++)
                    summ = summ + w[i] * w[i];
                d = Math.Sqrt(summ);
                e = Math.Abs(d - d0);
                for (int i = 0; i < n; i++)
                    w0[i] = w[i];
                summ = 0;
            }
            Console.WriteLine("\nПервое собственное число матрицы (наибольшее по модулю)\n" + d + "\nА соответствующий ему собственный вектор, имеющий первую норму, равную 1:");
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    Console.Write(A[i, j] + " | ");
            Console.WriteLine();
        }
    }
}
