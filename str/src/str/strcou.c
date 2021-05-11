#include <string.h>
#include "strlib.h"

#undef strcou

size_t strcou(const char *_str, const char *_substr)
{
    const size_t n = strlen(_substr);
    char *substr = NULL;
    size_t count = 0;
    size_t i = 0;

    if (!n)
        return 0;

    while ((substr = strstr(_str + i, _substr)))
    {
        i = (size_t)(substr - _str) / sizeof(char) + n;
        count++;
    }

    return count;
}
