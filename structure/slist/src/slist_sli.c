#include <stdlib.h>
#include "slist.h"

#undef slistc_sli

Slistc *slistc_sli(Slistc *_ph, size_t _index1, size_t _index2)
{
    if (!_ph) // _ph is void
        return NULL;

    if (_index1 > _index2)
        return NULL;

    Slistc *ph = NULL;
    Slistc *p = NULL;

    _ph = _ph->next;
    for (size_t i = 0; _ph && i < _index2; i++)
    {
        if (i == _index1)
        {
            ph = slistc_init();
            p = ph;
        }

        if (i >= _index1)
        {
            p->next = slistc_init();
            p = p->next;

            p->ch = _ph->ch;
        }

        _ph = _ph->next;
    }

    return ph;
}