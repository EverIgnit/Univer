using System;
using System.IO;
using System.Windows.Forms;
namespace WindowsFormsApp1
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }
        private void Del_B_Click(object sender, EventArgs e)
        {
            if (Students_LB.SelectedIndex < 0)
                return;
            Students_LB.Items.RemoveAt(Students_LB.SelectedIndex);
            if (Students_LB.Items.Count != 0)
                return;
            EditControls(false);
            DeleteControls(false);
            SaveControls(false);
            CalcControls(false);
        }
        private void Add_B_Click(object sender, EventArgs e)
        {
            Student_F dialog = new Student_F();
            if (dialog.ShowDialog() != DialogResult.OK)
                return;
            Student student = new Student(dialog.FIO_TB.Text.Trim(), Convert.ToByte(dialog.SchoolNum_TB.Text.Trim()), Convert.ToByte(dialog.ClassNum_TB.Text.Trim()), Convert.ToByte(dialog.TestMark_TB.Text.Trim()));
            Students_LB.Items.Add(student);
            if (Students_LB.Items.Count == 1)
            {
                SaveControls(true);
                CalcControls(true);
            }
        }
        private void Edit_B_Click(object sender, EventArgs e)
        {
            if (Students_LB.SelectedIndex < 0)
            {
                MessageBox.Show("Не выбран элемент");
                return;
            }
            Student_F dialog = new Student_F();
            if (dialog.ShowDialog() != DialogResult.OK)
                return;
            Student student = new Student(dialog.FIO_TB.Text.Trim(), Convert.ToByte(dialog.SchoolNum_TB.Text.Trim()), Convert.ToByte(dialog.ClassNum_TB.Text.Trim()), Convert.ToByte(dialog.TestMark_TB.Text.Trim()));
            Students_LB.Items[Students_LB.SelectedIndex] = student;
        }
        private void MainForm_Load(object sender, EventArgs e)
        {
            EditControls(false);
            DeleteControls(false);
            SaveControls(false);
            CalcControls(false);
        }
        private void EditControls(bool v)
        {
            Edit_B.Enabled = v;
            Edit_TSB.Enabled = v;
            Edit_TSMI.Enabled = v;
        }
        private void DeleteControls(bool v)
        {
            Del_B.Enabled = v;
            Delete_TSB.Enabled = v;
            Delete_TSMI.Enabled = v;
        }
        private void SaveControls(bool v)
        {
            Save_B.Enabled = v;
            Save_TSB.Enabled = v;
            Save_TSMI.Enabled = v;
        }
        private void CalcControls(bool v)
        {
            Calc_B.Enabled = v;
            Calc_TSB.Enabled = v;
            Calc_TSMI.Enabled = v;
        }
        private void Save_B_Click(object sender, EventArgs e)
        {
            if (Save_FD.ShowDialog() != DialogResult.OK)
                return;
            using (StreamWriter sw = new StreamWriter(File.Open(Save_FD.FileName, FileMode.Create)))
                for (int i = 0; i < Students_LB.Items.Count; i++)
                {
                    Student student = (Student)Students_LB.Items[i];
                    sw.WriteLine(student.GetFIO + ";" + student.GetSchoolNum + ";" + student.GetClassNum + ";" + student.GeTestMark);
                }
            EditControls(false);
            DeleteControls(false);
        }
        private void Load_B_Click(object sender, EventArgs e)
        {
            if (Open_FD.ShowDialog() != DialogResult.OK)
                return;
            Students_LB.Items.Clear();
            try
            {
                using (StreamReader sr = new StreamReader(File.Open(Open_FD.FileName, FileMode.Open)))
                    while (!sr.EndOfStream)
                    {
                        string[] s = sr.ReadLine().Split(';');
                        Student student = new Student(s[0], Convert.ToByte(s[1]), Convert.ToByte(s[2]), Convert.ToByte(s[3]));
                        Students_LB.Items.Add(student);
                    }
            }
            catch (Exception)
            {
                MessageBox.Show("Неверный формат данных в файле");
                return;
            }
            EditControls(false);
            DeleteControls(false);
            CalcControls(true);
            SaveControls(true);
        }
        private void Students_LB_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (Students_LB.SelectedIndex < 0)
                return;
            EditControls(true);
            DeleteControls(true);
            FIO_TSSL.Text = (Students_LB.Items[Students_LB.SelectedIndex] as Student).GetFIO;
            SchoolNum_TSSL.Text = (Students_LB.Items[Students_LB.SelectedIndex] as Student).GetSchoolNum.ToString();
            ClassNum_TSSL.Text = (Students_LB.Items[Students_LB.SelectedIndex] as Student).GetClassNum.ToString();
            TestMark_TSSL.Text = (Students_LB.Items[Students_LB.SelectedIndex] as Student).GeTestMark.ToString();
        }
        private void Calc_B_Click(object sender, EventArgs e)
        {
            Student[] students = new Student[Students_LB.Items.Count];
            for (int i = 0; i < Students_LB.Items.Count; i++)
                students[i] = Students_LB.Items[i] as Student;
            SortByMark(ref students);
            FormatStudents_LB.Items.Clear();
            for (int i = 0; i < Students_LB.Items.Count; i++)
                FormatStudents_LB.Items.Add(students[i].GeTestMark + " - "+ students[i].GetFIO + " " + students[i].GetSchoolNum + " " + students[i].GetClassNum);
        }
        private void SortByMark(ref Student[] students)
        {
            for(int i = 0; i < students.Length; i++)
            {
                for(int j = i; j < students.Length; j++)
                {
                    if (students[j].GeTestMark > students[i].GeTestMark)
                    {
                        Student temp = students[j];
                        students[j] = students[i];
                        students[i] = temp;
                    }
                }
            }
        }
    }
}