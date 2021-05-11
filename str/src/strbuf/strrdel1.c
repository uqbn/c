#include <string.h>
#include "strbuf.h"

#undef strrdel1

int strrdel1(char *_str, const char *_substr)
{
    char *str = strrstr(_str, _substr);

    if (str)
    {
        size_t nsub = strlen(_substr);

        if (!nsub)
            return 0;

        strdel(_str, (size_t)(str - _str) / sizeof(char), nsub);

        return 1;
    }

    return 0;
}
