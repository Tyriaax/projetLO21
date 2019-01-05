#ifndef INDIVIDU_H_INCLUDED
#define INDIVIDU_H_INCLUDED

typedef struct Individu Individu;
struct Individu
{
    int bits;
    Individu *suivant;
};

typedef struct Liste Liste;
struct Liste
{
    Individu *premier;
};


Liste* creation_indiv();
void ajoutDebut(Liste *liste, int nvNombre);
void afficherListe (Liste *liste, int nb);
void supprimerQueue (Liste *liste);
int decodageListe (Liste *liste );
double qualiteIndiv (int valIndiv);
Liste* croisageListe (Liste *parent1, Liste *parent2);
void ajouterFin (Liste *maListe, int nvNombre);
void suppressionTete(Liste *liste);


#endif // INDIVIDU_H_INCLUDED
