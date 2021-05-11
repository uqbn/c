#include "stack.h"
#include <stdlib.h>
#include <string.h>

#undef stacks_pop

int stacks_pop(Stacks *_ph, char **_dst)
{
    if (!_ph)
        return -1;

    Stacks *p = _ph->next;
    if (!p || !p->str)
        return 0;

    if (!_dst)
        return -2;

    *_dst = (char *)malloc((strlen(p->str) + 1) * sizeof(char));

    strcpy(*_dst, p->str);
    _ph->next = p->next;

    if (p->str)
        free(p->str);
    free(p);

    return 1;
}
