namespace MoreFormControls
{
    partial class FrmMoreControls
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
            this.TxtNumber = new System.Windows.Forms.TextBox();
            this.HsbNumber = new System.Windows.Forms.HScrollBar();
            this.MnuColours = new System.Windows.Forms.MenuStrip();
            this.coloursToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.redToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.greenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.blueToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.BtnToForm2 = new System.Windows.Forms.Button();
            this.MnuColours.SuspendLayout();
            this.SuspendLayout();
            // 
            // TxtNumber
            // 
            this.TxtNumber.Location = new System.Drawing.Point(85, 50);
            this.TxtNumber.Name = "TxtNumber";
            this.TxtNumber.Size = new System.Drawing.Size(239, 23);
            this.TxtNumber.TabIndex = 0;
            // 
            // HsbNumber
            // 
            this.HsbNumber.LargeChange = 1;
            this.HsbNumber.Location = new System.Drawing.Point(336, 50);
            this.HsbNumber.Maximum = 50;
            this.HsbNumber.Name = "HsbNumber";
            this.HsbNumber.Size = new System.Drawing.Size(239, 23);
            this.HsbNumber.TabIndex = 1;
            this.HsbNumber.Scroll += new System.Windows.Forms.ScrollEventHandler(this.HsbNumber_Scroll);
            // 
            // MnuColours
            // 
            this.MnuColours.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.coloursToolStripMenuItem});
            this.MnuColours.Location = new System.Drawing.Point(0, 0);
            this.MnuColours.Name = "MnuColours";
            this.MnuColours.Size = new System.Drawing.Size(800, 24);
            this.MnuColours.TabIndex = 2;
            this.MnuColours.Text = "menuStrip1";
            // 
            // coloursToolStripMenuItem
            // 
            this.coloursToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.redToolStripMenuItem,
            this.greenToolStripMenuItem,
            this.blueToolStripMenuItem});
            this.coloursToolStripMenuItem.Name = "coloursToolStripMenuItem";
            this.coloursToolStripMenuItem.Size = new System.Drawing.Size(60, 20);
            this.coloursToolStripMenuItem.Text = "Colours";
            // 
            // redToolStripMenuItem
            // 
            this.redToolStripMenuItem.Name = "redToolStripMenuItem";
            this.redToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.redToolStripMenuItem.Text = "Red";
            this.redToolStripMenuItem.Click += new System.EventHandler(this.redToolStripMenuItem_Click);
            // 
            // greenToolStripMenuItem
            // 
            this.greenToolStripMenuItem.Name = "greenToolStripMenuItem";
            this.greenToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.greenToolStripMenuItem.Text = "Green";
            this.greenToolStripMenuItem.Click += new System.EventHandler(this.greenToolStripMenuItem_Click);
            // 
            // blueToolStripMenuItem
            // 
            this.blueToolStripMenuItem.Name = "blueToolStripMenuItem";
            this.blueToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.blueToolStripMenuItem.Text = "Blue";
            this.blueToolStripMenuItem.Click += new System.EventHandler(this.blueToolStripMenuItem_Click);
            // 
            // BtnToForm2
            // 
            this.BtnToForm2.Location = new System.Drawing.Point(278, 175);
            this.BtnToForm2.Name = "BtnToForm2";
            this.BtnToForm2.Size = new System.Drawing.Size(187, 41);
            this.BtnToForm2.TabIndex = 3;
            this.BtnToForm2.Text = "Go To Second Form";
            this.BtnToForm2.UseVisualStyleBackColor = true;
            this.BtnToForm2.Click += new System.EventHandler(this.BtnToForm2_Click);
            // 
            // FrmMoreControls
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.BtnToForm2);
            this.Controls.Add(this.HsbNumber);
            this.Controls.Add(this.TxtNumber);
            this.Controls.Add(this.MnuColours);
            this.MainMenuStrip = this.MnuColours;
            this.Name = "FrmMoreControls";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "More Controls";
            this.MnuColours.ResumeLayout(false);
            this.MnuColours.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private TextBox TxtNumber;
        private HScrollBar HsbNumber;
        private MenuStrip MnuColours;
        private ToolStripMenuItem coloursToolStripMenuItem;
        private ToolStripMenuItem redToolStripMenuItem;
        private ToolStripMenuItem greenToolStripMenuItem;
        private ToolStripMenuItem blueToolStripMenuItem;
        private Button BtnToForm2;
    }
}