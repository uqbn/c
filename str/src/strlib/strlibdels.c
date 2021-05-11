#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibdels

char *strlibdels(char *_str, const char *_substr)
{
    size_t nsub = strlen(_substr);
    char *substr = NULL;
    size_t i = 0;

    if (!nsub)
        return 0;

    while ((substr = strstr(_str + i, _substr)))
    {
        i = (size_t)(substr - _str) / sizeof(char);

        _str = strlibdel(_str, i, i + nsub);
    }

    return _str;
}
