#include "swap.h"

#undef swapc

#if 1
int swapc(char *_x, char *_y)
{
    if (!_x || !_y)
        return -1;
    if (*_x == *_y)
        return 0;

    char i = *_x;
    *_x = *_y;
    *_y = i;

    return 1;
}
#else
int swapc(char *_x, char *_y)
{
    if (!_x || !_y)
        return -1;
    if (*_x == *_y)
        return 0;

    *_x ^= *_y;
    *_y ^= *_x;
    *_x ^= *_y;

    return 1;
}
#endif

#if 0
int swap(char *_x, char *_y)
{
    *_x += *_y;
    *_y -= *_x;
    *_x -= *_y;

    return 0;
}

int swap(char *_x, char *_y)
{
    *_x *= *_y;
    *_y /= *_x;
    *_x /= *_y;

    return 0;
}
#endif