using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TPLab4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            BackColor = Color.AntiqueWhite;
            CalcButton.Enabled = false;
            chart1.Series[0].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            chart1.Series[0].BorderWidth = 3;
            chart1.Series[0].LegendText = "GraphFromLab2";
            chart1.Series[0].Color = Color.Coral;
        }
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if (textBox1.Text != null)
                CalcButton.Enabled = true;
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            if (textBox2.Text != null)
                CalcButton.Enabled = true;
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            if (textBox3.Text != null)
                CalcButton.Enabled = true;
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            if (textBox4.Text != null)
                CalcButton.Enabled = true;
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            if (textBox5.Text != null)
                CalcButton.Enabled = true;
        }

        private void CalcButton_Click(object sender, EventArgs e)
        {
            string Sx0 = textBox1.Text, Sxn = textBox2.Text, Sdx = textBox3.Text, Sa = textBox4.Text, Sb = textBox5.Text;
            double x0 = 0, dx = 0, xn = 0, a = 0, b = 0;
            double.TryParse(Sx0, out (x0));
            double.TryParse(Sxn, out (xn));
            double.TryParse(Sdx, out (dx));
            double.TryParse(Sa, out (a));
            double.TryParse(Sb, out (b));
            int size = Convert.ToInt32((xn - x0) / dx) + 1;
            if ((x0 == 0 && Sx0 != "0") || (xn == 0 && Sxn != "0") || (dx == 0 && Sdx != "0") || (a == 0 && Sa != "0") || (b == 0 && Sb != "0"))
            {
                MessageBox.Show("Invalid value!");
                return;
            }
            double[] arrY = new double[size];
            double[] arrX = new double[size];

            int i = 0;
            for (double x = x0; x <= xn; x += dx, i++)
            {
                arrX[i] = x;
                arrY[i] = x + Math.Sqrt(Math.Abs(x * x * x + a - b * Math.Pow(Math.E, x)));
            }

            chart1.ChartAreas[0].AxisX.Minimum = x0;
            chart1.ChartAreas[0].AxisX.Maximum = xn;
            chart1.ChartAreas[0].AxisX.MajorGrid.Interval = dx;
            chart1.Series[0].Points.DataBindXY(arrX, arrY);
        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }
    }
}
