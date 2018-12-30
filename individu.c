#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "structure.h"
#include "constante.h"
#include "individu.h"

Individu initIndivIterative(Individu indiv)
{
    int i;
    for(i=0;i<longIndiv;i++)
    {
        indiv.bit[i]=rand()%2;
    }

    return indiv;
}

Individu initIndivRecursive(Individu indiv,int nombreRestant)
{
    if(nombreRestant!=0)
    {
        indiv.bit[longIndiv-nombreRestant]=rand()%2;
        indiv=initIndivRecursive(indiv,nombreRestant-1);
    }
    return indiv;
}

int valeurIndividu(Individu indiv)
{
    int i,valeur=0;
    for(i=0;i<longIndiv;i++)
    {
        valeur+=indiv.bit[longIndiv-1-i]*pow(2,i);
    }
    return valeur;
}
