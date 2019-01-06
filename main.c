#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"
#include "Population.h"
#include "quicksort.h"
#include "constante.h"
#include "croisement.h"

int main()
{
    srand(time(0));

    printf("-------------------\nPROJET LO21\n\n");

    Population *popul = creationPop();

    int nGen = nGenMin+rand()%(nGenMax-nGenMin), i;

    for(i=0;i<nGen;i++)
    {
        popul=croisagePopulation(popul);
        quickSort(popul);
        selection(popul);
    }

    affichage(popul->premier->Personne);
    printf("\nvaleur : %d\nqualite : %f\n",popul->premier->valeur,popul->premier->qualite);

    return 0;
}
