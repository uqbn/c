#include "stack.h"

#undef stackn_len

unsigned int stackn_len(Stackn *_ph)
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