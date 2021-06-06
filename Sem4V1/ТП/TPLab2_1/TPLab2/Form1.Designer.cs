namespace TPLab2
{
    partial class TPLab2
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.labelb = new System.Windows.Forms.Label();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.CalcButton = new System.Windows.Forms.Button();
            this.labela = new System.Windows.Forms.Label();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.labeldx = new System.Windows.Forms.Label();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.labelxn = new System.Windows.Forms.Label();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.labelx0 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // textBox6
            // 
            this.textBox6.BackColor = System.Drawing.SystemColors.Info;
            this.textBox6.Location = new System.Drawing.Point(21, 138);
            this.textBox6.Multiline = true;
            this.textBox6.Name = "textBox6";
            this.textBox6.ReadOnly = true;
            this.textBox6.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBox6.Size = new System.Drawing.Size(170, 111);
            this.textBox6.TabIndex = 24;
            // 
            // labelb
            // 
            this.labelb.AutoSize = true;
            this.labelb.Location = new System.Drawing.Point(17, 112);
            this.labelb.Name = "labelb";
            this.labelb.Size = new System.Drawing.Size(13, 13);
            this.labelb.TabIndex = 23;
            this.labelb.Text = "b";
            // 
            // textBox5
            // 
            this.textBox5.Cursor = System.Windows.Forms.Cursors.IBeam;
            this.textBox5.Location = new System.Drawing.Point(53, 112);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(100, 20);
            this.textBox5.TabIndex = 22;
            this.textBox5.TextChanged += new System.EventHandler(this.textBox5_TextChanged);
            // 
            // CalcButton
            // 
            this.CalcButton.Location = new System.Drawing.Point(197, 229);
            this.CalcButton.Name = "CalcButton";
            this.CalcButton.Size = new System.Drawing.Size(75, 23);
            this.CalcButton.TabIndex = 21;
            this.CalcButton.Text = "Вычислить";
            this.CalcButton.UseVisualStyleBackColor = true;
            this.CalcButton.Click += new System.EventHandler(this.CalcButton_Click);
            // 
            // labela
            // 
            this.labela.AutoSize = true;
            this.labela.Location = new System.Drawing.Point(18, 86);
            this.labela.Name = "labela";
            this.labela.Size = new System.Drawing.Size(13, 13);
            this.labela.TabIndex = 20;
            this.labela.Text = "a";
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(53, 86);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(100, 20);
            this.textBox4.TabIndex = 19;
            this.textBox4.TextChanged += new System.EventHandler(this.textBox4_TextChanged);
            // 
            // labeldx
            // 
            this.labeldx.AutoSize = true;
            this.labeldx.Location = new System.Drawing.Point(12, 63);
            this.labeldx.Name = "labeldx";
            this.labeldx.Size = new System.Drawing.Size(19, 13);
            this.labeldx.TabIndex = 18;
            this.labeldx.Text = "dn";
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(53, 60);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(100, 20);
            this.textBox3.TabIndex = 17;
            this.textBox3.TextChanged += new System.EventHandler(this.textBox3_TextChanged);
            // 
            // labelxn
            // 
            this.labelxn.AutoSize = true;
            this.labelxn.Location = new System.Drawing.Point(12, 37);
            this.labelxn.Name = "labelxn";
            this.labelxn.Size = new System.Drawing.Size(18, 13);
            this.labelxn.TabIndex = 16;
            this.labelxn.Text = "xn";
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(53, 34);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 20);
            this.textBox2.TabIndex = 15;
            this.textBox2.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // labelx0
            // 
            this.labelx0.AutoSize = true;
            this.labelx0.Location = new System.Drawing.Point(12, 11);
            this.labelx0.Name = "labelx0";
            this.labelx0.Size = new System.Drawing.Size(18, 13);
            this.labelx0.TabIndex = 14;
            this.labelx0.Text = "x0";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(53, 8);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 13;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // TPLab2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.textBox6);
            this.Controls.Add(this.labelb);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.CalcButton);
            this.Controls.Add(this.labela);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.labeldx);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.labelxn);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.labelx0);
            this.Controls.Add(this.textBox1);
            this.Name = "TPLab2";
            this.Text = "TPLab2";
            this.Load += new System.EventHandler(this.TPLab2_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.Label labelb;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.Button CalcButton;
        private System.Windows.Forms.Label labela;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.Label labeldx;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.Label labelxn;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Label labelx0;
        private System.Windows.Forms.TextBox textBox1;
    }
}

