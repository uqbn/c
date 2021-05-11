#include <stdlib.h>
#include "slist.h"

#undef slistc_ins

ssize_t slistc_ins(Slistc *_ph, size_t _index, char _ch)
{
    if (!_ph) // _ph is void
        return -1;

    size_t i = 0;

    while (_ph) //traverse list
    {
        if (i++ == _index)
        {
            Slistc *p = slistc_init(); //create a node

            p->ch = _ch; //assign value

            p->next = _ph->next; //link node
            _ph->next = p;       //link node

            return 1; //return success
        }

        _ph = _ph->next; //goto next
    }

    return 0; //return failure
}

