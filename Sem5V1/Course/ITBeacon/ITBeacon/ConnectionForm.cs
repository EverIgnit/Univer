using System;
using System.Windows.Forms;

namespace ITBeacon
{
    public partial class ConnectionForm : Form
    {
        public MainForm PrevForm { get; set; }
        public ConnectionForm(MainForm mainForm)
        {
            InitializeComponent();
            PrevForm = mainForm;
        }
        void Connect_Button_Click(object sender, EventArgs e)
        {
            try
            {
                PrevForm.connection = new(ConnectionString_TB.Text);
                PrevForm.connection?.Open();
                PrevForm.FillTableList();
                PrevForm.Show();
                Close();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        void Exit_Button_Click(object sender, EventArgs e)
            => Close();
    }
}
