#include <stdlib.h>
#include "slist.h"

#undef slistc_rstr

ssize_t slistc_rstr(const Slistc *_dst, const Slistc *_src)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_src) //_src is void
        return -2;

    _dst = _dst->next; //skp head node
    _src = _src->next; //skp head node

    Slistc *dst = slistc_init(); //create head node
    Slistc *src = slistc_init(); //create head node

    Slistc *p = NULL; //Slist pointer variable

    size_t i = 0; //count variable dsr
    size_t j = 0; //count variable src

    while (_dst) //traverse list _dst
    {
        p = slistc_init(); //create a node
        p->ch = _dst->ch;  //assign value

        p->next = dst->next; //link
        dst->next = p;       //link

        _dst = _dst->next; //goto next

        i++; //count plus one
    }

    while (_src) //traverse list _src
    {
        p = slistc_init(); //create a node
        p->ch = _src->ch;  //assign value

        p->next = src->next; //link
        src->next = p;       //link

        _src = _src->next; //goto next

        j++; //count plus one
    }

    _dst = dst->next; //skp head node
    _src = src->next; //skp head node

    size_t k = 0; //count variable

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

            if (!p2) //p2 is void or find src
            {
                slistc_free(dst);
                slistc_free(src);

                return i - j - k;
            }
        }

        _dst = _dst->next; //goto next

        k++; //count plus one
    }

    slistc_free(dst);
    slistc_free(src);

    return -3;
}