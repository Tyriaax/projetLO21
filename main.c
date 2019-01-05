#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"
#include "Population.h"
int main()
{
    srand(time(0));

    printf("\t\t\t\t\tALGORITHME GENETIQUE ! \n");

    Population *maPop2 = creationPop();
    afficherPop(maPop2);
    quickSort(maPop2);
    afficherPop(maPop2);
    afficherPop(maPop2);
    return 0;
}
