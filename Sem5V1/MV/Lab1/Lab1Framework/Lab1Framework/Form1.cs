using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Windows.Forms;
using LiveCharts;
using LiveCharts.Wpf;

namespace Lab1Framework
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            SeriesCollection series = new SeriesCollection();
            var xi = Settings.xi;
            FuncTable(Settings.x, Settings.y, Settings.h, out double[] xs, out double[] ys);
            Lagrange(xi, xs, ys, Settings.n, out double[] Lres);
            Newthon(xi, xs, ys, Settings.n1, out double[] Nres);
            cartesianChart1.AxisX.Add(new Axis()
            {
                Title = "x",
                Labels = xi.Select(el => el.ToString()).ToList()
            });
            series.Add(new LineSeries()
            {
                Title = "Lagr",
                Values = new ChartValues<double>(Lres)
            });
            series.Add(new LineSeries()
            {
                Title = "Newth",
                Values = new ChartValues<double>(Nres)
            });
            var a = new double[Settings.xi.Length];
            for (int i = 0; i < Settings.xi.Length; i++)
                a[i] = F(Settings.xi[i]);
            var chart = new ChartValues<double>(a);
            series.Add(new LineSeries()
            {
                Title = "ln(x)...",
                Values = chart
            });
            cartesianChart1.Series = series;
        }
        static void Lagrange(double[] x, double[] xs, double[] ys, int n, out double[] res)
        {
            res = new double[x.Length];
            for (int i = 0; i < x.Length; i++)
            {
                double Lnx = 0;
                for (int k = 0; k <= n; k++)
                {
                    double nominator = 1, denominator = 1;
                    for (int j = 0; j <= n; j++)
                        if (j != k)
                        {
                            nominator *= x[i] - xs[j];
                            denominator *= xs[k] - xs[j];
                        }
                    Lnx += nominator / denominator * ys[k];
                }
                res[i] = Settings.round ? Math.Round(Lnx, 2) : Lnx;
            }
        }
        static void Newthon(double[] x, double[] xs, double[] ys, int n, out double[] res)
        {
            res = new double[x.Length];
            for (var i = 0; i < x.Length; i++)
            {
                var Nnx = ys[0];
                for (var k = 1; k <= n; k++)
                {
                    var mult = Y(YParams(0, k), xs, ys);
                    for (var j = 0; j < k; j++)
                        mult *= (x[i] - xs[j]);
                    Nnx += mult;
                }
                res[i] = Settings.round ? Math.Round(Nnx, 2) : Nnx;
            }
        }
        static double Y(IEnumerable<int> yParams, double[] xs, double[] ys)
            => yParams.Count() <= 1 ? ys[yParams.First()] :
            (Y(YParams(1, yParams.Count() - 2), xs, ys) - Y(YParams(0, yParams.Count() - 2), xs, ys))
            / (xs[yParams.Last()] - xs[yParams.First()]);
        static IEnumerable<int> YParams(int startId, int am)
        {
            for (int i = 0; i <= am; i++)
                yield return i + startId;
        }
        static double F(double x) => Math.Log(x) + Math.Pow(x + 1, 3);
        static void FuncTable(int x0, int xn, double h, out double[] xs, out double[] ys)
        {
            int size = (int)((xn - x0) / h) + 1;
            xs = new double[size];
            ys = new double[size];
            for (double x = x0, i = 0; x <= xn && i < size; x += h, i++)
            {
                x = Settings.round ? Math.Round(x, 2) : x;
                xs[(int)i] = x;
                ys[(int)i] = Settings.round ? Math.Round(F(x), 2) : F(x);
            }
        }
    }
    enum Methods { Lagrange, Newthon, MathNetPkgCmn, MathNetPkgLagr }
    static class Settings
    {
        public static int x = 1, y = 2, n = 2, n1 = 3;
        public static double h = 0.2;
        public static double[] xi = { 1.27, 1.55, 1.94 };
        public static bool round = false;
    }
}
