#include <stdio.h>
#include <stdlib.h>
#include "Individu.h"
#include <math.h>
#include "constante.h"
#include "structure.h"

Individu* creation_indiv_iterative() //Creation et initialisation d'un individu de maniere iterative
{
    Individu *individu = malloc(sizeof(*individu));
    elemIndiv *element = malloc(sizeof(*element));

    if(individu == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element -> bits = rand()%2;
    element -> suivant = NULL;
    individu -> premier = element;

    int i;
    for(i = 0; i <= longIndiv - 2 ; i ++)
    {
        int nbAleatoire = rand()%2;
        insertTeteIndiv(individu, nbAleatoire);
    }

    return individu;
}

void insertTeteIndiv(Individu *individu, int nvNombre) //Insere une valeur à la tête d'un individu
{
    elemIndiv *nouveau = malloc(sizeof(*nouveau));
    if(individu == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau -> bits = nvNombre;
    nouveau-> suivant = individu->premier;
    individu -> premier = nouveau;
}



void affichage(Individu *individu) //affiche la liste de bits chainée d'un individu
{
    if(individu == NULL)
    {
        exit(EXIT_FAILURE);
    }
    printf("\tIndividu : ");
    elemIndiv *actuel = individu -> premier;
    while(actuel != NULL)
    {
        printf("%d -> ", actuel -> bits);
        actuel = actuel -> suivant;
    }
    printf("NULL\n");
}

//Creation et initialisation d'un individu de maniere iterative
Individu* creationIndivRec(Individu *individu, int i, int randomValue)
{

     elemIndiv *element = malloc(sizeof(elemIndiv));
     element = individu ->premier;

     if( i == longIndiv)
     {
            return individu;
     }else{

            insertTeteIndiv(individu,rand()%2);

            return creationIndivRec(individu,i + 1,rand()%2);
     }
}

Individu* iniIndivRec(void) //initialisation
{
    Individu *individu = malloc(sizeof(Individu));
    elemIndiv *element = malloc(sizeof(*element));

    element -> bits = rand()%2;
    element -> suivant = NULL;
    individu -> premier = element;

    individu = creationIndivRec(individu,0,rand()%2);

    return individu;

}

int valeur(Individu *individu ) //donne la valeur d'un individu
{
    int valeur = 0, i = 7;

    if(individu == NULL)
    {
        exit(EXIT_FAILURE);
    }

    elemIndiv *actuel = individu -> premier;
    while(actuel != NULL || i > 0)
    {
        valeur = valeur + (actuel -> bits) * pow(2, i);
        actuel = actuel -> suivant;
        i--;
    }

    return valeur;

    free(actuel);
}

double qualite(int valeur) //renvoie la qualité d'un individu en fonction de sa valeur
{
    double resultat = 0, X = 0, B = 1, A = -1;

    X = ((valeur)/(pow(2,longIndiv))) * (B - A) + A;

    resultat = -1 * pow(X,2);

    return resultat;
}

void insertQueueIndiv(Individu *individu, int nvBit) //insertion d'un bit à la queue d'un individu
{
    elemIndiv *nouveau = malloc(sizeof(elemIndiv));
    elemIndiv *elem = malloc(sizeof(elemIndiv));

    if(individu== NULL || nouveau == NULL || elem == NULL)
    {
        exit(EXIT_FAILURE);
    }

    elem = individu ->premier;

    while(elem ->suivant != NULL)
    {
        elem = elem ->suivant;
    }

    nouveau ->bits = nvBit;
    elem->suivant = nouveau;
    nouveau ->suivant = NULL;

}

void suppressionTete(Individu *individu) //fonction de suppression du premier element d'un individu
{
    if (individu == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (individu->premier != NULL)
    {
        elemIndiv *adresseTampon = individu->premier;
        individu->premier = individu->premier->suivant;
        free(adresseTampon);
    }
}

