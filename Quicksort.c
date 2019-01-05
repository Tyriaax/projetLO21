#include "Quicksort.h"
#include <stdio.h>
#include <stdlib.h>
#include "population.h"

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
        if(cur->qualite < pivot->qualite)
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

    printf("%d", newHead);
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

void quickSort(Population *headRef)
{
    IndivPop *point = malloc(sizeof(IndivPop));

    point = headRef->premier;

    (point) = quickSortRecur(point,getTail(point));
    return;
}
