#include <string.h>
#include "strbuf.h"

#undef strdeli

int strdeli(char *_str, const char * _substr, size_t _index)
{
    size_t nsub = strlen(_substr);

    if (!nsub)
        return 0;

    char *substr = NULL;
    for (size_t i = 0, count = 0; (substr = strstr(_str + i, _substr)); count++)
    {
        i = (size_t)(substr - _str) / sizeof(char);

        if (count == _index)
        {
            strdel(_str, i, nsub);

            return 1;
        }

        i += nsub;
    }

    return 0;
}
