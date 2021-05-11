#include <stdlib.h>
#include "slist.h"

#undef slistc_str

ssize_t slistc_str(const Slistc *_dst, const Slistc *_src)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_src) //_src is void
        return -2;

    _dst = _dst->next; //skp head node
    _src = _src->next; //skp head node

    if (!_src) //_src is "" (void)
        return 0;

    size_t i = 0; //count variable

    while (_dst) //traverse list _dst
    {
        if (_dst->ch == _src->ch) //compare the first character
        {
            Slistc *p1 = _dst->next; //pointer
            Slistc *p2 = _src->next; //pointer

            while (p1 && p2) //tarvsese list _src
            {
                if (p1->ch != p2->ch) //compare the remainings characters
                    break;

                p1 = p1->next; //goto next
                p2 = p2->next; //goto next
            }

            if (!p2) //p2 is void or find _src
                return i;
        }

        _dst = _dst->next; //goto next

        i++; //count plus one
    }

    return -3; //failure
}