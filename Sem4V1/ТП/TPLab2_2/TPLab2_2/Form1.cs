using System;
using System.Drawing;
using System.Windows.Forms;

namespace TPLab2_2
{
    public partial class TPLab2_2 : Form
    {
        private int[] Mas;
        private int n;

        public TPLab2_2()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            BackColor = Color.LightSkyBlue;
            button2.Enabled = false;
            button3.Enabled = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
            var rand = new Random();
            n = rand.Next() % 15;
            Mas = new int[n];
            for (int i = 0; i < n; i++)
                Mas[i] = rand.Next() % 100 - 50;
            for (int i = 0; i < n; i++)
                textBox1.Text += "Mas[" + i + "] = " + Mas[i] + "\n";
            button2.Enabled = true;
            button3.Enabled = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox2.Text = "";
            changeSign();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int i = 0, pr = 1;
            for (; i < n; i++)
                if (Mas[i] < 0)
                    break;
            for (int j = i + 1; j < n; j++)
                pr *= Mas[j];
            MessageBox.Show("Произведение = " + pr);
        }

        private void changeSign()
        {
            int[] MasCopy = Mas;
            var rand = new Random();
            int neg = 0;
            int i = 0;
            for (; i < n; i++)
                if (MasCopy[i] < 0)
                    neg++;
            int diff = Math.Abs(n - neg * 2);
            bool negMode = neg < n / 2;
            while (diff > 1)
            {
                i = rand.Next() % n;
                if ((MasCopy[i] > 0 && negMode == true) || (MasCopy[i] < 0 && negMode == false))
                {
                    MasCopy[i] *= -1;
                    diff--;
                }
            }
            for (i = 0; i < n; i++)
                textBox2.Text += "Mas[" + i + "] = " + MasCopy[i] + "\n";
        }
    }
}
