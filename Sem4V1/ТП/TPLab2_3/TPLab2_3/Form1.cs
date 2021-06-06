using System;
using System.Drawing;
using System.Windows.Forms;

namespace TPLab2_3
{
    public partial class TPLab2_3 : Form
    {
        private int[,] Mas;
        private int n, m;
        public TPLab2_3()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            BackColor = Color.LightSkyBlue;
            ArrRandFill();
            dataGridView1.RowCount = n;
            dataGridView1.ColumnCount = m;
            DataGridFillWithArr();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int i = 0;
            for (; i < n; i++) {
                if(Mas[i, 0] == 1)
                    break;
                if (i == n - 1)
                {
                    textBox1.Text = "Строки нет";
                    return;
                }
            }
            double aver = 0;
            for (int j = 0; j < m; j++)
                aver += Mas[i, j];
            textBox1.Text = i + ": " + aver/m;

        }

        private void ArrRandFill()
        {
            var rand = new Random();
            n = rand.Next() % 4 + 4;
            m = rand.Next() % 3 + 4;
            Mas = new int[n, m];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    Mas[i, j] = rand.Next() % 16 - 8;
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void DataGridFillWithArr()
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                {
                    dataGridView1.Rows[i].Cells[j].Value = Mas[i, j];
                }
            for (int j = 0; j < m; j++)
                dataGridView1.Columns[j].Width = 25;
        }
    }
}
