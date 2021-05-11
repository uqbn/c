#include <stdlib.h>
#include "slist.h"

#undef slistc_len

ssize_t slistc_len(const Slistc *_ph)
{
    if (!_ph) //_ph is vois
        return -1;

    _ph = _ph->next; //skip head node

    size_t i = 0; //count variable

    while (_ph) //traverse list
    {
        _ph = _ph->next; //goto next

        i++; //count plus noe
    }

    return i; //return count
}