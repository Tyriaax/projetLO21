#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
#include "constante.h"

typedef unsigned char Bit;

typedef struct elementIndiv
{
    Bit bit;
    struct elementIndiv* suivant;
}elementIndiv;

typedef elementIndiv* Individu;

#endif // STRUCTURE_H_INCLUDED
