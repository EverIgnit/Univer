namespace TPLab4
{
    partial class Form1
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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.labelb = new System.Windows.Forms.Label();
            this.labela = new System.Windows.Forms.Label();
            this.labeldx = new System.Windows.Forms.Label();
            this.labelxn = new System.Windows.Forms.Label();
            this.labelx0 = new System.Windows.Forms.Label();
            this.CalcButton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
            this.SuspendLayout();
            // 
            // chart1
            // 
            this.chart1.BackColor = System.Drawing.Color.Gainsboro;
            this.chart1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.chart1.BackImageAlignment = System.Windows.Forms.DataVisualization.Charting.ChartImageAlignmentStyle.Center;
            this.chart1.BackImageTransparentColor = System.Drawing.Color.White;
            this.chart1.BackImageWrapMode = System.Windows.Forms.DataVisualization.Charting.ChartImageWrapMode.Scaled;
            this.chart1.BorderlineDashStyle = System.Windows.Forms.DataVisualization.Charting.ChartDashStyle.Solid;
            this.chart1.BorderlineWidth = 3;
            this.chart1.BorderSkin.BackColor = System.Drawing.Color.YellowGreen;
            this.chart1.BorderSkin.BackGradientStyle = System.Windows.Forms.DataVisualization.Charting.GradientStyle.HorizontalCenter;
            chartArea1.Name = "ChartArea1";
            this.chart1.ChartAreas.Add(chartArea1);
            this.chart1.Cursor = System.Windows.Forms.Cursors.No;
            legend1.Name = "Legend1";
            this.chart1.Legends.Add(legend1);
            this.chart1.Location = new System.Drawing.Point(12, 12);
            this.chart1.Name = "chart1";
            series1.ChartArea = "ChartArea1";
            series1.Legend = "Legend1";
            series1.Name = "Series1";
            this.chart1.Series.Add(series1);
            this.chart1.Size = new System.Drawing.Size(776, 378);
            this.chart1.TabIndex = 0;
            this.chart1.Text = "chart1";
            // 
            // textBox5
            // 
            this.textBox5.Cursor = System.Windows.Forms.Cursors.IBeam;
            this.textBox5.Location = new System.Drawing.Point(436, 418);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(100, 20);
            this.textBox5.TabIndex = 27;
            this.textBox5.TextChanged += new System.EventHandler(this.textBox5_TextChanged);
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(330, 418);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(100, 20);
            this.textBox4.TabIndex = 26;
            this.textBox4.TextChanged += new System.EventHandler(this.textBox4_TextChanged);
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(224, 418);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(100, 20);
            this.textBox3.TabIndex = 25;
            this.textBox3.TextChanged += new System.EventHandler(this.textBox3_TextChanged);
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(118, 418);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 20);
            this.textBox2.TabIndex = 24;
            this.textBox2.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(12, 418);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 23;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // labelb
            // 
            this.labelb.AutoSize = true;
            this.labelb.Location = new System.Drawing.Point(475, 402);
            this.labelb.Name = "labelb";
            this.labelb.Size = new System.Drawing.Size(13, 13);
            this.labelb.TabIndex = 32;
            this.labelb.Text = "b";
            // 
            // labela
            // 
            this.labela.AutoSize = true;
            this.labela.Location = new System.Drawing.Point(368, 402);
            this.labela.Name = "labela";
            this.labela.Size = new System.Drawing.Size(13, 13);
            this.labela.TabIndex = 31;
            this.labela.Text = "a";
            // 
            // labeldx
            // 
            this.labeldx.AutoSize = true;
            this.labeldx.Location = new System.Drawing.Point(257, 402);
            this.labeldx.Name = "labeldx";
            this.labeldx.Size = new System.Drawing.Size(19, 13);
            this.labeldx.TabIndex = 30;
            this.labeldx.Text = "dn";
            // 
            // labelxn
            // 
            this.labelxn.AutoSize = true;
            this.labelxn.Location = new System.Drawing.Point(155, 402);
            this.labelxn.Name = "labelxn";
            this.labelxn.Size = new System.Drawing.Size(18, 13);
            this.labelxn.TabIndex = 29;
            this.labelxn.Text = "xn";
            // 
            // labelx0
            // 
            this.labelx0.AutoSize = true;
            this.labelx0.Location = new System.Drawing.Point(47, 402);
            this.labelx0.Name = "labelx0";
            this.labelx0.Size = new System.Drawing.Size(18, 13);
            this.labelx0.TabIndex = 28;
            this.labelx0.Text = "x0";
            // 
            // CalcButton
            // 
            this.CalcButton.Location = new System.Drawing.Point(563, 402);
            this.CalcButton.Name = "CalcButton";
            this.CalcButton.Size = new System.Drawing.Size(225, 36);
            this.CalcButton.TabIndex = 33;
            this.CalcButton.Text = "Расчёт!";
            this.CalcButton.UseVisualStyleBackColor = true;
            this.CalcButton.Click += new System.EventHandler(this.CalcButton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.CalcButton);
            this.Controls.Add(this.labelb);
            this.Controls.Add(this.labela);
            this.Controls.Add(this.labeldx);
            this.Controls.Add(this.labelxn);
            this.Controls.Add(this.labelx0);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.chart1);
            this.Name = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label labelb;
        private System.Windows.Forms.Label labela;
        private System.Windows.Forms.Label labeldx;
        private System.Windows.Forms.Label labelxn;
        private System.Windows.Forms.Label labelx0;
        private System.Windows.Forms.Button CalcButton;
    }
}

