#include <stdlib.h>
#include "slist.h"

#undef slistc_cou

ssize_t slistc_cou(const Slistc *_dst, const Slistc *_src)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_src) //_src is void
        return -2;

    size_t nsrc = slistc_len(_src); //get length of _src
    if (!nsrc)                      //if ""
        return 0;                   //failure

    size_t count = 0; //count variable
    ssize_t i = 0;    //subscript

    while ((i = slistc_str(_dst, _src)) > -1)
    {
        count++; //count plus one

        for (size_t j = 0; j < i + nsrc; j++) //get pointer
            _dst = _dst->next;
    }

    return count; //count
}