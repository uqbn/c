#include <stdlib.h>
#include "stack.h"

#undef stacks_free

void stacks_free(Stacks *_ph)
{
    if (!_ph)
        return;

    stacks_free(_ph->next);

    if (_ph->str)
        free(_ph->str);
    free(_ph);

    return;
}
