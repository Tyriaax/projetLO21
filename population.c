#include <stdio.h>
#include <stdlib.h>
#include "population.h"
#include <time.h>

Population* creationPop(void)
{
    Population *listePop = malloc(sizeof(*listePop)); //contient l'adresse du 1er indiv de la pop
    IndivPop *elementPop = malloc(sizeof(IndivPop));
    IndivPop *elementPop1 = malloc(sizeof(IndivPop));

    int taillePopulation = 10;//rand()%(201 - 20) + 20;

    if(listePop == NULL || elementPop == NULL || elementPop1 == NULL)
    {
        exit(EXIT_FAILURE);
    }

    elementPop->Personne = creation_indiv();
   // afficherListe(elementPop->Personne,1);
    elementPop->valeur = decodageListe(elementPop->Personne);
    elementPop->qualite = qualiteIndiv(elementPop ->valeur);
    elementPop -> suivant = NULL;
    listePop -> premier = elementPop;
     // printf("\td : qualite : %f, valeur : %d \n", elementPop->qualite, elementPop->valeur);
    int i;

    for(i = 1; i < taillePopulation; i++)
    {
        elementPop1->Personne = creation_indiv();
       // afficherListe(elementPop1->Personne, i + 1);
        elementPop1 ->valeur = decodageListe(elementPop1->Personne);
        elementPop1->qualite = qualiteIndiv(elementPop1 ->valeur);
       // printf("\td : qualite : %f, valeur : %d \n", elementPop1->qualite, elementPop1->valeur);
        ajoutDebutPop(listePop, elementPop1->Personne, elementPop1 ->valeur, elementPop1->qualite);
    }

    return listePop;
}

void ajoutDebutPop(Population *maPop, Liste *adresseIndiv, int val, double qual)
{
    IndivPop *nouveau = malloc(sizeof(*nouveau));
    if(maPop == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau-> Personne = adresseIndiv;
    nouveau->valeur = val;
    nouveau->qualite = qual;
    nouveau-> suivant = maPop->premier;
    maPop-> premier = nouveau;
}

void afficherPop (Population *popu)
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

void suppressionTetePop(Population *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        IndivPop *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}
