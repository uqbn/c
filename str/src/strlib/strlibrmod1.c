#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibrmod1

char *strlibrmod1(char *_str, const char *_oldstr, const char *_newstr)
{
    size_t nold = strlen(_oldstr);

    size_t i = 0;

    char *str = NULL;

    if (!nold)
        return NULL;

    str = strrstr(_str + i, _oldstr);

    if (str)
    {
        i = (size_t)(str - _str) / sizeof(char);

        return strlibmod(_str, i, nold, _newstr);
    }

    return NULL;
}
