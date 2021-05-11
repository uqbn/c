#include <stdlib.h>
#include "slist.h"

#undef slistc_cpyin

ssize_t slistc_cpyin(Slistc *_dst, size_t _index, const Slistc *_src, size_t _max)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_src) //_src is void
        return -2;

    size_t i = 0; //count variable

    while (_dst->next && i++ < _index) //find tail node
        _dst = _dst->next;

    slistc_free(_dst->next); //del list

    _src = _src->next; //skip head node

    i = 0; //initializes the count variable

    while (_src && i++ < _max) //traverse lst
    {
        _dst->next = slistc_init(); //create a node
        _dst = _dst->next;          //goto node

        _dst->ch = _src->ch; //assign value

        _src = _src->next; //goto node
    }

    return i; //return count
}
