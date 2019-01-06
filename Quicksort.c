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
    printf("%d",nombreSelection);

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


IndivPop *getTail(IndivPop *cur)
{
    while (cur != NULL && cur->suivant != NULL)
        cur = cur->suivant;
    return cur;
}

IndivPop* Diviser(IndivPop *head, IndivPop *end, IndivPop **newHead, IndivPop **newEnd)
{
    IndivPop *pivot = end;
    IndivPop *prev =NULL, *cur = NULL, *tail = NULL;

    cur = head, tail = end;

    while(cur != pivot)
    {
        printf("%f      %f\n", cur->qualite, pivot->qualite);
        if(cur->qualite > pivot->qualite)
        {
            if(((*newHead)) == NULL)
            {
                (*newHead) = cur;
            }

            prev = cur;
            cur = cur->suivant;

        }else{
            if(prev)
                prev->suivant = cur ->suivant;
            IndivPop *tmp = cur-> suivant;
            cur->suivant =NULL;
            tail->suivant = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if((*newHead) == NULL)
        (*newHead) = pivot;

    (*newEnd) = tail;

    return pivot;
}

IndivPop *quickSortRecur(IndivPop *head, IndivPop *end)
{
    if(head == NULL || head == end)
        return head;

    IndivPop *newHead = NULL, *newEnd = NULL;

    IndivPop *pivot = Diviser(head, end, &newHead,&newEnd);

    if(newHead != pivot)
    {
        IndivPop *tmp = newHead;
        while(tmp->suivant != pivot)
        {
            tmp = tmp->suivant;
        }
        tmp->suivant = NULL;
        newHead = quickSortRecur(newHead,tmp);
        tmp = getTail(newHead);
        tmp->suivant = pivot;
    }
    pivot ->suivant = quickSortRecur(pivot->suivant, newEnd);

    return newHead;
}

void quickSort(Population **headRef)
{

    (*headRef) = quickSortRecur(*headRef,getTail(*headRef));
}
