#include "queue_btree.h"
#include <stdlib.h>

Queue *queue_init(void)
{
    return (Queue *)calloc(1U, sizeof(Queue));
}

void queue_free(Queue *_ph)
{
    if (!_ph)
        return;
    queue_free(_ph->next);
    free(_ph);
    return;
}

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
