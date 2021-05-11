#include <stdlib.h>
#include "slist.h"

#undef slistc_catn

ssize_t slistc_catn(Slistc *_dst, const Slistc *_src, size_t _max)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_src) //_src is void
        return -2;

    while (_dst->next) //find tail node
        _dst = _dst->next;

    _src = _src->next; //skip head node

    size_t i = 0; //count variable

    while (_src && i++ < _max) //traverse lst
    {
        _dst->next = slistc_init(); //create a node
        _dst = _dst->next;          //goto node

        _dst->ch = _src->ch; //assign value

        _src = _src->next; //goto node
    }

    return i; //return count
}