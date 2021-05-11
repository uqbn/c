#include <stdlib.h>
#include "slist.h"

#undef slistc_inssn

ssize_t slistc_inssn(Slistc *_dst, size_t _index, const Slistc *_src, size_t _max)
{
    if (!_dst) //_dst is void
        return -1;
    else if (!_src) //_src is void
        return -2;

    size_t i = 0; //count variale

    while (_dst) //traverse list
    {
        if (i++ == _index) //find _index
        {
            Slistc *p = slistc_init(); //create a node
            Slistc *ph = p;            //record the head node

            size_t j = 0; // count variable

            while (_src->next && j++ < _max) //traverse lst
            {
                p->next = slistc_init(); //create a node
                p = p->next;             //goto node

                p->ch = _src->ch; //assign value

                _src = _src->next; //goto node
            }

            p->next = _dst->next;  //link
            _dst->next = ph->next; //link

            free(ph); //free memory of head node of ph;

            return 1; //success
        }

        _dst = _dst->next; //goto next
    }

    return 0; //fialure
}