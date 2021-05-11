#include "stack.h"

#undef stacks_empty

int stacks_empty(Stacks *_ph)
{
    if (!_ph)
        return -1;

    if (!_ph->next)
        return 1;

    return 0;
}
