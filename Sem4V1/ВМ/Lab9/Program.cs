using System;
class Program
{
    static void Main(string[] args)
    {
        byte n = 4, count = 0;
        double[,] A = { { 1, 1.5, 2.5, 3.5 },
                            { 1.5, 1, 2, 1.6 },
                            { 2.5, 2, 1, 1.7 },
                            { 3.5, 1.6, 1.7, 1 } }, An, M, M1, S = new double[n, n];
        double[] X, Y, XV;
        double E = 0.001, xi, xi2, buff, a, b, c;
        for (int i = 0; i < n; i++)
            S[i, i] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            M = new double[n, n];
            M1 = new double[n, n];
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    if (j == k)
                    {
                        M[j, j] = 1;
                        M1[j, j] = 1;
                    }
            for (int j = 0; j < n; M1[i, j] = A[i + 1, j], j++)
                if (i != j)
                    M[i, j] = (-1) * A[i + 1, j] / A[i + 1, i];
                else
                    M[i, j] = 1 / A[i + 1, i];
            S = Func(S, M);
            An = Func(M1, Func(A, M));
            for (int t = 0; t < n; t++)
                for (int j = 0; j < n; j++)
                    A[t, j] = An[t, j];
        }
        X = new double[4];
        xi = Math.Pow(-10, 4) - A[0, 0] * Math.Pow(-10, 3) - A[0, 1] * Math.Pow(-10, 2) - A[0, 2] * (-10) - A[0, 3];
        for (double i = -9.5; i <= 10; i = i + 0.5)
        {
            xi2 = Math.Pow(i, 4) - A[0, 0] * Math.Pow(i, 3) - A[0, 1] * Math.Pow(i, 2) - A[0, 2] * i - A[0, 3];
            if ((xi2 > 0 && xi < 0) || (xi2 < 0 && xi > 0))
            {
                a = i - 0.5;
                b = i;
                c = 0;
                while (Math.Abs(a - b) > 2 * E)
                {
                    c = (a + b) / 2;
                    buff = Math.Pow(c, 4) - A[0, 0] * Math.Pow(c, 3) - A[0, 1] * Math.Pow(c, 2) - A[0, 2] * c - A[0, 3];
                    if ((buff < 0 && xi < 0) || (buff > 0 && xi > 0))
                    {
                        a = c;
                        xi = buff;
                    }
                    else
                    {
                        b = c;
                        xi2 = buff;
                    }
                }
                X[count] = c;
                count++;
            }
            xi = xi2;
        }

        Console.WriteLine("Собственные числа:");
        for (int i = 0; i < 3; i++)
            Console.Write("\t" + X[i]);
        Console.Write("\n\nСобственные вектора:");
        for (int i = 0; i < n; i++)
        {
            Y = new double[n];
            for (int j = 0, p = 3; j < n; j++, p--)
                Y[j] = Math.Pow(X[i], p);
            XV = Func(S, Y);
            Console.Write("\nX" + (i + 1) + ":");
            for (int g = 0; g < 3; g++)
                Console.Write("\t" + XV[g]);
        }
        Console.WriteLine();
    }
    public static double[,] Func(double[,] A, double[,] M)
    {
        int n = 4;
        double[,] C = new double[n, n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int t = 0; t < n; t++)
                    C[i, j] += A[i, t] * M[t, j];
        return C;
    }
    public static double[] Func(double[,] A, double[] Y)
    {
        int n = 4;
        double[] C = new double[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i] += A[i, j] * Y[j];
        return C;
    }
}