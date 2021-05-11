#include "queue.h"

#undef queue_len
unsigned int queue_len(Queue *_ph)
{
    if (!_ph)
        return 0U;
    unsigned int count = 0;
    while (_ph->next)
    {
        count++;
        _ph = _ph->next;
    }
    return count;
}