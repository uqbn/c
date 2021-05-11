#include <string.h>
#include "strbuf.h"

#undef strmods

size_t strmods(char *_str, size_t _strsz, const char *_oldstr, const char *_newstr)
{
    size_t nold = strlen(_oldstr);
    size_t nnew = strlen(_newstr);

    if (!nold)
        return 0;

    char *str = NULL;
    size_t count = 0;

    for (size_t i = 0; (str = strstr(_str + i, _oldstr)); count++)
    {
        i = (size_t)(str - _str) / sizeof(char);

        strmod(_str, _strsz, i, nold, _newstr, nnew);
    }

    return count;
}
