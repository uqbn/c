#include <stdlib.h>
#include "stack.h"

#undef stacks_init

Stacks *stacks_init(void)
{
    return (Stacks *)calloc(1, sizeof(Stacks));
}