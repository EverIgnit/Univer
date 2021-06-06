namespace WindowsFormsApp1
{
    partial class Student_F
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Student_F));
            this.FIO_L = new System.Windows.Forms.Label();
            this.SchoolNum_L = new System.Windows.Forms.Label();
            this.ClassNum_L = new System.Windows.Forms.Label();
            this.FIO_TB = new System.Windows.Forms.TextBox();
            this.SchoolNum_TB = new System.Windows.Forms.TextBox();
            this.ClassNum_TB = new System.Windows.Forms.TextBox();
            this.Ok_B = new System.Windows.Forms.Button();
            this.TestMark_L = new System.Windows.Forms.Label();
            this.TestMark_TB = new System.Windows.Forms.TextBox();
            this.Cancel_B = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // FIO_L
            // 
            resources.ApplyResources(this.FIO_L, "FIO_L");
            this.FIO_L.Name = "FIO_L";
            // 
            // SchoolNum_L
            // 
            resources.ApplyResources(this.SchoolNum_L, "SchoolNum_L");
            this.SchoolNum_L.Name = "SchoolNum_L";
            // 
            // ClassNum_L
            // 
            resources.ApplyResources(this.ClassNum_L, "ClassNum_L");
            this.ClassNum_L.Name = "ClassNum_L";
            // 
            // FIO_TB
            // 
            resources.ApplyResources(this.FIO_TB, "FIO_TB");
            this.FIO_TB.Name = "FIO_TB";
            // 
            // SchoolNum_TB
            // 
            resources.ApplyResources(this.SchoolNum_TB, "SchoolNum_TB");
            this.SchoolNum_TB.Name = "SchoolNum_TB";
            // 
            // ClassNum_TB
            // 
            resources.ApplyResources(this.ClassNum_TB, "ClassNum_TB");
            this.ClassNum_TB.Name = "ClassNum_TB";
            // 
            // Ok_B
            // 
            this.Ok_B.DialogResult = System.Windows.Forms.DialogResult.OK;
            resources.ApplyResources(this.Ok_B, "Ok_B");
            this.Ok_B.Name = "Ok_B";
            this.Ok_B.UseVisualStyleBackColor = true;
            // 
            // TestMark_L
            // 
            resources.ApplyResources(this.TestMark_L, "TestMark_L");
            this.TestMark_L.Name = "TestMark_L";
            // 
            // TestMark_TB
            // 
            resources.ApplyResources(this.TestMark_TB, "TestMark_TB");
            this.TestMark_TB.Name = "TestMark_TB";
            // 
            // Cancel_B
            // 
            this.Cancel_B.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            resources.ApplyResources(this.Cancel_B, "Cancel_B");
            this.Cancel_B.Name = "Cancel_B";
            this.Cancel_B.UseVisualStyleBackColor = true;
            // 
            // Student_F
            // 
            this.AcceptButton = this.Ok_B;
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.Cancel_B;
            this.Controls.Add(this.Cancel_B);
            this.Controls.Add(this.TestMark_TB);
            this.Controls.Add(this.TestMark_L);
            this.Controls.Add(this.Ok_B);
            this.Controls.Add(this.ClassNum_TB);
            this.Controls.Add(this.SchoolNum_TB);
            this.Controls.Add(this.FIO_TB);
            this.Controls.Add(this.ClassNum_L);
            this.Controls.Add(this.SchoolNum_L);
            this.Controls.Add(this.FIO_L);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Student_F";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Student_F_FormClosing);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label FIO_L;
        private System.Windows.Forms.Label SchoolNum_L;
        private System.Windows.Forms.Label ClassNum_L;
        private System.Windows.Forms.Button Ok_B;
        private System.Windows.Forms.Label TestMark_L;
        private System.Windows.Forms.Button Cancel_B;
        public System.Windows.Forms.TextBox FIO_TB;
        public System.Windows.Forms.TextBox SchoolNum_TB;
        public System.Windows.Forms.TextBox ClassNum_TB;
        public System.Windows.Forms.TextBox TestMark_TB;
    }
}