#include <stdlib.h>
#include "slist.h"

#undef slistc_swaps

ssize_t slistc_swaps(Slistc *_ph, ssize_t _index1, ssize_t _max1, ssize_t _index2, ssize_t _max2)
{
    if (!_ph) //if _ph is void
        return -1;

    if (_index1 == _index2) //same characterd
        return 0;

    if (_index1 < _index2 && _index1 + _max1 > _index2)
        return -2;
    else if (_index1 > _index2 && _index2 + _max2 > _index1)
        return -2;

    Slistc *ph1 = NULL; //head poiinter variable
    Slistc *ph2 = NULL; //head poiinter variable

    for (size_t i = 0; _ph; i++) //traversse list _ph
    {
        if (i == _index1) //find _index1
        {
            ph1 = _ph;
        }
        else if (i == _index2) //find _index2
        {
            ph2 = _ph;
        }

        _ph = _ph->next; //goto next
    }

    if (ph1->next && ph2->next) //find both _index1 and _index2
    {
        Slistc *p1 = ph1; //end pointer
        Slistc *p2 = ph2; //end pointer

        for (size_t i = 0; p1->next && i < _max1; i++) //get pointer _index1
            p1 = p1->next;
        for (size_t i = 0; p2->next && i < _max2; i++) //get pointer _index2
            p2 = p2->next;

        Slistc *p = NULL;

        if (_max1 && _max2)
        {
            p = ph1->next; //relink head
            ph1->next = ph2->next;
            ph2->next = p;

            p = p2->next; //relink end
            p2->next = p1->next;
            p1->next = p;
        }
        else if (_max2)
        {
            p = ph2->next; //record pointer

            ph2->next = p2->next; //cut list

            p2->next = ph1->next; //relink
            ph1->next = p;
        }
        else if (_max1)
        {
            p = ph1->next; //record pointer

            ph1->next = p1->next; //cut list

            p1->next = ph2->next; //relink
            ph2->next = p;
        }

        return 1; //success
    }

    return 0; //failure
}