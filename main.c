#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include "constante.h"
#include "individu.h"
#include "time.h"

int main()
{
    srand(time(0));
    Individu indiv;
    indiv=initIndivRecursive(indiv,longIndiv);

    int i;
    for(i=0;i<longIndiv;i++)
    {
        printf("%d\n",indiv.bit[i]);
    }

    printf("value = %d\n",valeurIndividu(indiv));

    return 0;
}
