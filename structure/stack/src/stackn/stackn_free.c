#include "stack.h"
#include <stdlib.h>

#undef stackn_free

void stackn_free(Stackn *_ph)
{
    if (!_ph)
        return;

    stackn_free(_ph->next);
    free(_ph);

    return;
}