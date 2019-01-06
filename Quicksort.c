#include "Quicksort.h"
#include <stdio.h>
#include <stdlib.h>
#include "population.h"
#include "constante.h"


void SuppressionElePop(Population *Pop, IndivPop *adresse)
{
    IndivPop *element = malloc(sizeof(IndivPop));
    IndivPop *tampon = malloc(sizeof(IndivPop));

    element = Pop->premier;
    tampon = Pop->premier->suivant;

    while(tampon != NULL)
    {
        if(adresse == Pop->premier)
        {
            suppressionTetePop(Pop);
        }
        if(tampon == adresse)
        {
            element->suivant = tampon->suivant;
            free(tampon);
        }
        element = element ->suivant;
        tampon = tampon ->suivant;
    }
}

void ajouterFinPop (Population *maPop, double nvNombre,int val, Individu *adresse)
{
    IndivPop *nouveau = malloc(sizeof(*nouveau));
    IndivPop *parcourtListe = malloc(sizeof(*parcourtListe));

    if(maPop == NULL || nouveau == NULL || parcourtListe == NULL)
    {
        exit(EXIT_FAILURE);
    }

    parcourtListe = maPop ->premier;

    while(parcourtListe ->suivant != NULL)
    {
        parcourtListe = parcourtListe ->suivant;
    }

    nouveau ->qualite = nvNombre;
    nouveau ->valeur = val;
    nouveau ->Personne = adresse;
    parcourtListe->suivant = nouveau;
    nouveau ->suivant = NULL;
}

Population* selection (Population *individu)
{
   int nombreSelection = (int)(((rand()%((int)((tselectMax-tselectMin)*100)))/100.+tselectMin)*taillePop(individu));

   IndivPop *element = malloc(sizeof(IndivPop));

   Population *individuSubstitution = malloc(sizeof(Population));
   IndivPop *eleLS = malloc(sizeof(IndivPop));

   if (element == NULL || individu == NULL)
   {
       exit(EXIT_FAILURE);
   }

    element = individu->premier;

    individuSubstitution->premier = eleLS;
    eleLS->suivant = NULL;
    eleLS->Personne = NULL;
    eleLS->qualite = 0;
    eleLS->valeur = 0;

    int Taille = taillePop(individu);

    while(element != NULL)
    {
        if(nombreSelection <= 0)
        {
            SuppressionElePop(individu,element);
        }else{
            ajouterFinPop(individuSubstitution,element->qualite,element->valeur,element->Personne);
            nombreSelection--;
        }
        element = element->suivant;
    }

    int newTaille = taillePop(individu);

    suppressionTetePop(individuSubstitution);

    int i;

        eleLS = eleLS ->suivant;
    for(i = newTaille; i < Taille; i++)
    {
        ajouterFinPop(individu,eleLS->qualite, eleLS->valeur,eleLS->Personne);
        eleLS = eleLS ->suivant;
        if(eleLS == NULL)
        {
            eleLS = individuSubstitution ->premier;
        }
    }


    return individu;
}


IndivPop *adresseQueue(IndivPop *actuel)
{
    while (actuel != NULL && actuel->suivant != NULL)
        actuel = actuel->suivant;
    return actuel;
}

IndivPop* diviser(IndivPop *tete, IndivPop *fin, IndivPop **nouvTete, IndivPop **nouvFin) //sépare la population autour du pivot
{
    IndivPop *pivot = fin;
    IndivPop *precedent =NULL, *actuel = NULL, *tail = NULL;

    actuel = tete, tail = fin;

    while(actuel != pivot)
    {
        if(actuel->qualite > pivot->qualite)
        {
            if(((*nouvTete)) == NULL)
            {
                (*nouvTete) = actuel;
            }

            precedent = actuel;
            actuel = actuel->suivant;

        }else{
            if(precedent)
                precedent->suivant = actuel ->suivant;
            IndivPop *tampon = actuel-> suivant;
            actuel->suivant =NULL;
            tail->suivant = actuel;
            tail = actuel;
            actuel = tampon;
        }
    }

    if((*nouvTete) == NULL)
        (*nouvTete) = pivot;

    (*nouvFin) = tail;

    return pivot;
}

IndivPop *quickSortRecur(IndivPop *tete, IndivPop *fin) //fonction permettant la séparation de la population autour d'un pivot récurrente
{
    if(tete == NULL || tete == fin)
        return tete;

    IndivPop *nouvTete = NULL, *nouvFin = NULL;

    IndivPop *pivot = diviser(tete, fin, &nouvTete,&nouvFin);

    if(nouvTete != pivot)
    {
        IndivPop *tampon = nouvTete;
        while(tampon->suivant != pivot)
        {
            tampon = tampon->suivant;
        }
        tampon->suivant = NULL;
        nouvTete = quickSortRecur(nouvTete,tampon);
        tampon = adresseQueue(nouvTete);
        tampon->suivant = pivot;
    }
    pivot ->suivant = quickSortRecur(pivot->suivant, nouvFin);

    return nouvTete;
}

void quickSort(Population **adresse)
{

    (*adresse) = quickSortRecur(*adresse,adresseQueue(*adresse));
}
