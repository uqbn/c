#include "stack.h"
#include <stdio.h>

#undef stackn_displayn

unsigned int stackn_dispalyn(Stackn *_ph, unsigned int _count)
{
    if (!_ph)
        return 0;

    unsigned int count = 0;
    while (_ph->next && count++ < _count)
    {
        printf("%i ", _ph->next->n);
        _ph = _ph->next;
    }

    return count;
}
