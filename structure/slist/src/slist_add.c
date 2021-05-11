#include <stdlib.h>
#include "slist.h"

#undef slistc_add

ssize_t slistc_add(Slistc *_ph, char _ch)
{
    if (!_ph) //_ph is void
        return -1;

    while (_ph->next) //find the tail node
        _ph = _ph->next;

    _ph->next = slistc_init(); //create a node

    _ph->next->ch = _ch; //assign value

    return 1; //success
}
