#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



int main(){
char op, op2;
    do{
double t[11] = {0.00, 0.50, 1.00, 1.50, 2.00, 2.50, 3.00, 3.50, 4.00, 4.50, 5.00};
double x[11] = {2.26, 3.80, 4.43, 5.91, 6.18, 7.26, 8.15, 9.14 ,10.87, 11.53, 12.55};

srand(time(NULL));

double random(double min, double max){
   return min + rand() / (RAND_MAX / (max - min) + 1);
}
double want = random(-0.5,0.5) ,
bant = random(-0.5,0.5) ,
wnovo,
bnovo,
teta = 0,
alfa = 0.01,
equadratico,
y,
yliquido;

int numciclos,
ciclos = 0,
e;


printf("Tabela de valores a serem trabalhados:\n\n");
printf(" |  x   |  y   |\n");
printf(" ---------------\n");


for(int i = 0; i<11; i++){
    printf(" | %.2f | %.2f |\n", x[i], t[i]);}

    printf("\nEscolha a quantidade de ciclos: ");
    scanf("%d", &numciclos);
    printf("\n");
    printf("Mostrar dados em tempo real? (s/n): ");

    setbuf(stdin,NULL);
    op = getchar();
         printf("\n W Inicial: %lf   B Inicial: %lf\n", want, bant);

while (ciclos < numciclos){
    ciclos++;
    equadratico = 0;
     for(e = 0; e <10; e++){
         yliquido = (want*x[e]) + bant;
         y = yliquido;
         equadratico += pow(t[e]-y,2);
         wnovo = want + (alfa*(t[e]-y)*x[e]);
         bnovo = bant + (alfa*(t[e]-y));
         want = wnovo;
         bant = bnovo;
}
if(op == 's'){printf("\n%d   %.4lf   %.4lf   %.4lf   %.4lf\n", ciclos, want, bant,equadratico,sqrt(equadratico));}
}
if(op == 'n'){printf("\nCiclos: %d\nCoef. de reg. (b): %lf\nIntercepto (a): %lf\nCoeficiente de Correlacão: %lf\nErro Quadratico: %lf\n", ciclos, want, bant,sqrt(equadratico),equadratico);}
else{printf("\nCiclo | Coef. de Reg. | Intercepcao | Correl | E. quad |\n");}setbuf(stdin,NULL);
printf("\nPrograma terminado, executar novamente? (s/n)");
op2 = getchar();
system("cls");
}while(op2 == 's');
}
