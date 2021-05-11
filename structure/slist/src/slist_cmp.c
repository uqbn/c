#include <stdlib.h>
#include "slist.h"

#undef slistc_cmp

ssize_t slistc_cmp(const Slistc *_dst, const Slistc *_src)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_src) //_src is void
        return -2;

    _dst = _dst->next; //skp head node
    _src = _src->next; //skp head node

    while (_dst && _src) //traverse list
    {
        if (_dst->ch > _src->ch) //compare characater
            return 1;
        else if (_dst->ch < _src->ch) //compare characater
            return -1;

        _dst = _dst->next; //goto next
        _src = _src->next; //goto next
    }

    if (!_dst && !_src) //both _dst and _src is void
        return 0;
    else if (!_src) //_src is void
        return 1;
    else
        return -1; //_dst is void
}