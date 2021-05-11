#include <stdlib.h>
#include "slist.h"

#undef slistc_rchr

ssize_t slistc_rchr(const Slistc *_ph, char _ch)
{
    if (!_ph) // _ph is void
        return -1;

    _ph = _ph->next; //skip head node

    Slistc *ph = slistc_init(); //create head node
    Slistc *p = NULL;           //Slist pointer variable

    size_t i = 0; //count variable

    while (_ph) //traverse list
    {
        p = slistc_init(); //create a node
        p->ch = _ph->ch;   //assign value

        p->next = ph->next; //link
        ph->next = p;       //link

        _ph = _ph->next; //goto next

        i++; //count plus one
    }

    p = ph->next; //skipp head node

    size_t j = 0; //count variable

    while (p)
    {
        if (p->ch == _ch) //if find the character
        {
            slistc_free(ph); //free memory of hp

            return i - j; //success
        }

        p = p->next; //goto next

        j++; //count plus one
    }

    slistc_free(ph); //free memory of hp

    return -2; //failure
}