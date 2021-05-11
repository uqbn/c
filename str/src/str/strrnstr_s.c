#include <string.h>
#include "strlib.h"

#undef strrnstr_s

char *strrnstr_s(const char *_str, size_t _max1, const char *_substr, size_t _max2)
{
    char *p = NULL;
    size_t max = strnlen(_substr, _max2);

    for (p = (char *)_str + strnlen(_str, _max1) - 1; p >= _str; p--)
    {
        if (*p == *_substr && !memcmp(p, _substr, max))
        {
            return p;
        }
    }

    return NULL;
}
