#include <string.h>
#include "strbuf.h"

#undef strrdeln

size_t strrdeln(char *_str, const char *_substr, size_t _max)
{
    size_t nsub = strlen(_substr);

    if (!nsub)
        return 0;

    size_t count = 0;
    char *substr = NULL;

    for (size_t i = 0; (substr = strrstr(_str, _substr)) && count < _max; count++)
    {
        i = (size_t)(substr - _str) / sizeof(char);

        strdel(_str, i, nsub);
    }

    return count;
}
