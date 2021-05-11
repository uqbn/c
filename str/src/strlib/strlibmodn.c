#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibmodn

char *strlibmodn(char *_str, const char *_oldstr, const char *_newstr, size_t _max)
{
    size_t nold = strlen(_oldstr);

    size_t i = 0;
    size_t count = 0;

    char *str = NULL;

    if (!nold)
        return NULL;

    while ((str = strstr(_str + i, _oldstr)) && count++ < _max)
    {
        i = (size_t)(str - _str) / sizeof(char);

        _str = strlibmod(_str, i, nold, _newstr);
    }

    return _str;
}
