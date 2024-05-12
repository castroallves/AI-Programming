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
// usando o algoritmo da retropropaga��o do erro(error backpropagation)
// para  o problema do OU-Exclusivo.
// fun��o de ativa��o: sigm�ide bipolar
// f(x)= (2/(1+exp(-x)))-1
// derivada de f(x)= 0.5(1+f(x))(1-f(x))
// data: 07/09/2020

 double x [11] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};

    double t [11] = {-0.9602,-0.5770,-0.0729,0.3771,0.6405,0.6600,0.4609,
                     0.1336, -0.2013, -0.4344, -0.5000};

    double tx[11];

int
// neur�nios de entrada
neuroniosentrada = 1, // duas vari�veis: x1 e x2

//neur�nios na camada escondida
//neuroniosescondidos=input('Neur�nios na camada escondida =');
neuroniosescondidos = 10,
//  neur�nios na camada de sa�da
neuroniossaida = 1,
f,g,h,i,j,k, padroes;

double
//inicializa��o da taxa de aprendizagem alfa
//alfa=input('Taxa de aprendizagem(0< alfa <=1) =');
alfa = 0.03,
//errototaladmissivel=input('Entre com o erro total admissivel: ');
errototaladmissivel = 0.001,
//numciclo=input('Entre com o n�mero de ciclos m�ximo= ');
numciclo=4000;
//------inicializa��o aleat�ria dos pesos, entre -0.5 e +0.5 ---------
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



//gr�fico do erro quadratico total
//xlabel('Ciclos');
//ylabel('Erro quadratico total');

//-------- treinamento da rede neural-------

int ciclo=0;
int errototal=10; // acumula os erros para todos os padr�es de treinamento
//zin=zeros(1,neuroniosescondidos); // soma ponderada das entradas dos neur�nios escondidos
//z=zeros(1,neuroniosescondidos);// sa�da dos neur�nios escondidos

//treinamento ir� parar pelo n�mero de ciclo ou pelo errototal alcan�ado.
while ((ciclo < numciclo) && (errototal > errototaladmissivel)){
   ciclo++;
   errototal=0;

   // -----------fase feedforward --------------
   // inser��o de cada padrao de treinamento na entrada da rede neural
   // e c�lculo das sa�das z dos neur�nios escondidos
   for (padroes = 0; padroes <11;  padroes++){
		for(i = 0; i<neuroniosescondidos; i++){
         zin[i]= x[padroes] * v[i]+bv[i];
         z[i] = (2/(1+pow(nep,-zin[j])))-1; // sigm�ide bipolar
		}

       //%C�lculo da  sa�da  da rede
       for(j = 0; j< neuroniosescondidos; j++){
     	yin=z[j] * w[j]+ bw;
        y=(2/(1+pow(nep,-yin)))-1;}

   // -------------fase da Retropropaga��o do erro----------
   // da saida para a camada escondida
   //c�lculos do deltinhaw do neur�nio de sa�da
     deltinhaw = (t[padroes] - y)*0.5*(1+y)*(1-y);
  // c�lculo dos deltaw para atualiza��o dos pesos do neur�nio de
  // saida
     for (k = 0; k<neuroniosescondidos; k++){
	   deltaw[k]= alfa*deltinhaw*z[k];
     }

  //c�lculo das atualiza��es dos bias dos neur�nios de saida
     deltabw = alfa*deltinhaw;

 // c�culo dos deltinhav da camada escondida para as atualiza��es dos pesos
 // dos neur�nios escondidos
    for (j=0; j<neuroniosescondidos; j++){
      deltinhav[j]=deltinhaw*w[j]*0.5*(1+z[j])*(1-z[j]);
    }

//c�lculo dos deltav para atualiza��o dos pesos dos neur�nios escondidos
      for(j=0; j<neuroniosescondidos; j++){
      deltav[j]= alfa*deltinhav[j]*x[padroes];   /// REVER
      }

// c�lculo dos deltabv, bias dos neur�nios escondidos
    for(i= 0; i<neuroniosescondidos; i++){
      deltabv[i]= alfa*deltinhav[i];
    }

//-------atualiza��o dos pesos----------
// dos neur�nios da camada de sa�da
for(i = 0; i<neuroniosescondidos; i++){
    w[i]+= deltaw[i];
    }
    bw += deltabw;
// dos neur�nios da camada escondida

     for(j=0; j< neuroniosescondidos; j++){
       v[j] += deltav[j];
   }

   for (i=0; i< neuroniosescondidos; i++){
     bv[i]+=deltabv[i];
   }

   // c�lculo do erro total
   // � a soma de todos os erros  produzidos pelos neur�nios de saida
   // para todos os padr�es de treinamento
   errototal+=0.5*(pow(t[padroes]-y,2));
   }// for padr�es de entrada
    //plot(ciclo,errototal,'r.');
}
//plot(erroquadraticototal,'r.');
//disp('Fim do treinamento');
//disp('Erro quadr�tico final: ');
//disp(errototal);
//disp('Ciclos: ');
//disp(ciclo);
//disp('');
//disp('');
//disp('Teste da rede treinada');

//--------teste da rede com os padr�es de treinamento ---------
    for(padroes= 0; padroes< 11; padroes++){
		for( j=0; j<neuroniosescondidos;j++){
         zin[j] = (x[padroes]* v[j]) + bv[j];
         z[j] = (2/(1+pow(nep,-zin[j])))-1;
		}
        //C�lculo da sa�da  da rede
        for(k = 0; k< neuroniosescondidos;k++){
     	 yin = (z[k]* w[k])+ bw;}
         y = (2/(1+pow(nep,-yin)))-1;
         tx[padroes] = y;
         }

         for(i = 0; i<11; i++){
         printf("Target: %.2f   Rede treinada: %lf\n",t[i],tx[i]);}

}
