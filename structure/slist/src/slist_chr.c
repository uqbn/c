#include <stdlib.h>
#include "slist.h"

#undef slistc_chr

ssize_t slistc_chr(const Slistc *_ph, char _ch)
{
    if (!_ph) // _ph is void
        return -1;

    _ph = _ph->next; //skip head node

    size_t i = 0; //count variable

    while (_ph) //traverse list
    {
        if (_ph->ch == _ch) //if find the character
            return i;       //return the subscript

        _ph = _ph->next; //goto next

        i++; //count plus one
    }

    return -2; //failure
}
