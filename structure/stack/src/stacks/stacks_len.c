#include "stack.h"

#undef stacks_len

unsigned int stacks_len(Stacks *_ph)
{
    if (!_ph)
        return 0;

    unsigned int count = 0;
    while (_ph->next)
    {
        count++;
        _ph = _ph->next;
    }

    return count;
}
