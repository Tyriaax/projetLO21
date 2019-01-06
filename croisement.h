#ifndef CROISEMENT_H_INCLUDED
#define CROISEMENT_H_INCLUDED
#include "structure.h"

Population* croisagePopulation (Population *);
IndivPop* lecturePop(Population *, int);
Individu* croisageListe (Individu *, Individu *);

#endif // CROISEMENT_H_INCLUDED
