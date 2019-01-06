#include "Quicksort.h"
#include <stdio.h>
#include <stdlib.h>
#include "population.h"

void SuppressionElePop(Population *Pop, IndivPop *adresse)
{
    IndivPop *element = malloc(sizeof(IndivPop));
    IndivPop *aSupprimer = malloc(sizeof(IndivPop));

    element = Pop->premier;
    aSupprimer = Pop->premier->suivant;

    while(aSupprimer != NULL)
    {
        if(adresse == Pop->premier)
        {
            suppressionTetePop(Pop);
        }
        if(aSupprimer == adresse)
        {
            element->suivant = aSupprimer->suivant;
            free(aSupprimer);
        }
        element = element ->suivant;
        aSupprimer = aSupprimer ->suivant;
    }
}

int getTaillePop(Population *liste)
{
    IndivPop *element = malloc(sizeof(IndivPop));
    element = liste->premier;
    int n = 0;
    while (element != NULL )
    {
        element = element->suivant;
        n++;
    }
    return n;
}

void ajouterFinPop (Population *maPop, double nvNombre)
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
    parcourtListe->suivant = nouveau;
    nouveau ->suivant = NULL;

}

Population* t_Select (Population *liste)
{
   const double tSelect = -0.5;
   IndivPop *element = malloc(sizeof(IndivPop));

   Population *listeSubstitution = malloc(sizeof(Population));
   IndivPop *eleLS = malloc(sizeof(IndivPop));

   if (element == NULL || liste == NULL)
   {
       exit(EXIT_FAILURE);
   }

    element = liste->premier;

    listeSubstitution->premier = eleLS;
    eleLS->suivant = NULL;
    suppressionTetePop(listeSubstitution);

      int Taille = getTaillePop(liste);

    while(element != NULL)
    {
        if((element->qualite) < tSelect )
        {
            SuppressionElePop(liste,element);
        }else{
            ajoutDebutPop(listeSubstitution,element->Personne,element->valeur,element->qualite);
        }
        element = element->suivant;
    }

    int newTaille = getTaillePop(liste);

    printf("Pop liste substi : ");
    afficherPop(listeSubstitution);

    int i;
    for(i = newTaille; i<Taille; i++)
    {
        ajoutDebutPop(liste,eleLS->Personne, eleLS->valeur,eleLS->qualite);
        eleLS = eleLS ->suivant;
    }

    return liste;
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
