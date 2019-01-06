#include <stdio.h>
#include <stdlib.h>
#include "Individu.h"
#include <math.h>
#include "constante.h"

Liste* creation_indiv()
{
    Liste *liste = malloc(sizeof(*liste));
    Individu *element = malloc(sizeof(*element));

    if(liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element -> bits = rand()%2;
    element -> suivant = NULL;
    liste -> premier = element;

    int i;
    for(i = 0; i <= longIndiv - 2 ; i ++)
    {
        int nbAleatoire = rand()%2;
        ajoutDebut(liste, nbAleatoire);
    }

    return liste;
}

void ajoutDebut(Liste *liste, int nvNombre)
{
    Individu *nouveau = malloc(sizeof(*nouveau));
    if(liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau -> bits = nvNombre;
    nouveau-> suivant = liste->premier;
    liste -> premier = nouveau;
}


/* void creationIndivRec(Liste *liste) // Initialiser liste de bis (itérative)
{
    if(liste == NULL)
    {
        Liste *new = malloc(sizeof(Liste))
    }else{
        return
    }
}
*/

void afficherListe (Liste *liste, int nb)
{
    if(liste == NULL)
    {
        exit(EXIT_FAILURE);
    }
    printf("\tIndividu %d : ",nb);
    Individu *actuel = liste -> premier;
    while(actuel != NULL)
    {
        printf("%d -> ", actuel -> bits);
        actuel = actuel -> suivant;
    }
       printf("NULL\n");
}

/*void supprimerQueue (Liste *liste)
{
    if(liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if(liste -> premier == NULL) // a changer
    {
        free(liste);
        exit(EXIT_FAILURE);
    }

    Individu *L1 = liste -> premier;
    Individu *L2 = liste -> premier -> suivant;

    while(L2 -> suivant != NULL)
    {
        L2 = L2 -> suivant;
        L1 = L1 -> suivant;
    }

    free(L2);
    L1 -> suivant = NULL;
}
*/

int decodageListe (Liste *liste ) //val de l'indiv
{
    int valeur = 0, i = 7;

    if(liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Individu *actuel = liste -> premier;
    while(actuel != NULL || i > 0)
    {
        valeur = valeur + (actuel -> bits) * pow(2, i);
        actuel = actuel -> suivant;
        i--;
    }

   // printf("\tValeur : %d | ", valeur);

    return valeur;

    free(actuel);
}

Liste* croisageListe (Liste *parent1, Liste *parent2)
{
    float pCroise = 0.5;

    Liste *listeEnfant = malloc(sizeof(*listeEnfant));
    Individu *element = malloc(sizeof(*element));

    element->bits = 0;
    element -> suivant = NULL;
    listeEnfant -> premier = element;

    Individu *actuel1 = parent1 -> premier;
    Individu *actuel2 = parent2 -> premier;

    if(parent1 == NULL || parent2 == NULL || listeEnfant == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int i;
    for(i = 0; i<= longIndiv -1; i++)
    {
        int nbAlea = rand()%2;

        if( nbAlea < pCroise)
        {
            ajouterFin(listeEnfant,actuel1->bits);
        }else{
            ajouterFin(listeEnfant,actuel2->bits);
        }
        actuel1 = actuel1 ->suivant;
        actuel2 = actuel2 ->suivant;
    }

    suppressionTete(listeEnfant);

    return listeEnfant;
}

double qualiteIndiv (int valIndiv)
{
    double resultat = 0, X = 0, B = 1, A = -1;

    X = ((valIndiv)/(pow(2,longIndiv))) * (B - A) + A;

    resultat = -1 * pow(X,2);

    //printf("Qualite : %f |\n", resultat);

    return resultat;
}

void ajouterFin (Liste *maListe, int nvNombre)
{
    Individu *nouveau = malloc(sizeof(*nouveau));
    Individu *parcourtListe = malloc(sizeof(parcourtListe));

    if(maListe == NULL || nouveau == NULL || parcourtListe == NULL)
    {
        exit(EXIT_FAILURE);
    }

    parcourtListe = maListe ->premier;

    while(parcourtListe ->suivant != NULL)
    {
        parcourtListe = parcourtListe ->suivant;
    }

    nouveau ->bits = nvNombre;
    parcourtListe->suivant = nouveau;
    nouveau ->suivant = NULL;

}

void suppressionTete(Liste *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (liste->premier != NULL)
    {
        Individu *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

