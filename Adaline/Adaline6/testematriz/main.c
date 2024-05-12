#include <stdio.h>
#include <stdlib.h>

int main()
{

    int matriz [5][1] = {1,2,3,4,5},
    i,j;


    for(j = 0; j<5; j++){



        printf("%d, j: %d\n", matriz[j][0], j);

    }
    //Sprintf("Hello world!\n");
    return 0;
}
