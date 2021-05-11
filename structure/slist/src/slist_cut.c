#include <stdlib.h>
#include "slist.h"

#undef slistc_cut

Slistc *slistc_cut(Slistc *_ph, size_t _index1, size_t _index2)
{
    if (!_ph) // _ph is void
        return NULL;

    if (_index1 > _index2)
        return NULL;

    Slistc *p1 = NULL;
    Slistc *p2 = NULL;

    for (size_t i = 0; _ph->next; i++)
    {
        if (i == _index1)
            p1 = _ph;
        else if (i == _index2)
            p2 = _ph;
        _ph = _ph->next;
    }

    if (!p2)
        p2 = _ph;

    if (p1)
    {
        _ph = p1->next;
        p1->next = p2->next;
        p2->next = NULL;

        Slistc *ph = slistc_init();
        ph->next = _ph;

        return ph;
    }

    return NULL;
}