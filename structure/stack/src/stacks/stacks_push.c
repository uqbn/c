#include "stack.h"
#include <stdlib.h>
#include <string.h>

#undef stacks_push

int stacks_push(Stacks *_ph, char *_str)
{
    if (!_ph)
        return -1;

    Stacks *p = (Stacks *)calloc(1, sizeof(Stacks));

    p->str = (char *)calloc(strlen(_str) + 1, sizeof(char));

    strcpy(p->str, _str);

    p->next = _ph->next;
    _ph->next = p;

    return 1;
}
