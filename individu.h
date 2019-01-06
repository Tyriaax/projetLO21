#ifndef INDIVIDU_H_INCLUDED
#define INDIVIDU_H_INCLUDED
#include "structure.h"
Individu* creation_indiv_iterative();
void insertTeteIndiv(Individu *individu, int nvNombre);
void afficherListe (Individu *individu);
void supprimerQueue (Individu *individu);
int valeur(Individu *individu );
double qualite(int valIndiv);
Individu* croisageListe (Individu *parent1, Individu *parent2);
void insertQueueIndiv(Individu *maListe, int nvNombre);
void suppressionTete(Individu *individu);


#endif // INDIVIDU_H_INCLUDED
