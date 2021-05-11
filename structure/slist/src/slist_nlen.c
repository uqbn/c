#include <stdlib.h>
#include "slist.h"

#undef slistc_nlen

ssize_t slistc_nlen(const Slistc *_ph, size_t _max)
{
    if (!_ph) //_ph is vois
        return -1;

    _ph = _ph->next; //skip head node

    size_t i = 0; //count variable

    while (_ph && i++ < _max) //traverse list
        _ph = _ph->next;      //goto next

    return i; //return count
}