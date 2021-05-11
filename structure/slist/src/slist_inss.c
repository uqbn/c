#include <stdlib.h>
#include "slist.h"

#undef slistc_inss

ssize_t slistc_inss(Slistc *_dst, size_t _index, const Slistc *_src)
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

            while (_src->next) //traverse lst
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