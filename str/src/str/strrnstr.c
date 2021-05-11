#include <string.h>
#include "strlib.h"

#undef strrnstr

char *strrnstr(const char *_str, const char *_substr, size_t _max)
{
    char *p = NULL;
    size_t max = strnlen(_substr, _max);

    for (p = (char *)_str + strlen(_str) - 1; p >= _str; p--)
    {
        if (*p == *_substr && !memcmp(p, _substr, max))
        {
            return p;
        }
    }

    return NULL;
}
