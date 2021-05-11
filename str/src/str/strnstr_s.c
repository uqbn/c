#include <string.h>
#include <stdlib.h>
#include "strlib.h"

#undef strnstr_s

char *strnstr_s(const char *_str, size_t _max1, const char *_substr, size_t _max2)
{
    const size_t n = strnlen(_substr, _max2);

    char *p = NULL;

    for (p = (char *)_str; *p && (p - _str) < _max1; p++)
    {
        if (*p == *_substr && !memcmp(p, _substr, n))
            return p;
    }

    return NULL;
}