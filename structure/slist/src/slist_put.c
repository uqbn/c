#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

#undef slistc_put

ssize_t slistc_put(const Slistc *_ph, FILE *_fp)
{
    if (!_ph) //_ph is void
        return -1;

    _ph = _ph->next; //skip head node

    size_t i = 0; //count variable

    while (_ph) //traverse list
    {
        putc(_ph->ch, _fp); //prssize_t _ph->ch to _fp

        _ph = _ph->next; //goto next

        i++; //count plus one
    }

    return i; //return count
}