#include <string.h>
#include "strbuf.h"

#undef strmodi

int strmodi(char *_str, size_t _strsz, const char *_oldstr, const char *_newstr, size_t _index)
{
    size_t nold = strlen(_oldstr);
    size_t nnew = strlen(_newstr);
    if (!nold)
        return 0;

    char *str = NULL;
    for (size_t i = 0, count = 0; (str = strstr(_str + i, _oldstr)); count++)
    {

        i = (size_t)(str - _str) / sizeof(char);

        if (_index == count)
        {
            strmod(_str, _strsz, i, nold, _newstr, nnew);

            return 1;
        }

        i += nold;
    }

    return 0;
}
