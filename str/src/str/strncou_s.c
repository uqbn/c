#include <string.h>
#include "strlib.h"

#undef strncou_s

size_t strncou_s(const char *_str, size_t _max1, const char *_substr, size_t _max2)
{
    const size_t n = strnlen(_substr, _max2);
    char *substr = NULL;
    size_t count = 0;
    size_t i = 0;

    if (!n)
        return 0;

    while ((substr = strnstr(_str + i, _substr, _max2)) && i < _max1)
    {
        i = (size_t)(substr - _str) / sizeof(char) + n;
        count++;
    }

    return count;
}
