#include <stdio.h>
#include "stack.h"

#undef stacks_displayn

unsigned int stacks_dispalyn(Stacks *_ph, unsigned int _count)
{
    if (!_ph)
        return 0;

    unsigned int count = 0;
    while (_ph->next && count++ < _count)
    {
        printf("%s ", _ph->next->str);
        _ph = _ph->next;
    }

    return count;
}