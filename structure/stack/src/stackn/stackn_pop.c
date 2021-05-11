#include "stack.h"
#include <stdlib.h>

#undef stackn_pop

int stackn_pop(Stackn *_ph, stackn_t *_dst)
{
    if (!_ph)
        return -1;

    Stackn *p = _ph->next;
    if (!p)
        return 0;

    if (!_dst)
        return -2;

    *_dst = p->n;

    _ph->next = p->next;
    _ph->n--;
    free(p);

    return 1;
}
