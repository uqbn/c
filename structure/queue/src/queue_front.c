#include "queue.h"

#undef queue_front
int queue_front(Queue *_ph, queue_t *_dest)
{
    if (!_ph)
        return -1;

    if (!_ph->next)
        return 0;

    if (!_dest)
        return -2;

    *_dest = _ph->next->data;

    return 1;
}