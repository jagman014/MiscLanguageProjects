namespace FirstApp
{
    partial class FrmFirstApp
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FrmFirstApp));
            this.LblTitle = new System.Windows.Forms.Label();
            this.TxtName = new System.Windows.Forms.TextBox();
            this.PicOne = new System.Windows.Forms.PictureBox();
            this.PicTwo = new System.Windows.Forms.PictureBox();
            this.BtnHello = new System.Windows.Forms.Button();
            this.BtnExit = new System.Windows.Forms.Button();
            this.GrpMood = new System.Windows.Forms.GroupBox();
            this.RBtnSad = new System.Windows.Forms.RadioButton();
            this.RBtnHappy = new System.Windows.Forms.RadioButton();
            this.GrpOther = new System.Windows.Forms.GroupBox();
            this.radioButton4 = new System.Windows.Forms.RadioButton();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.PicHappy = new System.Windows.Forms.PictureBox();
            this.PicSad = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.PicOne)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.PicTwo)).BeginInit();
            this.GrpMood.SuspendLayout();
            this.GrpOther.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.PicHappy)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.PicSad)).BeginInit();
            this.SuspendLayout();
            // 
            // LblTitle
            // 
            this.LblTitle.AutoSize = true;
            this.LblTitle.Font = new System.Drawing.Font("Segoe UI", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.LblTitle.Location = new System.Drawing.Point(45, 24);
            this.LblTitle.Name = "LblTitle";
            this.LblTitle.Size = new System.Drawing.Size(218, 21);
            this.LblTitle.TabIndex = 0;
            this.LblTitle.Text = "Welcome To My First Program";
            // 
            // TxtName
            // 
            this.TxtName.Location = new System.Drawing.Point(45, 67);
            this.TxtName.Name = "TxtName";
            this.TxtName.Size = new System.Drawing.Size(227, 23);
            this.TxtName.TabIndex = 1;
            // 
            // PicOne
            // 
            this.PicOne.Image = global::FirstApp.Properties.Resources.rgb;
            this.PicOne.Location = new System.Drawing.Point(45, 96);
            this.PicOne.Name = "PicOne";
            this.PicOne.Size = new System.Drawing.Size(98, 97);
            this.PicOne.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.PicOne.TabIndex = 2;
            this.PicOne.TabStop = false;
            // 
            // PicTwo
            // 
            this.PicTwo.Image = ((System.Drawing.Image)(resources.GetObject("PicTwo.Image")));
            this.PicTwo.Location = new System.Drawing.Point(173, 96);
            this.PicTwo.Name = "PicTwo";
            this.PicTwo.Size = new System.Drawing.Size(99, 97);
            this.PicTwo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.PicTwo.TabIndex = 3;
            this.PicTwo.TabStop = false;
            // 
            // BtnHello
            // 
            this.BtnHello.Location = new System.Drawing.Point(302, 67);
            this.BtnHello.Name = "BtnHello";
            this.BtnHello.Size = new System.Drawing.Size(75, 23);
            this.BtnHello.TabIndex = 4;
            this.BtnHello.Text = "Hello";
            this.BtnHello.UseVisualStyleBackColor = true;
            this.BtnHello.Click += new System.EventHandler(this.BtnHello_Click);
            // 
            // BtnExit
            // 
            this.BtnExit.Location = new System.Drawing.Point(408, 67);
            this.BtnExit.Name = "BtnExit";
            this.BtnExit.Size = new System.Drawing.Size(75, 23);
            this.BtnExit.TabIndex = 5;
            this.BtnExit.Text = "Exit";
            this.BtnExit.UseVisualStyleBackColor = true;
            this.BtnExit.Click += new System.EventHandler(this.BtnExit_Click);
            // 
            // GrpMood
            // 
            this.GrpMood.Controls.Add(this.RBtnSad);
            this.GrpMood.Controls.Add(this.RBtnHappy);
            this.GrpMood.Location = new System.Drawing.Point(302, 96);
            this.GrpMood.Name = "GrpMood";
            this.GrpMood.Size = new System.Drawing.Size(181, 97);
            this.GrpMood.TabIndex = 10;
            this.GrpMood.TabStop = false;
            this.GrpMood.Text = "Moods";
            // 
            // RBtnSad
            // 
            this.RBtnSad.AutoSize = true;
            this.RBtnSad.Location = new System.Drawing.Point(8, 44);
            this.RBtnSad.Name = "RBtnSad";
            this.RBtnSad.Size = new System.Drawing.Size(44, 19);
            this.RBtnSad.TabIndex = 1;
            this.RBtnSad.TabStop = true;
            this.RBtnSad.Text = "Sad";
            this.RBtnSad.UseVisualStyleBackColor = true;
            this.RBtnSad.CheckedChanged += new System.EventHandler(this.RBtnSad_CheckedChanged);
            // 
            // RBtnHappy
            // 
            this.RBtnHappy.AutoSize = true;
            this.RBtnHappy.Location = new System.Drawing.Point(8, 19);
            this.RBtnHappy.Name = "RBtnHappy";
            this.RBtnHappy.Size = new System.Drawing.Size(60, 19);
            this.RBtnHappy.TabIndex = 0;
            this.RBtnHappy.TabStop = true;
            this.RBtnHappy.Text = "Happy";
            this.RBtnHappy.UseVisualStyleBackColor = true;
            this.RBtnHappy.CheckedChanged += new System.EventHandler(this.RBtnHappy_CheckedChanged);
            // 
            // GrpOther
            // 
            this.GrpOther.Controls.Add(this.radioButton4);
            this.GrpOther.Controls.Add(this.radioButton3);
            this.GrpOther.Location = new System.Drawing.Point(49, 225);
            this.GrpOther.Name = "GrpOther";
            this.GrpOther.Size = new System.Drawing.Size(184, 104);
            this.GrpOther.TabIndex = 11;
            this.GrpOther.TabStop = false;
            this.GrpOther.Text = "Other";
            // 
            // radioButton4
            // 
            this.radioButton4.AutoSize = true;
            this.radioButton4.Location = new System.Drawing.Point(6, 63);
            this.radioButton4.Name = "radioButton4";
            this.radioButton4.Size = new System.Drawing.Size(94, 19);
            this.radioButton4.TabIndex = 1;
            this.radioButton4.TabStop = true;
            this.radioButton4.Text = "radioButton4";
            this.radioButton4.UseVisualStyleBackColor = true;
            // 
            // radioButton3
            // 
            this.radioButton3.AutoSize = true;
            this.radioButton3.Location = new System.Drawing.Point(10, 28);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(94, 19);
            this.radioButton3.TabIndex = 0;
            this.radioButton3.TabStop = true;
            this.radioButton3.Text = "radioButton3";
            this.radioButton3.UseVisualStyleBackColor = true;
            // 
            // PicHappy
            // 
            this.PicHappy.BackColor = System.Drawing.Color.Lime;
            this.PicHappy.Location = new System.Drawing.Point(489, 107);
            this.PicHappy.Name = "PicHappy";
            this.PicHappy.Size = new System.Drawing.Size(61, 52);
            this.PicHappy.TabIndex = 12;
            this.PicHappy.TabStop = false;
            this.PicHappy.Visible = false;
            // 
            // PicSad
            // 
            this.PicSad.BackColor = System.Drawing.Color.Blue;
            this.PicSad.Location = new System.Drawing.Point(567, 107);
            this.PicSad.Name = "PicSad";
            this.PicSad.Size = new System.Drawing.Size(62, 52);
            this.PicSad.TabIndex = 13;
            this.PicSad.TabStop = false;
            this.PicSad.Visible = false;
            // 
            // FrmFirstApp
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.ClientSize = new System.Drawing.Size(681, 370);
            this.Controls.Add(this.PicSad);
            this.Controls.Add(this.PicHappy);
            this.Controls.Add(this.GrpOther);
            this.Controls.Add(this.GrpMood);
            this.Controls.Add(this.BtnExit);
            this.Controls.Add(this.BtnHello);
            this.Controls.Add(this.PicTwo);
            this.Controls.Add(this.PicOne);
            this.Controls.Add(this.TxtName);
            this.Controls.Add(this.LblTitle);
            this.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Name = "FrmFirstApp";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "First App";
            this.Load += new System.EventHandler(this.FrmFirstApp_Load);
            ((System.ComponentModel.ISupportInitialize)(this.PicOne)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.PicTwo)).EndInit();
            this.GrpMood.ResumeLayout(false);
            this.GrpMood.PerformLayout();
            this.GrpOther.ResumeLayout(false);
            this.GrpOther.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.PicHappy)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.PicSad)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private Label LblTitle;
        private TextBox TxtName;
        private PictureBox PicOne;
        private PictureBox PicTwo;
        private Button BtnHello;
        private Button BtnExit;
        private GroupBox GrpMood;
        private RadioButton RBtnSad;
        private RadioButton RBtnHappy;
        private GroupBox GrpOther;
        private RadioButton radioButton4;
        private RadioButton radioButton3;
        private PictureBox PicHappy;
        private PictureBox PicSad;
    }
}