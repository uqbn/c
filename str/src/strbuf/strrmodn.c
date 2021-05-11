#include <string.h>
#include "strbuf.h"

#undef strrmodn

size_t strrmodn(char *_str, size_t _strsz, const char *_oldstr, const char *_newstr, size_t _max)
{
    size_t nold = strlen(_oldstr);
    size_t nnew = strlen(_newstr);

    if (!nold)
        return 0;

    char *str = NULL;
    size_t count = 0;

    for (size_t i = 0; (str = strrstr(_str, _oldstr)) && count < _max; count++)
    {
        i = (size_t)(str - _str) / sizeof(char);

        strmod(_str, _strsz, i, nold, _newstr, nnew);
    }

    return count;
}
