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
void ajoutDebutPop(Population *, Liste *adresseIndiv, int val, double qual);
void afficherPop (Population *);
void suppressionTetePop(Population *);
void ajouterFinPop (Population *, double);


#endif // POPULATION_H_INCLUDED
