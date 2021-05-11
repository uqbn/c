#include <stdlib.h>
#include "slist.h"

#undef slistc_toan

char *slistc_toan(const Slistc *_ph, size_t _max)
{
    if (!_ph) // _ph is void
        return NULL;

    char *str = (char *)calloc(1, sizeof(char)); //calloc a char

    if (!str) //calloc char fail
        return NULL;

    _ph = _ph->next; //skep head node

    size_t i = 0; //count variable

    while (_ph && i < _max) //traverse list
    {
        str = (char *)realloc(str, i + 2); //reallocation memory

        str[i++] = _ph->ch; //assign value

        _ph = _ph->next; //goto next
    }
    str[i] = '\0'; //terminator

    return str; //return string
}