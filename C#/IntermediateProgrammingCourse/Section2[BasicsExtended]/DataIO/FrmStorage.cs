namespace DataIO
{
    public partial class FrmStorage : Form
    {
        public FrmStorage()
        {
            InitializeComponent();
        }

        private void BtnGo_Click(object sender, EventArgs e)
        {
            // variable declaration
            // local variables
            int age;
            string yourName;
            double salary;

            // assignment statements
            age = 24;
            yourName = "Jag";
            salary = 231.25;

            // display the results
            MessageBox.Show($"Your age is {age}");
            MessageBox.Show($"Your name is {yourName}");
            MessageBox.Show($"Your salary is {salary}");
        }
    }
}