namespace FirstApp
{
    public partial class FrmFirstApp : Form
    {
        public FrmFirstApp()
        {
            InitializeComponent();
        }

        private void FrmFirstApp_Load(object sender, EventArgs e)
        {

        }

        private void BtnHello_Click(object sender, EventArgs e)
        {
            MessageBox.Show($"Hello {TxtName.Text}!");
        }

        private void BtnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void RBtnHappy_CheckedChanged(object sender, EventArgs e)
        {
            PicHappy.Visible = true;
            PicSad.Visible = false;
        }

        private void RBtnSad_CheckedChanged(object sender, EventArgs e)
        {
            PicSad.Visible = true;
            PicHappy.Visible = false;
        }
    }
}