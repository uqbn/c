#include <stdlib.h>
#include "slist.h"

#undef slistc_free

void slistc_free(Slistc *_ph)
{
    if (_ph) //_ph not is void
    {
        slistc_free(_ph->next); //goto next

        free(_ph); //free memory of _ph
    }

    return;
}