#include "stack.h"
#include <stdlib.h>

#undef stackn_push

int stackn_push(Stackn *_ph, stackn_t _data)
{
    if (!_ph)
        return -1;

    Stackn *data = (Stackn *)malloc(sizeof(Stackn));

    data->n = _data;
    data->next = _ph->next;
    _ph->next = data;
    _ph->n++;

    return 1;
}