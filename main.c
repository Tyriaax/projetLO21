#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"
#include "Population.h"
#include "quicksort.h"
#include "constante.h"

int main()
{
    srand(time(0));

    printf("\t\t\t\t\tALGORITHME GENETIQUE ! \n");

    Population *maPop = creationPop();

    int nGen = nGenMin+rand()%(nGenMax-nGenMin), i;

    for(i=0;i<nGen;i++)
    {
        maPop=croisagePopulation(maPop);
        quickSort(maPop);
        t_Select(maPop);
    }

    afficherListe(maPop->premier->Personne);

    return 0;
}
