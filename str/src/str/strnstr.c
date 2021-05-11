#include <string.h>
#include <stdlib.h>
#include "strlib.h"

#undef strnstr

char *strnstr(const char *_str, const char *_substr, size_t _max)
{
    const size_t n = strnlen(_substr, _max);

    char *p = NULL;

    for (p = (char *)_str; *p; p++)
    {
        if (*p == *_substr && !memcmp(p, _substr, n))
            return p;
    }

    return NULL;
}