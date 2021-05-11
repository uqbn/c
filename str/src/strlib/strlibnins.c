#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibnins

char *strlibnins(char *_str, size_t _index, const char *_substr, size_t _max)
{
    const size_t nstr = strlen(_str);
    const size_t nsub = strnlen(_substr, _max);

    size_t j = 0;

    if (nstr < _index)
        _index = nstr;

    _str = (char *)realloc(_str, nstr + 1 + nsub);

    for (j = nstr; j + 1 > _index; j--) //j - 1 + 1 = j
    {
        _str[j + nsub] = _str[j];
    }

    for (j = 0; j < nsub; j++)
    {
        _str[_index + j] = _substr[j];
    }

    return _str;
}
