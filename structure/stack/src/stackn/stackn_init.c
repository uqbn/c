#include "stack.h"
#include <stdlib.h>

#undef stackn_init

Stackn *stackn_init(void)
{
    return (Stackn *)calloc(1, sizeof(Stackn));
}