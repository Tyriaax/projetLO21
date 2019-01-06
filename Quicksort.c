#include "Quicksort.h"
#include <stdio.h>
#include <stdlib.h>
#include "population.h"
#include "constante.h"

IndivPop* lecturePop(Population *popu, int nombre)
{
    if(popu==NULL)
    {
        exit(EXIT_FAILURE);
    }

    IndivPop *elem = popu->premier;

    int i;
    for(i=0;i<nombre;i++)
    {
        if(elem==NULL)
        {
            exit(EXIT_FAILURE);
        }

        elem = elem->suivant;
    }

    return elem;
}

Population* croisagePopulation (Population *popu)
{
    int nbAlea1, nbAlea2, i;

    Population *newPop = malloc(sizeof(Population));
    IndivPop *indivNewPop = malloc(sizeof(IndivPop));

    newPop ->premier = indivNewPop;
    indivNewPop ->suivant = NULL;
    indivNewPop ->Personne = NULL;
    indivNewPop ->qualite = 0;
    indivNewPop ->valeur = 0;

    for(i = 0; i < getTaillePop(popu);i++)
    {
        printf("%d",i);
        nbAlea1 = rand()%getTaillePop(popu);
        do
        {
            nbAlea2 = rand()%getTaillePop(popu);
        }
        while(nbAlea1 == nbAlea2);

        IndivPop *parent1 = lecturePop(popu,nbAlea1);
        IndivPop *parent2 = lecturePop(popu,nbAlea2);

        Individu *enfant = croisageListe(parent1->Personne,parent2->Personne);

        int valeurEnfant = decodageListe(enfant);

        printf("s");
        ajouterFinPop(newPop,qualiteIndiv(valeurEnfant),valeurEnfant,enfant);
    }
    suppressionTetePop(newPop);
    return newPop;
}

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

void ajouterFinPop (Population *maPop, double nvNombre,int val, Liste *adresse)
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

Population* t_Select (Population *individu)
{
   int nombreSelection = (int)(((rand()%((int)((tselectMax-tselectMin)*100)))/100.+tselectMin)*getTaillePop(individu));

   IndivPop *element = malloc(sizeof(IndivPop));

   Population *listeSubstitution = malloc(sizeof(Population));
   IndivPop *eleLS = malloc(sizeof(IndivPop));

   if (element == NULL || individu == NULL)
   {
       exit(EXIT_FAILURE);
   }

    element = individu->premier;

    listeSubstitution->premier = eleLS;
    eleLS->suivant = NULL;
    eleLS->Personne = NULL;
    eleLS->qualite = 0;
    eleLS->valeur = 0;

    int Taille = getTaillePop(individu);
    printf("%d",nombreSelection);

    while(element != NULL)
    {
        if(nombreSelection <= 0)
        {
            SuppressionElePop(individu,element);
        }else{
            ajouterFinPop(listeSubstitution,element->qualite,element->valeur,element->Personne);
            nombreSelection--;
        }
        element = element->suivant;
    }

    int newTaille = getTaillePop(individu);

    suppressionTetePop(listeSubstitution);

    int i;

        eleLS = eleLS ->suivant;
    for(i = newTaille; i < Taille; i++)
    {
        ajouterFinPop(individu,eleLS->qualite, eleLS->valeur,eleLS->Personne);
        eleLS = eleLS ->suivant;
        if(eleLS == NULL)
        {
            eleLS = listeSubstitution ->premier;
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
