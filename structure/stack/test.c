#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int main(int argc, char *argv[])
{
    srand(time(NULL));

    Stackn *headern1 = stackn_init();
    Stackn *headern2 = stackn_init();

    for (size_t i = 0; i < N; i++)
    {
        stackn_push(headern1, rand() % 10);
    }
    stackn_dispaly(headern1);

    int n = stackn_len(headern1);
    for (size_t i = 0; i < n; i++)
    {
        int temp = 0;
        stackn_pop(headern1, &temp);
        stackn_push(headern2, temp);
    }

    putchar('\n');
    stackn_dispalyn(headern2, N);
    putchar('\n');

    stackn_free(headern1);
    headern1 = NULL;
    stackn_free(headern2);
    headern2 = NULL;

    Stacks *headers1 = stacks_init();
    Stacks *headers2 = stacks_init();

    for (size_t i = 0; i < N; i++)
    {
        char buff[3] = {33 + rand() % (128 - 33), 33 + rand() % (128 - 33), '\0'};
        stacks_push(headers1, buff);
    }
    stacks_dispaly(headers1);

    n = stacks_len(headers1);
    for (size_t i = 0; i < n; i++)
    {
        char *temp = NULL;
        stacks_pop(headers1, &temp);
        stacks_push(headers2, temp);
    }

    putchar('\n');
    stacks_dispalyn(headers2, N);
    putchar('\n');

    stacks_free(headers1);
    headers1 = NULL;
    stacks_free(headers2);
    headers2 = NULL;

    return 0;
}