using System;
using System.Linq;
class Program
{
    static void Main()
    {
        FuncTable(out double[] xs, out double[] ys);
        Out(xs, ys);
        var lagrRes = Lagrange(xs, ys);
        Out(Methods.Lagrange, lagrRes);
        WriteInacc(lagrRes);
        var newthRes = Newthon(xs, ys);
        Out(Methods.Newthon, newthRes);
        WriteInacc(newthRes);
        var mathNetRes = MathNetMeth(xs, ys);
        Out(Methods.MathNetPkgLagr, mathNetRes);
        WriteInacc(mathNetRes);
    }
    static void WriteInacc(double[] res)
    {
        for (int i = 0; i < res.Length; i++)
        {
            var actualVal = F(Settings.xi[i]);
            Console.Write($"{Math.Abs((res[i] - actualVal) / actualVal / 100)}%\t");
        }
        Console.WriteLine();
    }
    static double[] MathNetMeth(double[]xs, double[] ys)
    {
        var a = MathNet.Numerics.Interpolation.NevillePolynomialInterpolation.Interpolate(xs, ys);
        var MathNetRes = new double[Settings.xi.Length];
        for (int i = 0; i < Settings.xi.Length; i++)
            MathNetRes[i] = a.Interpolate(Settings.xi[i]);
        return MathNetRes;
    }
    static void Out(Methods method, double[] res)
    {
        Console.WriteLine($"Методом {method switch { Methods.Lagrange => "Лагранжа", Methods.Newthon => "Ньютона", _ => "MathNetPkgLagr" }}");
        Out(Settings.xi);
        Console.WriteLine("Соответствуют значения функции:");
        Out(res);
        Console.WriteLine();
    }
    static void Out(double[] xs, double[] ys)
    {
        Console.Write("Таблица значений функции:\nx:\t");
        Out(xs);
        Console.Write("\ny:\t");
        Out(ys);
    }
    static double[] Lagrange(double[] xs, double[] ys)
    {
        var res = new double[Settings.xi.Length];
        for (int i = 0; i < Settings.xi.Length; i++)
        {
            double Lnx = 0;
            for (int k = 0; k <= Settings.n; k++)
            {
                double nominator = 1, denominator = 1;
                for (int j = 0; j <= Settings.n; j++)
                    if (j != k)
                    {
                        nominator *= Settings.xi[i] - xs[j];
                        denominator *= xs[k] - xs[j];
                    }
                Lnx += nominator / denominator * ys[k];
            }
            res[i] = Settings.round ? Math.Round(Lnx, 2) : Lnx;
        }
        return res;
    }
    static double[] Newthon(double[] xs, double[] ys)
    {
        var res = new double[Settings.xi.Length];
        for (var i = 0; i < Settings.xi.Length; i++)
        {
            var Nnx = ys[0];
            for (var k = 1; k <= Settings.n; k++)
            {
                var mult = Y(YParams(0, k), xs, ys);
                for (var j = 0; j < k; j++)
                    mult *= (Settings.xi[i] - xs[j]);
                Nnx += mult;
            }
            res[i] = Settings.round ? Math.Round(Nnx, 2) : Nnx;
        }
        return res;
    }
    static double Y(System.Collections.Generic.IEnumerable<int> yParams, double[] xs, double[] ys) => yParams.Count() <= 1 ? ys[yParams.First()] : (Y(YParams(1, yParams.Count() - 2), xs, ys) - Y(YParams(0, yParams.Count() - 2), xs, ys))/ (xs[yParams.Last()] - xs[yParams.First()]);
    static System.Collections.Generic.IEnumerable<int> YParams(int startId, int am) { for (int i = 0; i <= am; i++) yield return i + startId; }
    static double F(double x) => Math.Log(x) + Math.Pow(x + 1, 3);
    static void FuncTable(out double[] xs, out double[] ys)
    {
        int size = (int)((Settings.y - Settings.x) / Settings.h) + 1;
        xs = new double[size];
        ys = new double[size];
        for (double x = Settings.x, i =0; x <= Settings.y && i < size; x += Settings.h, i++)
        {
            x = Settings.round ? Math.Round(x, 2) : x;
            xs[(int)i] = x;
            ys[(int)i] = Settings.round ? Math.Round(F(x), 2) : F(x);
        }
    }
    static void Out(double[] arr)
    {
        foreach (var el in arr)
            Console.Write($"{el}\t");
        Console.WriteLine();
    }
}
enum Methods { Lagrange, Newthon, MathNetPkgLagr }
static class Settings
{
    public static int x = 1, y = 2, n = 2, n1 = 3;
    public static double h = 0.2;
    public static double[] xi = { 1.27, 1.55, 1.94 };
    public static bool round = false;
}
