#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

#undef slistc_putn

ssize_t slistc_putn(const Slistc *_ph, size_t _count, FILE *_fp)
{
    if (!_ph) //_ph is void
        return -1;

    _ph = _ph->next; //skip head node

    size_t i = 0; //count variable

    while (_ph && i++ < _count) //traverse list
    {
        putc(_ph->ch, _fp); //prssize_t _ph->ch to _fp

        _ph = _ph->next; //goto next
    }

    return i; //return count
}