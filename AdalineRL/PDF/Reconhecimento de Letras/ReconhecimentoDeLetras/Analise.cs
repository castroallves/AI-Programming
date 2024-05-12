using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ReconhecimentoDeLetras
{
    class Analise
    {

        // Padrão para a letra T
        public int[] letra_t = new int[25] { 1, 1, 1, 1, 1,
                                             0, 0, 1, 0, 0,
                                             0, 0, 1, 0, 0,
                                             0, 0, 1, 0, 0,
                                             0, 0, 1, 0, 0 };

        // Padrão para a letra X								
        public int[,] letra_n = new int[2, 25] {{ 1, 0, 0, 0, 1,
                                                  0, 1, 0, 1, 0,
                                                  0, 0, 1, 0, 0,
                                                  0, 1, 0, 1, 0,
                                                  1, 0, 0, 0, 1 },

                                                { 1, 1, 1, 1, 1,
                                                  0, 0, 1, 0, 0,
                                                  0, 0, 1, 0, 0,
                                                  0, 0, 1, 0, 0,
                                                  0, 0, 1, 0, 0 }};
    public string info_analises = null;
        public float[] wantigo = new float[25];
        public float[] wnovo = new float[25];
        public int t;
        public float y;
                
        int[,] x = new int[4, 2];
        public float bnovo = 0, bantigo = 0, theta = 0,// limiar
                                          trocou = 1,// sinaliza mudança dos pesos
                                          ciclos = 0; // contador para número de ciclos de treinamento
                                          
        public float alpha = 1, yliquido = 0;// taxa de aprendizagem

        void inicializa() {                           
            for (int i = 0; i < 25; i++) {
                wantigo[i] = 0;
                wnovo[i] = 0;
                info_analises += "W de " + i.ToString() + "= " + wnovo[i].ToString() +
                                 "  B =  " + bnovo.ToString() + "\n";
                //if(i ==  10 ) info_analises += "\t"                ;
            }
        }

        public void treina(int numero)
        {
            if (numero == 0) { t = 1; } else { t = -1; }
            inicializa();
            while(trocou == 1)
            {
                MessageBox.Show("Ciclo " + ciclos.ToString() + "\n\n" + info_analises);
                trocou = 0;
                ciclos = ciclos + 1;
                for(int i = 0; i < 25; i++)
                {
                    yliquido += wantigo[i] * letra_n[numero,i] + bantigo;
                    
                }

                if (yliquido >= theta)
                { y = 1; }
                else { y = -1; }

                // atualiza pesos se rede neural errou
                if (y != t)
                {
                    info_analises = null;
                    trocou = 1;  //  sinaliza que a rede neural errou
                    for (int n = 0; n < 25; n++)
                    {
                        wnovo[n] = wantigo[n] + alpha * letra_n[numero,n] * t;
                        info_analises += "W de " + n.ToString() + "= " + wnovo[n].ToString() +
                                 " B =  " + bnovo.ToString() + "\n";
                    }
                    bnovo = bantigo + alpha * t;
                    // salva os novos pesos
                    wantigo = wnovo;
                    bantigo = bnovo;
                }


                //MessageBox.Show(info_analises);
                
            }

            MessageBox.Show("A saída é: " + y.ToString());
        }
}

}
