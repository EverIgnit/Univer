using System;
class Program
{
    static void Main()
    {
        FuncTable(out double[] xs, out double[] ys);
        Out(xs, ys);
        var res = MathNetMeth(xs, ys);
        foreach (var point in res)
            Console.Write($"{point}\t");
        Console.WriteLine();
        WriteInacc(res);
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
    static double[] MathNetMeth(double[] xs, double[] ys)
    {
        var a = MathNet.Numerics.Interpolate.CubicSpline(xs, ys);
        var MathNetRes = new double[Settings.xi.Length];
        for (int i = 0; i < Settings.xi.Length; i++)
            MathNetRes[i] = a.Interpolate(Settings.xi[i]);
        return MathNetRes;
    }
    static void Out(double[] xs, double[] ys)
    {
        Console.Write("Таблица значений функции:\nx:\t");
        Out(xs);
        Console.Write("\ny:\t");
        Out(ys);
    }
    static double F(double x) => Math.Log(x) + Math.Pow(x + 1, 3);
    static void FuncTable(out double[] xs, out double[] ys)
    {
        int size = (int)((Settings.y - Settings.x) / Settings.h) + 1;
        xs = new double[size];
        ys = new double[size];
        for (double x = Settings.x, i = 0; x <= Settings.y && i < size; x += Settings.h, i++)
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
static class Settings
{
    public static int x = 1, y = 2, n = 2, n1 = 3;
    public static double h = 0.2;
    public static double[] xi = { 1.27, 1.55, 1.94 };
    public static bool round = false;
}
