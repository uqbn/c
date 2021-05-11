#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibdeln

char *strlibdeln(char *_str, const char *_substr, size_t _max)
{
    size_t nsub = strlen(_substr);
    char *substr = NULL;
    size_t i = 0;
    size_t count = 0;

    if (!nsub)
        return NULL;

    while ((substr = strstr(_str + i, _substr)) && count++ < _max)
    {
        i = (size_t)(substr - _str) / sizeof(char);
        _str = strlibdel(_str, i, i + nsub);
    }

    return _str;
}
