#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED
#include "Population.h"
void SuppressionElePop(Population *, IndivPop *);
int getTaillePop(Population *);
void ajouterFinPop (Population *maPop, double nvNombre,int val, Liste *adresse);
Population* t_Select (Population *);
IndivPop *getTail(IndivPop *);
IndivPop* Diviser(IndivPop *, IndivPop *, IndivPop **, IndivPop **);
IndivPop *quickSortRecur(IndivPop *, IndivPop *);
void quickSort(Population **);

#endif // QUICKSORT_H_INCLUDED
