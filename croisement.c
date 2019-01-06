#include <stdio.h>
#include <stdlib.h>
#include "population.h"
#include "Individu.h"
#include "constante.h"
#include "croisement.h"

Population* croisagePopulation (Population *popu) //croisage de la population
{
    int nbAlea1, nbAlea2, i;

    Population *popu2 = malloc(sizeof(Population));
    IndivPop *indivPopu2 = malloc(sizeof(IndivPop));

    popu2 ->premier = indivPopu2;
    indivPopu2 ->suivant = NULL;
    indivPopu2 ->Personne = NULL;
    indivPopu2 ->qualite = 0;
    indivPopu2 ->valeur = 0;

    for(i = 0; i < taillePop(popu);i++)
    {

        nbAlea1 = rand()%taillePop(popu);
        do
        {
            nbAlea2 = rand()%taillePop(popu);
        }
        while(nbAlea1 == nbAlea2);

        IndivPop *parent1 = lecturePop(popu,nbAlea1);
        IndivPop *parent2 = lecturePop(popu,nbAlea2);

        elemIndiv *enfant = croisageListe(parent1->Personne,parent2->Personne);

        int valeurEnfant = valeur(enfant);

        ajouterFinPop(popu2,qualite(valeurEnfant),valeurEnfant,enfant);
    }
    suppressionTetePop(popu2);
    return popu2;
}

IndivPop* lecturePop(Population *popu, int nombre) //renvoie l'adresse de l'element contenant un individu à la place demandée
{
    if(popu==NULL)
    {
        exit(EXIT_FAILURE);
    }

    IndivPop *elem = popu->premier;

    int i;
    for(i=0;i<nombre;i++)
    {
        if(elem==NULL)
        {
            exit(EXIT_FAILURE);
        }

        elem = elem->suivant;
    }

    return elem;
}

Individu* croisageListe (Individu *parent1, Individu *parent2) //croisement entre 2 individus avec probabilité
{
    Individu *individuEnfant = malloc(sizeof(*individuEnfant));
    elemIndiv *element = malloc(sizeof(*element));

    element->bits = 0;
    element -> suivant = NULL;
    individuEnfant -> premier = element;

    elemIndiv *actuel1 = parent1 -> premier;
    elemIndiv *actuel2 = parent2 -> premier;

    if(parent1 == NULL || parent2 == NULL || individuEnfant == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int i;
    for(i = 0; i<= longIndiv -1; i++)
    {
        int nbAlea = rand()%2;

        if( nbAlea < pCroise)
        {
            insertQueueIndiv(individuEnfant,actuel1->bits);
        }else{
            insertQueueIndiv(individuEnfant,actuel2->bits);
        }
        actuel1 = actuel1 ->suivant;
        actuel2 = actuel2 ->suivant;
    }

    suppressionTete(individuEnfant);

    return individuEnfant;
}
