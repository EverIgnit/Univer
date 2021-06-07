
namespace CourseWork
{
    partial class ControlForm
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnConnect = new System.Windows.Forms.Button();
            this.tbConnection = new System.Windows.Forms.TextBox();
            this.btnSaveDS = new System.Windows.Forms.Button();
            this.btnSelectTable1 = new System.Windows.Forms.Button();
            this.cmbTable1 = new System.Windows.Forms.ComboBox();
            this.btnSelectTable2 = new System.Windows.Forms.Button();
            this.cmbTable2 = new System.Windows.Forms.ComboBox();
            this.btnJoinTables = new System.Windows.Forms.Button();
            this.dgvResTable = new System.Windows.Forms.DataGridView();
            this.cmbTables = new System.Windows.Forms.ComboBox();
            this.ofdOpenTableFile1 = new System.Windows.Forms.OpenFileDialog();
            this.ofdOpenTableFile2 = new System.Windows.Forms.OpenFileDialog();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.flpRadioJoins = new System.Windows.Forms.FlowLayoutPanel();
            this.saveFileDialog1 = new System.Windows.Forms.SaveFileDialog();
            this.flowLayoutPanel1 = new System.Windows.Forms.FlowLayoutPanel();
            this.btnGenerateData = new System.Windows.Forms.Button();
            this.flowLayoutPanel2 = new System.Windows.Forms.FlowLayoutPanel();
            this.flowLayoutPanel4 = new System.Windows.Forms.FlowLayoutPanel();
            this.flowLayoutPanel3 = new System.Windows.Forms.FlowLayoutPanel();
            this.flowLayoutPanel5 = new System.Windows.Forms.FlowLayoutPanel();
            ((System.ComponentModel.ISupportInitialize)(this.dgvResTable)).BeginInit();
            this.flpRadioJoins.SuspendLayout();
            this.flowLayoutPanel1.SuspendLayout();
            this.flowLayoutPanel2.SuspendLayout();
            this.flowLayoutPanel4.SuspendLayout();
            this.flowLayoutPanel3.SuspendLayout();
            this.flowLayoutPanel5.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnConnect
            // 
            this.btnConnect.Location = new System.Drawing.Point(3, 3);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(75, 23);
            this.btnConnect.TabIndex = 0;
            this.btnConnect.Text = "Connect";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.BtnConnect_Click);
            // 
            // tbConnection
            // 
            this.tbConnection.Location = new System.Drawing.Point(84, 3);
            this.tbConnection.Name = "tbConnection";
            this.tbConnection.Size = new System.Drawing.Size(100, 23);
            this.tbConnection.TabIndex = 1;
            this.tbConnection.Text = "Data Source=localhost;Initial Catalog=DreamHome;Integrated Security=True";
            this.tbConnection.TextChanged += new System.EventHandler(this.TbConnection_TextChanged);
            // 
            // btnSaveDS
            // 
            this.btnSaveDS.Enabled = false;
            this.btnSaveDS.Location = new System.Drawing.Point(190, 3);
            this.btnSaveDS.Name = "btnSaveDS";
            this.btnSaveDS.Size = new System.Drawing.Size(75, 23);
            this.btnSaveDS.TabIndex = 2;
            this.btnSaveDS.Text = "Save DataSet";
            this.btnSaveDS.UseVisualStyleBackColor = true;
            this.btnSaveDS.Click += new System.EventHandler(this.BtnSaveDS_Click);
            // 
            // btnSelectTable1
            // 
            this.btnSelectTable1.Location = new System.Drawing.Point(3, 3);
            this.btnSelectTable1.Name = "btnSelectTable1";
            this.btnSelectTable1.Size = new System.Drawing.Size(164, 23);
            this.btnSelectTable1.TabIndex = 3;
            this.btnSelectTable1.Text = "Select Table1 File";
            this.btnSelectTable1.UseVisualStyleBackColor = true;
            this.btnSelectTable1.Click += new System.EventHandler(this.BtnSelectTable1_Click);
            // 
            // cmbTable1
            // 
            this.cmbTable1.FormattingEnabled = true;
            this.cmbTable1.Location = new System.Drawing.Point(3, 3);
            this.cmbTable1.Name = "cmbTable1";
            this.cmbTable1.Size = new System.Drawing.Size(121, 23);
            this.cmbTable1.TabIndex = 4;
            this.cmbTable1.SelectedIndexChanged += new System.EventHandler(this.CmbTable1_SelectedIndexChanged);
            // 
            // btnSelectTable2
            // 
            this.btnSelectTable2.Location = new System.Drawing.Point(173, 3);
            this.btnSelectTable2.Name = "btnSelectTable2";
            this.btnSelectTable2.Size = new System.Drawing.Size(114, 23);
            this.btnSelectTable2.TabIndex = 5;
            this.btnSelectTable2.Text = "Select Table1 File";
            this.btnSelectTable2.UseVisualStyleBackColor = true;
            this.btnSelectTable2.Click += new System.EventHandler(this.BtnSelectTable2_Click);
            // 
            // cmbTable2
            // 
            this.cmbTable2.FormattingEnabled = true;
            this.cmbTable2.Location = new System.Drawing.Point(130, 3);
            this.cmbTable2.Name = "cmbTable2";
            this.cmbTable2.Size = new System.Drawing.Size(121, 23);
            this.cmbTable2.TabIndex = 6;
            this.cmbTable2.SelectedIndexChanged += new System.EventHandler(this.CmbTable2_SelectedIndexChanged);
            // 
            // btnJoinTables
            // 
            this.btnJoinTables.Enabled = false;
            this.btnJoinTables.Location = new System.Drawing.Point(293, 3);
            this.btnJoinTables.Name = "btnJoinTables";
            this.btnJoinTables.Size = new System.Drawing.Size(75, 23);
            this.btnJoinTables.TabIndex = 7;
            this.btnJoinTables.Text = "Join Tables";
            this.btnJoinTables.UseVisualStyleBackColor = true;
            this.btnJoinTables.Click += new System.EventHandler(this.BtnJoinTables_Click);
            // 
            // dgvResTable
            // 
            this.dgvResTable.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvResTable.Location = new System.Drawing.Point(130, 3);
            this.dgvResTable.Name = "dgvResTable";
            this.dgvResTable.RowTemplate.Height = 25;
            this.dgvResTable.Size = new System.Drawing.Size(433, 246);
            this.dgvResTable.TabIndex = 8;
            // 
            // cmbTables
            // 
            this.cmbTables.FormattingEnabled = true;
            this.cmbTables.Location = new System.Drawing.Point(3, 3);
            this.cmbTables.Name = "cmbTables";
            this.cmbTables.Size = new System.Drawing.Size(121, 23);
            this.cmbTables.TabIndex = 9;
            this.cmbTables.SelectedIndexChanged += new System.EventHandler(this.CmbTables_SelectedIndexChanged);
            // 
            // ofdOpenTableFile1
            // 
            this.ofdOpenTableFile1.DefaultExt = "xml";
            this.ofdOpenTableFile1.FileName = "ofdOpenTableFile1";
            this.ofdOpenTableFile1.Filter = "XML Files (*.xml)|*.xml";
            this.ofdOpenTableFile1.FilterIndex = 0;
            // 
            // ofdOpenTableFile2
            // 
            this.ofdOpenTableFile2.DefaultExt = "xml";
            this.ofdOpenTableFile2.FileName = "ofdOpenTableFile2";
            this.ofdOpenTableFile2.Filter = "XML Files (*.xml)|*.xml";
            this.ofdOpenTableFile2.FilterIndex = 0;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(3, 3);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(88, 19);
            this.radioButton1.TabIndex = 10;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "Full Join";
            this.radioButton1.UseVisualStyleBackColor = true;
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Enabled = false;
            this.radioButton2.Location = new System.Drawing.Point(97, 3);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(130, 19);
            this.radioButton2.TabIndex = 11;
            this.radioButton2.Text = "Auto Inner Join";
            this.radioButton2.UseVisualStyleBackColor = true;
            // 
            // flpRadioJoins
            // 
            this.flpRadioJoins.Controls.Add(this.radioButton1);
            this.flpRadioJoins.Controls.Add(this.radioButton2);
            this.flpRadioJoins.Location = new System.Drawing.Point(257, 3);
            this.flpRadioJoins.Name = "flpRadioJoins";
            this.flpRadioJoins.Size = new System.Drawing.Size(295, 39);
            this.flpRadioJoins.TabIndex = 13;
            // 
            // saveFileDialog1
            // 
            this.saveFileDialog1.DefaultExt = "xml";
            this.saveFileDialog1.FileName = "dataset";
            this.saveFileDialog1.Filter = "XML Files (*.xml)|*.xml";
            this.saveFileDialog1.FilterIndex = 0;
            // 
            // flowLayoutPanel1
            // 
            this.flowLayoutPanel1.Controls.Add(this.btnConnect);
            this.flowLayoutPanel1.Controls.Add(this.tbConnection);
            this.flowLayoutPanel1.Controls.Add(this.btnSaveDS);
            this.flowLayoutPanel1.Controls.Add(this.btnGenerateData);
            this.flowLayoutPanel1.Location = new System.Drawing.Point(3, 3);
            this.flowLayoutPanel1.Name = "flowLayoutPanel1";
            this.flowLayoutPanel1.Size = new System.Drawing.Size(449, 38);
            this.flowLayoutPanel1.TabIndex = 14;
            // 
            // btnGenerateData
            // 
            this.btnGenerateData.Enabled = false;
            this.btnGenerateData.Location = new System.Drawing.Point(271, 3);
            this.btnGenerateData.Name = "btnGenerateData";
            this.btnGenerateData.Size = new System.Drawing.Size(97, 23);
            this.btnGenerateData.TabIndex = 3;
            this.btnGenerateData.Text = "Generate Data";
            this.btnGenerateData.UseVisualStyleBackColor = true;
            this.btnGenerateData.Click += new System.EventHandler(this.BtnGenerateData_Click);
            // 
            // flowLayoutPanel2
            // 
            this.flowLayoutPanel2.Controls.Add(this.btnSelectTable1);
            this.flowLayoutPanel2.Controls.Add(this.btnSelectTable2);
            this.flowLayoutPanel2.Controls.Add(this.btnJoinTables);
            this.flowLayoutPanel2.Location = new System.Drawing.Point(3, 47);
            this.flowLayoutPanel2.Name = "flowLayoutPanel2";
            this.flowLayoutPanel2.Size = new System.Drawing.Size(526, 27);
            this.flowLayoutPanel2.TabIndex = 15;
            // 
            // flowLayoutPanel4
            // 
            this.flowLayoutPanel4.Controls.Add(this.cmbTables);
            this.flowLayoutPanel4.Controls.Add(this.dgvResTable);
            this.flowLayoutPanel4.Location = new System.Drawing.Point(3, 144);
            this.flowLayoutPanel4.Name = "flowLayoutPanel4";
            this.flowLayoutPanel4.Size = new System.Drawing.Size(634, 249);
            this.flowLayoutPanel4.TabIndex = 17;
            // 
            // flowLayoutPanel3
            // 
            this.flowLayoutPanel3.Controls.Add(this.cmbTable1);
            this.flowLayoutPanel3.Controls.Add(this.cmbTable2);
            this.flowLayoutPanel3.Controls.Add(this.flpRadioJoins);
            this.flowLayoutPanel3.Location = new System.Drawing.Point(3, 80);
            this.flowLayoutPanel3.Name = "flowLayoutPanel3";
            this.flowLayoutPanel3.Size = new System.Drawing.Size(645, 58);
            this.flowLayoutPanel3.TabIndex = 16;
            // 
            // flowLayoutPanel5
            // 
            this.flowLayoutPanel5.Controls.Add(this.flowLayoutPanel1);
            this.flowLayoutPanel5.Controls.Add(this.flowLayoutPanel2);
            this.flowLayoutPanel5.Controls.Add(this.flowLayoutPanel3);
            this.flowLayoutPanel5.Controls.Add(this.flowLayoutPanel4);
            this.flowLayoutPanel5.FlowDirection = System.Windows.Forms.FlowDirection.TopDown;
            this.flowLayoutPanel5.Location = new System.Drawing.Point(12, 12);
            this.flowLayoutPanel5.Name = "flowLayoutPanel5";
            this.flowLayoutPanel5.Size = new System.Drawing.Size(759, 426);
            this.flowLayoutPanel5.TabIndex = 18;
            // 
            // ControlForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveBorder;
            this.ClientSize = new System.Drawing.Size(800, 488);
            this.Controls.Add(this.flowLayoutPanel5);
            this.Name = "ControlForm";
            this.Text = "ControlForm";
            ((System.ComponentModel.ISupportInitialize)(this.dgvResTable)).EndInit();
            this.flpRadioJoins.ResumeLayout(false);
            this.flpRadioJoins.PerformLayout();
            this.flowLayoutPanel1.ResumeLayout(false);
            this.flowLayoutPanel1.PerformLayout();
            this.flowLayoutPanel2.ResumeLayout(false);
            this.flowLayoutPanel4.ResumeLayout(false);
            this.flowLayoutPanel3.ResumeLayout(false);
            this.flowLayoutPanel5.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.TextBox tbConnection;
        private System.Windows.Forms.Button btnSaveDS;
        private System.Windows.Forms.Button btnSelectTable1;
        private System.Windows.Forms.ComboBox cmbTable1;
        private System.Windows.Forms.Button btnSelectTable2;
        private System.Windows.Forms.ComboBox cmbTable2;
        private System.Windows.Forms.Button btnJoinTables;
        private System.Windows.Forms.DataGridView dgvResTable;
        private System.Windows.Forms.ComboBox cmbTables;
        private System.Windows.Forms.OpenFileDialog ofdOpenTableFile1;
        private System.Windows.Forms.OpenFileDialog ofdOpenTableFile2;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.FlowLayoutPanel flpRadioJoins;
        private System.Windows.Forms.SaveFileDialog saveFileDialog1;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel1;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel2;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel4;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel3;
        private System.Windows.Forms.FlowLayoutPanel flowLayoutPanel5;
        private System.Windows.Forms.Button btnGenerateData;
    }
}

