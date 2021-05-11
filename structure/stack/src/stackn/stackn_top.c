#include "stack.h"

#undef stackn_top

int stackn_top(Stackn *_ph, stackn_t *_dst)
{
    if (!_ph)
        return -1;

    if (!_ph->next)
        return 0;

    if (!_dst)
        return -2;

    *_dst = _ph->next->n;

    return 1;
}
