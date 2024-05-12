#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "pbPlots.h"
#include "supportLib.h"
#define EQ pow(10,-6)

double random(double min, double max){
   return min + rand() / (RAND_MAX / (max - min) + 1);
}

int main(){
char op, op2;

double t[35] = {1.0000,-1.0000,-1.0000,-1.0000,1.0000,1.0000,1.0000,1.0000,-1.0000,1.0000 ,-1.0000,-1.0000,1.0000,1.0000,-1.0000,
               -1.0000,1.0000,-1.0000,-1.0000,1.0000,1.0000,-1.0000,-1.0000,1.0000,-1.0000,1.0000,-1.0000,1.0000,-1.0000,1.0000,
                1.0000,1.0000,-1.0000,-1.0000,-1.0000};


double x[4][35] = {{0.4329,0.3024,0.1349,0.3374,1.1434,1.3749,0.7221,0.4403,-0.5231,0.3255,0.5824,0.1340,0.1480,0.7359,0.7115,
                   0.8251,0.1569,0.0033,0.4243,1.0490,1.4276,0.5971,0.8475,1.3967,0.0044,0.2201,0.6300,-0.2479,-0.3088,-0.5180,
                   0.6833,0.4353,-0.1069,0.4662,0.8298},

                   {-1.3719,0.2286,-0.6445,-1.7163,-0.0485,-0.5071,-0.7587,-0.8072,0.3548,-2.0000,1.3915,0.6081,-0.2988,0.1869,
                   -1.1469,-1.2840,0.3712,0.6835,0.8313,0.1326,0.5331,1.4865,2.1479,-0.4171,1.5378,-0.5668,-1.2480,0.8960,-0.0929,
                   1.4974,0.8266,-1.4066,-3.2329,0.6261,-1.4089},

                   {0.7022,0.8630,1.0530,0.3670,0.6637,0.4464,0.7681,0.5154,0.2538,0.7112,-0.2291,0.4450,0.4778,-0.0872,0.3394,
                   0.8452,0.8825,0.5389,0.2634,0.9138,-0.0145,0.2904,0.3179,0.6443,0.6099,0.0515,0.8591,0.0547,0.8659,0.5453,
                   0.0829,0.4207,0.1856,0.7304,0.3119},

                   {-0.8535,2.7909,0.5687,-0.6283,1.2606,1.3009,-0.5592,-0.3129,1.5776,-1.1209,4.1735,3.2230,0.8649,2.3584,0.9573,
                   1.2382,1.7633,2.8249,3.5855,1.9792,3.7286,4.6069,5.8235,1.3927,4.7755,0.7829,0.8093,1.7381,1.5483,2.3993,2.8864,
                   -0.4879,-2.4572,3.4370,1.3235}};

double xt[4][15] = {{0.9694,0.5427,0.6081,-0.1618,0.1870,0.4891,0.3777,1.1498,0.9325,0.5060,0.0497,0.4004,-0.1874,0.5060,1.6375},
                   {0.6909,1.3832,-0.9196,0.4694,-0.2578,-0.5276,2.0149,-0.4067,1.0950,1.3317,-2.0656,3.5369,1.3343,1.3317,-0.7911},
                   {0.4334,0.6390,0.5925,0.2030,0.6124,0.4378,0.7423,0.2469,1.0359,0.9222,0.6124,0.9766,0.5374,0.9222,0.7537},
                   {3.4965,4.0352,0.1016,3.0117,1.7749,0.6439,3.3932,1.5866,3.3591,3.7174,-0.6585,5.3532,3.2189,3.7174,0.5515}};


double ge[1700];
double cicl[1700];
double want[4],
bant = random(0,1),
wnovo[4],
bnovo,
teta = 0,
alfa = 0.0025,
eqatual = 0,
eqant = 0,
y,
yliquido;
int
ciclos = 0,
erros = 0,
e;



do{setbuf(stdin,NULL);
srand(time(NULL));

RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();



want[4],
bant = random(0,1),
wnovo[4],
bnovo,
teta = 0,
alfa = 0.0025,
eqatual = 0,
eqant = 0,
y,
yliquido;

ciclos = 0,
erros = 0,
e;

printf("              Rede Neural Adaline\n\n");

printf("Pesos Iniciais: \n");
for(int i = 0; i<4; i++){
    want[i] = random(0,1);
    printf("W%d: %.2f\n",i,want[i]);
}

printf("B: %.2f\n", bant);

//clrscr();

do{

    eqant = eqatual;
    ciclos++;
     eqatual = 0;
     for(e = 0; e <35; e++){
         yliquido = (want[0]*x[0][e] + want[1]*x[1][e] + want[2]*x[2][e] + want[3]*x[3][e]) + bant;
         y = yliquido;
         eqatual += pow((t[e]-y),2) * 0.5;
         wnovo[0] = want[0] + (alfa*(t[e]-y)*x[0][e]);
         wnovo[1] = want[1] + (alfa*(t[e]-y)*x[1][e]);
         wnovo[2] = want[2] + (alfa*(t[e]-y)*x[2][e]);
         wnovo[3] = want[3] + (alfa*(t[e]-y)*x[3][e]);
         bnovo = bant + (alfa*(t[e]-y));
         want[0] = wnovo[0];
         want[1] = wnovo[1];
         want[2] = wnovo[2];
         want[3] = wnovo[3];
         bant = bnovo;

}

ge[ciclos] = eqant;
cicl[ciclos] = ciclos;

}while((fabs(eqatual - eqant) > EQ));



//printf("%d", ciclos);
//printf("Erros: %d\n", erros);

erros = 0;



printf("\n\nPesos Finais: \n");
for(int i = 0; i<4; i++){
    want[i] = random(0,1);
    printf("W%d: %.2f\n",i,want[i]);
}

printf("B: %.2f", bant);
printf("\nCiclos: %d\n\n", ciclos);

DrawScatterPlot(canvasReference,600,600,cicl,1000,ge,1000);
	size_t length;
	double *pngdata = ConvertToPNG(&length, canvasReference->image);
	WriteToFile(pngdata, length, "erroquadratico.png");
	DeleteImage(canvasReference->image);

printf("Treinamento terminado, treinar novamente (s/n)\nou testar rede(t)? (s/n) ");
op2 = getchar();
system("cls");
}while(op2 == 's');
setbuf(stdin,NULL);
srand(time(NULL));
if(op2 == 'n'){ printf("Saida da rede neural para os 35 valores:\n\n");
    for(e = 0; e<35; e++){

        yliquido = (wnovo[0]*x[0][e] + wnovo[1]*x[1][e] + wnovo[2]*x[2][e] + wnovo[3]*x[3][e]) + bnovo;

        if(yliquido >= teta){

            y = 1;
            printf(" %.2f\n",y);
        } else {y = -1;printf("%.2f\n",y);}

}
}
else if(op2 == 't'){
        printf("Saida da rede neural para os valores predefinidos:\n\n");
for(e = 0; e<15; e++){

        yliquido = (wnovo[0]*xt[0][e] + wnovo[1]*xt[1][e] + wnovo[2]*xt[2][e] + wnovo[3]*xt[3][e]) + bnovo;

        if(yliquido >= teta){

            y = 1;
printf(" %.2f\n",y);
        } else {y = -1; printf("%.2f\n",y);}
        //if(y != t[e]) {erros++;}

}}
system("pause");
}
