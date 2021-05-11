#include <stdlib.h>
#include "slist.h"

#undef slistc_init

Slistc *slistc_init(void)
{
    Slistc *p = (Slistc *)calloc(1, sizeof(Slistc)); //create a node

    if (!p)      //create fail
        exit(1); //EXIT_FAILURE

    p->next = NULL;

    return p;
}