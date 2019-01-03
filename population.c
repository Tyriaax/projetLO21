#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "constante.h"
#include "population.h"
#include "individu.h"

Population initPopul()
{
    int taillePopul=rand()%181+20;

    elementPopul *elemPopul = malloc(sizeof(elementPopul));
    elemPopul->indiv=initIndivIterative();
    elemPopul->suivant=NULL;

    int i;
    for(i=0;i<taillePopul-1;i++)
    {
        elementPopul *nouvElPopul = malloc(sizeof(elementPopul));

        nouvElPopul->indiv=initIndivIterative();
        nouvElPopul->suivant=elemPopul;

        elemPopul = nouvElPopul;
    }

    return elemPopul;
}

Population selection(Population popul, int tselect)
{
    if(popul==NULL)
    {
        return NULL;
    }
    elementPopul elMemoire;
    elMemoire->suivant=NULL;
    Population memoire;

    elementPopul elemPopul = *popul;

    while(elemPopul!=NULL&&qualite(elemPopul)>=tselect)
    {
        elMemoire->indiv=elemPopul->indiv;
        elementPopul elMemoireSuivant;
    }


    return popul;
}
