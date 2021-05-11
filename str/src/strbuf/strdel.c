#include <string.h>
#include "strbuf.h"

#undef strdel

void strdel(char *_str, size_t _index, size_t _subsz)
{
    size_t j = 0;
    size_t nstr = strlen(_str) + 1;

    for (j = _index + _subsz; j < nstr; j++)
    {
        _str[j - _subsz] = _str[j];
    }

    return;
}
