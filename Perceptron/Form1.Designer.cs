
namespace ReconhecimentoDeLetras
{
    partial class Perceptrons
    {
        /// <summary>
        /// Variável de designer necessária.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpar os recursos que estão sendo usados.
        /// </summary>
        /// <param name="disposing">true se for necessário descartar os recursos gerenciados; caso contrário, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código gerado pelo Windows Form Designer

        /// <summary>
        /// Método necessário para suporte ao Designer - não modifique 
        /// o conteúdo deste método com o editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.bt_X = new System.Windows.Forms.Button();
            this.bt_T = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // bt_X
            // 
            this.bt_X.Font = new System.Drawing.Font("Microsoft Sans Serif", 27.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bt_X.Location = new System.Drawing.Point(31, 51);
            this.bt_X.Name = "bt_X";
            this.bt_X.Size = new System.Drawing.Size(80, 74);
            this.bt_X.TabIndex = 5;
            this.bt_X.Text = "X";
            this.bt_X.UseVisualStyleBackColor = true;
            this.bt_X.Click += new System.EventHandler(this.bt_X_Click);
            // 
            // bt_T
            // 
            this.bt_T.Font = new System.Drawing.Font("Microsoft Sans Serif", 27.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.bt_T.Location = new System.Drawing.Point(138, 51);
            this.bt_T.Name = "bt_T";
            this.bt_T.Size = new System.Drawing.Size(78, 74);
            this.bt_T.TabIndex = 6;
            this.bt_T.Text = "T";
            this.bt_T.UseVisualStyleBackColor = true;
            this.bt_T.Click += new System.EventHandler(this.bt_T_Click);
            // 
            // Perceptrons
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.AliceBlue;
            this.ClientSize = new System.Drawing.Size(259, 199);
            this.Controls.Add(this.bt_T);
            this.Controls.Add(this.bt_X);
            this.Name = "Perceptrons";
            this.Text = "Perceptrons";
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Button bt_X;
        private System.Windows.Forms.Button bt_T;
    }
}

