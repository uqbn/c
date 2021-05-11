#include <stdlib.h>
#include "slist.h"

#undef slistc_mod

ssize_t slistc_mod(Slistc *_ph, size_t _index, char _ch)
{
    if (!_ph) // _ph is void
        return -1;

    _ph = _ph->next; //skip head node

    size_t i = 0; //count variable

    while (_ph) //traverse list
    {
        if (i++ == _index)
        {
            _ph->ch = _ch; //assign value

            return 1; //return success
        }

        _ph = _ph->next; //goto next
    }

    return 0; //return failure
}