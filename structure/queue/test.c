#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Queue *ph = queue_init();
    for (size_t i = 0; i < 10; i++)
    {
        queue_push(ph, (queue_t)rand());
    }
    queue_t data = 0;
    for (size_t i = 0; i < 10; i++)
    {
        queue_pop(ph, &data);
        printf("%i ", data);
    }
    putchar('\n');
    queue_free(ph);
    return 0;
}