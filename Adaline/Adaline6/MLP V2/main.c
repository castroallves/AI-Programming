#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "pbPlots.h"
#include "supportLib.h"
#define e 2.718281


double random(double min, double max){
   return min + rand() / (RAND_MAX / (max - min) + 1);}

int main()
{
    double x [11] = {0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
    double t [11] = {-0.9602,-0.5770,-0.0729,0.3771,0.6405,0.6600,0.4609,
                     0.1336, -0.2013, -0.4344, 0.5000};

srand(time(NULL));

// Neuronios
int
n_in = 1,
n_out = 1,
n_hid = 4,
ciclo = 0,
numciclos = 4000,
i,j,k;

double alfa = 0.03,
y_in = 0,
y = 0,

// Erros
elimit = 0.001,
etotal = 10,

// Pesos

//camadas intermediárias
w_hid [n_in][n_hid],
b_hid [n_hid],

//camadas de saida
w_out [n_hid][n_out],
b_out = random(-0.5,0.5),
z[n_hid],
z_in[n_hid],

//deltinhas

deltabw = 0,
deltinhainv[n_hid],
deltinhav[n_hid],
deltinhaw = 0,
deltaw[n_hid],
deltav[n_hid],
deltabv[n_hid];


// for(i = 0; i < n_hid; i++){
//
// for(j= 0; j)
//    b_hid [i] =  random(-0.5,0.5);
//    w_hid[i][j] = random(-0.5,0.5);
//    w_out[i][j] = random(-0.5,0.5);
//    deltinhainv[i] = 0;
//    deltinhav[i] = 0;
//    deltaw[i] = 0;
//    deltav[i] = 0;
//    deltabv[i]= 0;
//    z_in [i] = random(-0.5,0.5);
//    z[i] = random(-0.5,0.5);
//
//}


 while( (ciclo < numciclos) && (etotal > elimit) ){
    ciclo++;
    etotal = 0;

    for(i = 0; i<11; i++){

        for(j = 0; j < n_hid; j++){

            z_in[j] = x[i] * w_hid[j] + b_hid[j];
            z[j] = (2/(1+pow(e,-z_in[j])))-1; // sigmóide bipola

}
        //for(k = 0; k < n_out; k++){
         y_in = (z[j]* w_out[j]) + b_out;
         //}

        y = (2/(1+pow(e,(-y_in))))-1;

        // -------------fase da Retropropagação do erro----------
   // da saida para a camada escondida
   //cálculos do deltinhaw do neurônio de saída
     deltinhaw = (t[i] - y)*0.5*(1+y)*(1-y);
  // cálculo dos deltaw para atualização dos pesos do neurônio de
  // saida
     for(k = 0; k < n_hid; k++){
	   deltaw[k] = alfa*deltinhaw*z[k];
     }

     deltabw = alfa*deltinhaw;

     // cáculo dos deltinhav da camada escondida para as atualizações dos pesos
 // dos neurônios escondidos
    for (k = 0; k < n_hid; k++){
      deltinhav[k] = deltinhaw * w_out[k]*0.5*(1+z[k])*(1-z[k]);
    }

//cálculo dos deltav para atualização dos pesos dos neurônios escondidos

      for(j = 0 ; j < n_hid; j++){
        deltav[j] = alfa * deltinhav[j] * x[i];
    }

// cálculo dos deltabv, bias dos neurônios escondidos
    for(k=0; k < n_hid; k++){
       deltabv[k]= alfa*deltinhav[i];
    }

    //-------atualização dos pesos----------
// dos neurônios da camada de saída

for(j = 0; j < n_hid; j++){

    w_out[j] += deltaw[j];
    b_out += deltabw;
}

// dos neurônios da camada escondida

     for(k = 0; k< n_hid; k++){
       w_hid[k] += deltav[k];
     }

   for(j = 0; j<n_hid; j++){
     b_hid[j] += deltabv[j];
   }
    }

    // cálculo do erro total
   // é a soma de todos os erros  produzidos pelos neurônios de saida
   // para todos os padrões de treinamento
   etotal += 0.5*(pow(t[i]-y,2));
   // for padrões de entrada


    }




 //--------teste da rede com os padrões de treinamento ---------
    for(i = 0; i < 11; i++){
		for(j = 0; j < n_hid; j++){
         z_in[j] = x[i]* w_hid[j]+ b_hid[j];
         z[j] = (2/(1+pow(e,-z_in[j])))-1;}

        //Cálculo da saída  da rede

     	 y_in += z[j] * w_out[j] + b_out;
         y =(2/(1+pow(e,(-y_in))))-1;
         printf("Target: %.2f   Rede treinada: %f\n",t[i],y);}

 }

// RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
// DrawScatterPlot(canvasReference,1000,1000,x,10,t,10);
// DrawScatterPlot(canvasReference,1000,1000,t,10,x,10);
////DrawScatterPlot(canvasReference, 600, 400, x, t);
//
////DrawPixel(canvasReference,1.2000,1.9000,GetBlack(1.2));
//	size_t length;
//	double *pngdata = ConvertToPNG(&length, canvasReference->image);
//	WriteToFile(pngdata, length, "erroquadratico.png");
//	DeleteImage(canvasReference->image);




