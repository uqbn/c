#include <stdlib.h>
#include "slist.h"

#undef slistc_swap

ssize_t slistc_swap(Slistc *_ph, size_t _index1, size_t _index2)
{
    if (!_ph) // _ph is void
        return -1;

    if (_index1 == _index2) //same character
        return 0;

    _ph = _ph->next; //skip head node

    Slistc *p1 = NULL; //the pointer of _index1
    Slistc *p2 = NULL; //the pointer of _index2

    for (size_t i = 0; _ph; i++) //traverse list
    {
        if (i == _index1) //find _index1
            p1 = _ph;
        else if (i == _index2) //find _index2
            p2 = _ph;

        _ph = _ph->next; //goto next
    }

    if (p1 && p2) //find both _index1 and _index2
    {
        char ch = p1->ch; //temp character variable
        p1->ch = p2->ch;  //swap
        p2->ch = ch;

        return 1; //success
    }

    return 0; //failure
}