#include <stdio.h>
#include "stack.h"

#undef stacks_display

unsigned int stacks_dispaly(Stacks *_ph)
{
    if (!_ph)
        return 0;

    unsigned int count = 0;
    while (_ph->next)
    {
        printf("%s ", _ph->next->str);
        count++;
        _ph = _ph->next;
    }

    return count;
}
