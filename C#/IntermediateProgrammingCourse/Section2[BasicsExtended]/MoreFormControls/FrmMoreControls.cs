namespace MoreFormControls
{
    public partial class FrmMoreControls : Form
    {
        public FrmMoreControls()
        {
            InitializeComponent();
        }

        private void HsbNumber_Scroll(object sender, ScrollEventArgs e)
        {
            TxtNumber.Text = HsbNumber.Value.ToString();
        }

        private void redToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Red;
        }

        private void greenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Green;
        }

        private void blueToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.BackColor = Color.Blue;
        }

        private void BtnToForm2_Click(object sender, EventArgs e)
        {
            FrmTwo x = new FrmTwo();
            x.Show();
        }
    }
}
