#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibdel

char *strlibdel(char *_str, size_t _index1, size_t _index2)
{
    const size_t n = strlen(_str) + 1;
    const size_t i = _index2 - _index1;
    size_t j = 0;

    if (i >= n)
        return NULL;

    for (j = _index1; j + i < n; j++)
    {
        _str[j] = _str[j + i];
    }

    _str = (char *)realloc(_str, j--);

    _str[j] = '\0';

    return _str;
}