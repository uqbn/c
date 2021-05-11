#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"

#define MIN 0ULL
#define MAX 100000ULL

void display(sort_t *_data, size_t _n)
{
    for (size_t i = 0U; i < _n; i++)
    {
        printf("%i ", _data[i]);
    }
    putchar('\n');
    return;
}

int main(void)
{
    sort_t *buff = (sort_t *)malloc(MAX * sizeof(sort_t));
    sort_t *buff1 = (sort_t *)malloc(MAX * sizeof(sort_t));

    clock_t start, end;

    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < MAX; i++)
    {
        buff[i] = (sort_t)rand();
    }
    //    display(buff, MAX);

    /* bulle sort */
    memcpy(buff1, buff, MAX * sizeof(sort_t));

    start = clock();
    sort_bubble(buff1, MIN, MAX - 1U);
    end = clock();

    printf("bubble \t %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    //display(buff1, MAX);

    /* selection sort */
    memcpy(buff1, buff, MAX * sizeof(sort_t));

    start = clock();
    sort_select(buff1, MIN, MAX - 1U);
    end = clock();

    printf("selection \t %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    //    display(buff1, MAX);

    /* insertion sort */
    memcpy(buff1, buff, MAX * sizeof(sort_t));

    start = clock();
    sort_insert(buff1, MIN, MAX - 1U);
    end = clock();

    printf("insertion \t %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    //    display(buff1, MAX);

    /* shell sort */
    memcpy(buff1, buff, MAX * sizeof(sort_t));

    start = clock();
    sort_shell(buff1, MIN, MAX - 1U);
    end = clock();

    printf("shell \t %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    //    display(buff1, MAX);

    /* merge sort */
    memcpy(buff1, buff, MAX * sizeof(sort_t));

    start = clock();
    sort_merge(buff1, MIN, MAX - 1U);
    end = clock();

    printf("merge \t %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    //    display(buff1, MAX);

    /* quick sort */
    memcpy(buff1, buff, MAX * sizeof(sort_t));

    start = clock();
    sort_quick(buff1, MIN, MAX - 1U);
    end = clock();

    printf("quick \t %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    //    display(buff1, MAX);

    /* heap sort */
    memcpy(buff1, buff, MAX * sizeof(sort_t));

    start = clock();
    sort_heap(buff1, MIN, MAX - 1U);
    end = clock();

    printf("heap \t %f\n", (double)(end - start) / CLOCKS_PER_SEC);
    //display(buff1, MAX);

    return 0;
}