using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ReconhecimentoDeLetras
{
    public partial class Perceptrons : Form
    {
        public Perceptrons()
        {
            InitializeComponent();
        }

        int clicks = 0;

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

    

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {


        }


        private void bt_X_Click(object sender, EventArgs e)
        {

            Analise b1 = new Analise();

            b1.treina(0);

        }

        private void bt_T_Click(object sender, EventArgs e)
        {


            Analise b1 = new Analise();

            b1.treina(1);
        }
    }
}
