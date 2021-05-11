#include "queue.h"
#include <stdlib.h>

#undef queue_pop
int queue_pop(Queue *_ph, queue_t *_dest)
{
    if (!_ph)
        return -1;

    Queue *p = _ph->next;
    if (!p)
        return 0;

    if (!_dest)
        return -2;

    *_dest = p->data;

    _ph->next = p->next;
    free(p);

    return 1;
}