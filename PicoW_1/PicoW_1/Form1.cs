using System.IO.Ports;

namespace PicoW_1
{
    public partial class Form1 : Form
    {
        SerialPort port;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            port = new SerialPort();
            port.PortName = comboBox1.Text;
            port.BaudRate = 115200;
            port.DtrEnable = true;
            try
            {
                port.Open();
                MessageBox.Show("Sí se conectó :)");
            }
            catch (Exception ex)
            {
                MessageBox.Show("No está conectado" + ex);
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                port.WriteLine(textBox1.ToString());
                MessageBox.Show("Se envio correctamente");
            }
            catch (Exception ex)
            {
                MessageBox.Show("No se envió" + ex);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Text = "";
        }
    }
}