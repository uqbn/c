#include <string.h>
#include "strbuf.h"

#undef strdel1

int strdel1(char *_str, const char * _substr)
{
    char *substr = strstr(_str, _substr);

    if (substr)
    {
        size_t nsub = strlen(_substr);

        if (!nsub)
            return 0;

        strdel(_str, (size_t)(substr - _str) / sizeof(char), nsub);

        return 1;
    }

    return 0;
}
