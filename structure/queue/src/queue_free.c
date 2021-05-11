#include "queue.h"
#include <stdlib.h>

#undef queue_free
void queue_free(Queue *_ph)
{
    if (!_ph)
        return;
    queue_free(_ph->next);
    free(_ph);
    return;
}
