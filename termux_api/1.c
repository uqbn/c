#include <stdio.h>
#include <stdlib.h>
#include "termux_api.h"

int main(int argc, char *argv[])
{
    if (argc > 1)
        while (1)
            termux_volume("music", 15);
    while (1)
        termux_volume("music", 0);
}