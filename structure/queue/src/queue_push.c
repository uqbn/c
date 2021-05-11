#include "queue.h"
#include <stdlib.h>

#undef queue_push
int queue_push(Queue *_ph, queue_t _data)
{
    if (!_ph)
        return -1;
    while (_ph->next)
    {
        _ph = _ph->next;
    }
    _ph->next = (Queue *)calloc(1, sizeof(Queue));
    _ph->next->data = _data;
    return 1;
}