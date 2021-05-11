#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibrdel1

char *strlibrdel1(char *_str, const char *_substr)
{
    size_t nsub = strlen(_substr);
    char *substr = NULL;
    size_t i = 0;

    if (!nsub)
        return NULL;

    substr = strrstr(_str, _substr);

    if (substr)
    {
        i = (size_t)(substr - _str) / sizeof(char);

        return strlibdel(_str, i, i + nsub);
    }

    return NULL;
}
