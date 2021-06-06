using System;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Student_F : Form
    {
        public Student_F()
        {
            InitializeComponent();
        }
        private void Student_F_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (DialogResult != DialogResult.OK)
                return;
            try
            {
                FIO_TB.Focus();
                if (FIO_TB.Text.Trim() == "" || FIO_TB.Text.Trim().Split(' ').Length!=3)
                    throw new Exception("ФИО");
                SchoolNum_TB.Focus();
                byte SchoolNum = Convert.ToByte(SchoolNum_TB.Text.Trim());
                if (SchoolNum_TB.Text.Trim() == ""||SchoolNum>200)
                    throw new Exception("Номер школы");
                ClassNum_TB.Focus();
                byte ClassNum = Convert.ToByte(ClassNum_TB.Text.Trim());
                if (ClassNum_TB.Text.Trim() == ""||ClassNum>11)
                    throw new Exception("Номер класса");
                TestMark_TB.Focus();
                byte TestMark = Convert.ToByte(TestMark_TB.Text.Trim());
                if (TestMark_TB.Text.Trim() == "" || TestMark < 2 || TestMark > 5)
                    throw new Exception("Оценка");
            }
            catch (Exception ex)
            {
                e.Cancel = true;
                MessageBox.Show("Неправильный ввод: " + ex.Message);
            }
        }
    }
}
