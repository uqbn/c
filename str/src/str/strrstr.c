#include <string.h>
#include "strlib.h"

#undef strrstr

char *strrstr(const char *_str, const char *_substr)
{
    char *p = NULL;
    size_t n = strlen(_substr);

    for (p = (char *)_str + strlen(_str) - 1; p >= _str; p--)
    {
        if (*p == *_substr && !memcmp(p, _substr, n))
        {
            return p;
        }
    }

    return NULL;
}
