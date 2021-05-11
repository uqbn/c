#include "stack.h"

#undef stackn_empty

int stackn_empty(Stackn *_ph)
{
    if (!_ph)
        return -1;

    if (!_ph->next)
        return 1;

    return 0;
}