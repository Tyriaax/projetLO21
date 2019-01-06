#ifndef POPULATION_H_INCLUDED
#define POPULATION_H_INCLUDED

#include "Individu.h"


Population* creationPop(void);
void insertTetePop(Population *, Individu *, int, double );
void affichagePopulation(Population *);
void suppressionTetePop(Population *);
int taillePop(Population *);

#endif // POPULATION_H_INCLUDED
