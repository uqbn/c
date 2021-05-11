#include <string.h>
#include "strlib.h"

#undef strncou

size_t strncou(const char *_str, const char *_substr, size_t _max)
{
    const size_t n = strnlen(_substr, _max);
    char *substr = NULL;
    size_t count = 0;
    size_t i = 0;

    if (!n)
        return 0;

    while ((substr = strnstr(_str + i, _substr, _max)))
    {
        i = (size_t)(substr - _str) / sizeof(char) + n;
        count++;
    }

    return count;
}
