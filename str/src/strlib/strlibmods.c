#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibmods

char *strlibmods(char *_str, const char *_oldstr, const char *_newstr)
{
    size_t nold = strlen(_oldstr);

    size_t i = 0;

    char *str = NULL;

    if (!nold)
        return NULL;

    while ((str = strstr(_str + i, _oldstr)))
    {
        i = (size_t)(str - _str) / sizeof(char);

        _str = strlibmod(_str, i, nold, _newstr);
    }

    return _str;
}
