#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibmodi

char *strlibmodi(char *_str, const char *_oldstr, const char *_newstr, size_t _index)
{
    size_t nold = strlen(_oldstr);

    size_t i = 0;
    size_t count = 0;

    char *str = NULL;

    if (!nold)
        return NULL;

    while ((str = strstr(_str + i, _oldstr)))
    {
        i = (size_t)(str - _str) / sizeof(char);

        if (count++ == _index)
        {
            return strlibmod(_str, i, nold, _newstr);
        }

        i += nold;
    }

    return NULL;
}
