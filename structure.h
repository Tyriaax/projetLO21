#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

typedef struct elemIndiv elemIndiv;
struct elemIndiv
{
    int bits;
    elemIndiv *suivant;
};

typedef struct Individu Individu;
struct Individu
{
    elemIndiv *premier;
};

typedef struct IndivPop IndivPop;
struct IndivPop
{
    Individu *Personne;
    int valeur;
    double qualite;
    IndivPop *suivant;
};

typedef struct Population Population;
struct Population
{
    IndivPop *premier;
};

#endif // STRUCTURE_H_INCLUDED
