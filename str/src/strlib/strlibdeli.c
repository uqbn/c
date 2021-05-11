#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibdeli

char *strlibdeli(char *_str, const char *_substr, size_t _index)
{
    size_t nsub = strlen(_substr);
    char *substr = NULL;
    size_t i = 0;
    size_t count = 0;

    if (!nsub)
        return NULL;

    while ((substr = strstr(_str + i, _substr)))
    {
        i = (size_t)(substr - _str) / sizeof(char);

        if (count++ == _index)
        {
            return strlibdel(_str, i, i + nsub);
        }

        i += nsub;
    }

    return NULL;
}
