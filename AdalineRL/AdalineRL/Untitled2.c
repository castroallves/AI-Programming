#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double randf( double min, double max )
{
    srand(time(NULL));
    return min + (rand() / ( RAND_MAX / ( max - min) ) ) ;


}
