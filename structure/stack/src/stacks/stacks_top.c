#include "stack.h"
#include <stdlib.h>
#include <string.h>

#undef stacks_top

int stacks_top(Stacks *_ph, char **_dst)
{
    if (!_ph)
        return -1;

    if (!_ph->next || !_ph->next->str)
        return 0;

    if (!_dst)
        return -2;

    *_dst = (char *)calloc(strlen(_ph->next->str) + 1, sizeof(char));

    strcpy(*_dst, _ph->next->str);

    return 1;
}
