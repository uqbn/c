#include "slist.h"
#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    Slistc *header = slistc_init();
    for (int i = 0; i < 10; i++)
    {
        slistc_add(header, '1' + i);
    }
    slistc_put(header, stdout);
    putchar('\n');
    slistc_swaps(header, 1, 2, 4, 3);
    putchar('\n');
    slistc_put(header, stdout);
    return 0;
}