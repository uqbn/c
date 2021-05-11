#include "queue.h"
#include <stdlib.h>

#undef queue_init
Queue *queue_init(void)
{
    return (Queue *)calloc(1U, sizeof(Queue));
}