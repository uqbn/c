#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibcut

char *strlibcut(char *_str, size_t _index1, size_t _index2)
{
    const size_t n = strlen(_str) + 1;
    const size_t i = _index2 - _index1;
    size_t j = 0;
    char *str = NULL;

    if (i >= n)
        return NULL;

    for (j = _index1; j < _index2; j++)
    {
        if (!str)
            str = malloc(sizeof(char));

        if (str)
        {
            str = realloc(str, j - _index1 + 2);
            str[j - _index1] = _str[j];
            str[j - _index1 + 1] = '\0';
        }
    }

    for (j = _index1; j + i < n; j++)
    {
        _str[j] = _str[j + i];
    }

    _str = (char *)realloc(_str, j--);

    _str[j] = '\0';

    return str;
}