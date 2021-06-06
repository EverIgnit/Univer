using System;
using System.Drawing;
using System.Windows.Forms;

namespace TPLab3
{
    public partial class TPLab3 : Form
    {
        char[] punct = { '-', '.', ',', ':', ';' };
        int l, ind;
        string s;

        public TPLab3()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            BackColor = Color.LightSkyBlue;
            textBox2.ReadOnly = true;
            textBox2.BackColor = Color.Wheat;
            button1.Enabled = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            s = textBox1.Text;
            l = s.Length;
            if (!checkData())
            {
                MessageBox.Show("Invalid data!");
                return;
            }
            swapWords();
            if (l % 3 == 0)
                s = removeThird();
            textBox1.Text = "";
            textBox2.Text = s;
            textBox2.ReadOnly = false;
            textBox2.BackColor = Color.White;
        }

        private void swapWords()
        {
            string temp;
            int[] dashes = new int[l / 3];
            int am = 0, ind1, ind2;
            for (int i = 0; i != l; i++)
                if (s[i] == '-')
                {
                    dashes[am] = i;
                    am++;
                }
            string s1, s2;
            for (int i = 0; i < am; i++)
            {
                ind1 = leftOfDash(dashes[i]);
                if (ind1 != 0)
                    s1 = s.Substring(ind1, dashes[i] - ind1);
                else
                    s1 = s.Substring(0, dashes[i]);
                ind2 = rightOfDash(dashes[i]);
                s2 = s.Substring(dashes[i]+2, ind2-dashes[i]-1);
                swapParts(ind1, ind2, dashes[i], s1, s2);
            }
        }

        private void swapParts(int ind1, int ind2, int indOfDash, string s1, string s2)
        {
            s = s.Remove(indOfDash+2, ind2 - indOfDash - 1).Insert(indOfDash + 2, s1);
            s = s.Remove(ind1, indOfDash - ind1).Insert(ind1, s2);
        }
        private int leftOfDash(int indOfDash)
        {
            for (int i = indOfDash-1; i > 0; i--)
            {
                for (int p = 0; p < punct.Length; p++)
                {
                    if (s[i] == punct[p] || s[i] == ' ')
                    {
                        return i+1;
                    }
                }
            }
            return 0;
        }

        private int rightOfDash(int indOfDash)
        {
            for (int i = indOfDash+2; i < l; i++)
            {
                for (int p = 0; p < punct.Length; p++)
                {
                    if (s[i] == punct[p]||s[i]==' ')
                    {
                        return i-1;
                    }
                }
            }
            return l-1;
        }

        private string removeThird()
        {
            for (int i = l - 1; i > 0; i -= 3)
            {
                if (s[i] != ' ')
                {
                    i += 2;
                    continue;
                }
                for (int j = 0; j < 5; j++)
                    if (s[i] == punct[j])
                    {
                        i += 2;
                        continue;
                    }
                s.Remove(i);
            }
            return s;
        }

        private bool checkData()
        {
            int i, j;
            for (j = 0; j < 5; j++)
                if (s[0] == punct[j] || (s[l - 1] == punct[j] && punct[j] != '.'))
                    return false;
            for (i = 1; i < l && s[i] != '.'; i++) ;
            for (j = 0; j < l && s[j] != '-'; j++) ;
            if (j == l)
                return false;

            if (s.Length > 200 || i == l || s[l - 1] != '.')
                return false;
            for (i = 1; i < l && s[i] != ' '; i++) ;
            if (i == l)
                return false;
            for (i = 1; i < l - 1; i++)
            {
                for (j = 0; j < 5; j++)
                    if (s[i] == punct[j] && (s[i - 1] == ' ' || s[i + 1] != ' '))
                        return false;
            }
            return true;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            button1.Enabled = true;
        }
    }
}
