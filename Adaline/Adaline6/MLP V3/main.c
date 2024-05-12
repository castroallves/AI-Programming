#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define nep 2.71828

double random(double min, double max){
   return min + rand() / (RAND_MAX / (max - min) + 1);}

int main()
{
    // treinamento da rede neural multicamada MLP(multilayer perceptron)
// usando o algoritmo da retropropagação do erro(error backpropagation)
// para  o problema do OU-Exclusivo.
// função de ativação: sigmóide bipolar
// f(x)= (2/(1+exp(-x)))-1
// derivada de f(x)= 0.5(1+f(x))(1-f(x))
// data: 07/09/2020

 double x [11] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};

    double t [11] = {-0.9602,-0.5770,-0.0729,0.3771,0.6405,0.6600,0.4609,
                     0.1336, -0.2013, -0.4344, -0.5000};

    double tx[11];

int
// neurônios de entrada
neuroniosentrada = 1, // duas variáveis: x1 e x2

//neurônios na camada escondida
//neuroniosescondidos=input('Neurônios na camada escondida =');
neuroniosescondidos = 10,
//  neurônios na camada de saída
neuroniossaida = 1,
f,g,h,i,j,k, padroes;

double
//inicialização da taxa de aprendizagem alfa
//alfa=input('Taxa de aprendizagem(0< alfa <=1) =');
alfa = 0.03,
//errototaladmissivel=input('Entre com o erro total admissivel: ');
errototaladmissivel = 0.001,
//numciclo=input('Entre com o número de ciclos máximo= ');
numciclo=4000;
//------inicialização aleatória dos pesos, entre -0.5 e +0.5 ---------
// da camada escondida

double v[neuroniosescondidos];
double bv[neuroniosescondidos];
//double deltinhainv[neuroniosescondidos];
double deltinhav[neuroniosescondidos];
double w[neuroniosescondidos];
double deltinhaw = 0;
double deltaw[neuroniosescondidos];
double bw;
double deltabw;
double zin[neuroniosescondidos];
double z[neuroniosescondidos];
double yin = 0;
double y = 0;
double deltav[neuroniosescondidos];
double deltabv[neuroniosescondidos];


for(j = 0; j < neuroniosescondidos; j++){
        v [j] = random(-0.5,0.5);
        bv[j]= random(-0.5,0.5);}


for(j = 0; j < neuroniosescondidos; j++){
//deltinhainv[j] = 0;
deltinhav[j]= 0;
//zin[j] = 0;
//z[j] = 0;
}

// da camada de saida
for(i = 0; i < neuroniosescondidos; i++ ){
w[neuroniosescondidos] = random(-0.5,0.5);}

bw = random(-0.5,0.5); //bias



//gráfico do erro quadratico total
//xlabel('Ciclos');
//ylabel('Erro quadratico total');

//-------- treinamento da rede neural-------

int ciclo=0;
int errototal=10; // acumula os erros para todos os padrões de treinamento
//zin=zeros(1,neuroniosescondidos); // soma ponderada das entradas dos neurônios escondidos
//z=zeros(1,neuroniosescondidos);// saída dos neurônios escondidos

//treinamento irá parar pelo número de ciclo ou pelo errototal alcançado.
while ((ciclo < numciclo) && (errototal > errototaladmissivel)){
   ciclo++;
   errototal=0;

   // -----------fase feedforward --------------
   // inserção de cada padrao de treinamento na entrada da rede neural
   // e cálculo das saídas z dos neurônios escondidos
   for (padroes = 0; padroes <11;  padroes++){
		for(i = 0; i<neuroniosescondidos; i++){
         zin[i]= x[padroes] * v[i]+bv[i];
         z[i] = (2/(1+pow(nep,-zin[j])))-1; // sigmóide bipolar
		}

       //%Cálculo da  saída  da rede
       for(j = 0; j< neuroniosescondidos; j++){
     	yin=z[j] * w[j]+ bw;
        y=(2/(1+pow(nep,-yin)))-1;}

   // -------------fase da Retropropagação do erro----------
   // da saida para a camada escondida
   //cálculos do deltinhaw do neurônio de saída
     deltinhaw = (t[padroes] - y)*0.5*(1+y)*(1-y);
  // cálculo dos deltaw para atualização dos pesos do neurônio de
  // saida
     for (k = 0; k<neuroniosescondidos; k++){
	   deltaw[k]= alfa*deltinhaw*z[k];
     }

  //cálculo das atualizações dos bias dos neurônios de saida
     deltabw = alfa*deltinhaw;

 // cáculo dos deltinhav da camada escondida para as atualizações dos pesos
 // dos neurônios escondidos
    for (j=0; j<neuroniosescondidos; j++){
      deltinhav[j]=deltinhaw*w[j]*0.5*(1+z[j])*(1-z[j]);
    }

//cálculo dos deltav para atualização dos pesos dos neurônios escondidos
      for(j=0; j<neuroniosescondidos; j++){
      deltav[j]= alfa*deltinhav[j]*x[padroes];   /// REVER
      }

// cálculo dos deltabv, bias dos neurônios escondidos
    for(i= 0; i<neuroniosescondidos; i++){
      deltabv[i]= alfa*deltinhav[i];
    }

//-------atualização dos pesos----------
// dos neurônios da camada de saída
for(i = 0; i<neuroniosescondidos; i++){
    w[i]+= deltaw[i];
    }
    bw += deltabw;
// dos neurônios da camada escondida

     for(j=0; j< neuroniosescondidos; j++){
       v[j] += deltav[j];
   }

   for (i=0; i< neuroniosescondidos; i++){
     bv[i]+=deltabv[i];
   }

   // cálculo do erro total
   // é a soma de todos os erros  produzidos pelos neurônios de saida
   // para todos os padrões de treinamento
   errototal+=0.5*(pow(t[padroes]-y,2));
   }// for padrões de entrada
    //plot(ciclo,errototal,'r.');
}
//plot(erroquadraticototal,'r.');
//disp('Fim do treinamento');
//disp('Erro quadrático final: ');
//disp(errototal);
//disp('Ciclos: ');
//disp(ciclo);
//disp('');
//disp('');
//disp('Teste da rede treinada');

//--------teste da rede com os padrões de treinamento ---------
    for(padroes= 0; padroes< 11; padroes++){
		for( j=0; j<neuroniosescondidos;j++){
         zin[j] = (x[padroes]* v[j]) + bv[j];
         z[j] = (2/(1+pow(nep,-zin[j])))-1;
		}
        //Cálculo da saída  da rede
        for(k = 0; k< neuroniosescondidos;k++){
     	 yin = (z[k]* w[k])+ bw;}
         y = (2/(1+pow(nep,-yin)))-1;
         tx[padroes] = y;
         }

         for(i = 0; i<11; i++){
         printf("Target: %.2f   Rede treinada: %lf\n",t[i],tx[i]);}

}
