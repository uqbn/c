#include "stack.h"
#include <stdio.h>

#undef stackn_display

unsigned int stackn_dispaly(Stackn *_ph)
{
    if (!_ph)
        return 0;

    unsigned int count = 0;
    while (_ph->next)
    {
        printf("%i ", _ph->next->n);
        count++;
        _ph = _ph->next;
    }

    return count;
}