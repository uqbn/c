#include <stdlib.h>
#include "slist.h"

#undef slistc_aton

Slistc *slistc_aton(const char *_src, size_t _max)
{
    if (!_src) //_src is void
        return NULL;

    Slistc *ph = slistc_init(); //create header pointer
    Slistc *p = ph;             //store

    for (size_t i = 0; i < _max && _src[i]; i++) //traverse string
    {
        Slistc *pch = slistc_init(); //cfreate a node

        pch->ch = _src[i]; //assign value

        p->next = pch; //link node

        p = p->next; //goto next
    }

    return ph; //return header pointer
}
