#include <stdio.h>
#include <stdlib.h>
#include "population.h"
#include <time.h>
#include "constante.h"

Population* creationPop(void) //initialise une population
{
    Population *individuPop = malloc(sizeof(*individuPop));
    IndivPop *elementPop = malloc(sizeof(IndivPop));
    IndivPop *elementPop1 = malloc(sizeof(IndivPop));

    int taillePopulation = rand()%(taillePopulationMax - taillePopulationMin) + taillePopulationMin; //taille de la population aléatoire entre les bornes

    if(individuPop == NULL || elementPop == NULL || elementPop1 == NULL)
    {
        exit(EXIT_FAILURE);
    }

    elementPop->Personne = creation_indiv_iterative();
    elementPop->valeur = valeur(elementPop->Personne);
    elementPop->qualite = qualite(elementPop ->valeur);
    elementPop -> suivant = NULL;
    individuPop -> premier = elementPop;

    int i;

    for(i = 1; i < taillePopulation; i++) //boucle pour initialise chaque individu de la population
    {
        elementPop1->Personne = creation_indiv_iterative();

        elementPop1 ->valeur = valeur(elementPop1->Personne);
        elementPop1->qualite = qualite(elementPop1 ->valeur);

        insertTetePop(individuPop, elementPop1->Personne, elementPop1 ->valeur, elementPop1->qualite);
    }

    return individuPop;
}

void insertTetePop(Population *popu, Individu *adresseIndiv, int valeur, double qualite)
{
    IndivPop *nouveau = malloc(sizeof(*nouveau));
    if(popu == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau-> Personne = adresseIndiv;
    nouveau->valeur = valeur;
    nouveau->qualite = qualite;
    nouveau-> suivant = popu->premier;
    popu-> premier = nouveau;
}

void affichagePopulation(Population *popu)
{
    int i = 1;
    if(popu == NULL)
    {
        exit(EXIT_FAILURE);
    }
    printf("\n\n\t\tPopulation : \n");
    IndivPop *actuel = malloc(sizeof(IndivPop));
    actuel = popu ->premier;

    while(actuel != NULL)
    {
        printf("\t\tIndividu %d : qualite : %f, valeur : %d \n",i, actuel->qualite, actuel->valeur);
        actuel = actuel -> suivant;
        i++;
    };
}

void suppressionTetePop(Population *individu)
{
    if (individu == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (individu->premier != NULL)
    {
        IndivPop *tampon = individu->premier;
        individu->premier = individu->premier->suivant;
        free(tampon);
    }
}

int taillePop(Population *individu)
{
    IndivPop *element = malloc(sizeof(IndivPop));
    element = individu->premier;
    int taille = 0;
    while (element != NULL )
    {
        element = element->suivant;
        taille++;
    }
    return taille;
}
