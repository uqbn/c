#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "swap.h"

#define MAX (size_t)(800000000)

int main(void)
{
    clock_t t1 = 0;
    clock_t t2 = 0;

    uint8_t *buff1 = (uint8_t *)malloc(MAX * sizeof(uint8_t));
    uint8_t *buff2 = (uint8_t *)malloc(MAX * sizeof(uint8_t));

    for (size_t i = 0; i < MAX; i++)
    {
        buff1[i] = (uint8_t)(rand() % 256);
        buff2[i] = (uint8_t)(rand() % 256);
    }

    t1 = clock();
    swap(buff1, buff2, MAX);
    t2 = clock();
    printf("%f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    t1 = clock();
    swap(buff1, buff2, MAX - 1);
    t2 = clock();
    printf("%f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);

    return 0;
}