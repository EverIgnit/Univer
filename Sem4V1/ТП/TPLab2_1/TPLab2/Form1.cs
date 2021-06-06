using System;
using System.Drawing;
using System.Windows.Forms;

namespace TPLab2
{
    public partial class TPLab2 : Form
    {
        public TPLab2()
        {
            InitializeComponent();
        }

        private void TPLab2_Load(object sender, EventArgs e)
        {
            BackColor = Color.AntiqueWhite;
            CalcButton.Enabled = false;
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

        private string s;

        private void CalcButton_Click(object sender, EventArgs e)
        {
            string Sx0 = textBox1.Text, Sxn = textBox2.Text, Sdx = textBox3.Text, Sa = textBox4.Text, Sb = textBox5.Text;
            double x0 = 0, dx = 0, xn = 0, a = 0, b = 0;
            double.TryParse(Sx0, out (x0));
            double.TryParse(Sxn, out (xn));
            double.TryParse(Sdx, out (dx));
            double.TryParse(Sa, out (a));
            double.TryParse(Sb, out (b));
            if ((x0 == 0 && Sx0 != "0") || (xn == 0 && Sxn != "0") || (dx == 0 && Sdx != "0") || (a == 0 && Sa != "0") || (b == 0 && Sb != "0"))
            {
                MessageBox.Show("Invalid value!");
                return;
            }

            textBox6.Text = "";
            s = "";
            for (double x = x0; x <= xn; x += dx)
            {
                s = "x = " + x + "\t" + Convert.ToString(x + Math.Sqrt(Math.Abs(x * x * x + a - b * Math.Pow(Math.E, x))));
                textBox6.Text += "\n" + s;
            }

        }
    }
}
