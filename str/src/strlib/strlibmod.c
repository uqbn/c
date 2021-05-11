#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibmod

char *strlibmod(char *_str, size_t _index, size_t _size, const char *_newstr)
{
    const size_t nstr = strlen(_str);
    const size_t nnew = strlen(_newstr);
    size_t nsub = 0;
    size_t i = 0;

    if (_size < nnew)
    {
        nsub = nnew - _size;

        _str = (char *)realloc(_str, nstr + nsub + 1);

        for (i = nstr; i + 1 > _index + _size; i--)
        {
            _str[i + nsub] = _str[i];
        }

        for (i = 0; i < nnew; i++)
        {
            _str[_index + i] = _newstr[i];
        }
    }
    else if (_size > nnew)
    {
        nsub = _size - nnew;

        for (i = 0; i < nnew; i++)
        {
            _str[_index + i] = _newstr[i];
        }

        for (i = _index + _size; i < nstr + 1; i++)
        {
            _str[i - nsub] = _str[i];
        }

        if (_index + _size < nstr + 1)
            _str = (char *)realloc(_str, nstr - nsub + 1);
    }
    else
    {
        for (i = 0; i < nnew; i++)
        {
            _str[_index + i] = _newstr[i];
        }
    }

    return _str;
}
