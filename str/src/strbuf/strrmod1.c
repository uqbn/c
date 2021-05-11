#include <string.h>
#include "strbuf.h"

#undef strrmod1

int strrmod1(char *_str, size_t _strsz, const char *_oldstr, const char *_newstr)
{
    char *str = strrstr(_str, _oldstr);

    if (str)
    {
        size_t nold = strlen(_oldstr);
        size_t nnew = strlen(_newstr);

        if (!nold)
            return 0;

        strmod(_str, _strsz, (size_t)(str - _str) / sizeof(char), nold, _newstr, nnew);

        return 1;
    }

    return 0;
}
