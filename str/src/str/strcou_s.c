#include <string.h>
#include "strlib.h"

#undef strcou_s

size_t strcou_s(const char *_str, size_t _max, const char *_substr)
{
    const size_t n = strlen(_substr);
    char *substr = NULL;
    size_t count = 0;
    size_t i = 0;

    if (!n)
        return 0;

    while ((substr = strstr(_str + i, _substr)) && i < _max)
    {
        i = (size_t)(substr - _str) / sizeof(char) + n;
        count++;
    }

    return count;
}
