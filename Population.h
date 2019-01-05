#ifndef POPULATION_H_INCLUDED
#define POPULATION_H_INCLUDED

#include "Individu.h"

typedef struct IndivPop IndivPop;
struct IndivPop
{
    Liste *Personne;
    int valeur;
    double qualite;
    IndivPop *suivant;
};

typedef struct Population Population;
struct Population
{
    IndivPop *premier;
};

Population* creationPop(void);
void ajoutDebutPop(Population *maPop, Liste *adresseIndiv, int val, double qual);
void afficherPop (Population *popu);
void suppressionTetePop(Population *liste);


#endif // POPULATION_H_INCLUDED
