#include "strbuf.h"

int strrdelx(char *_str, const char *_substr, size_t _index)
{
    if (!_str)
        return -1;
    if (!_substr)
        return -2;

    size_t nsub = strlen(_substr);
    if (!nsub)
        return 0;

    char *substr = NULL;

    for (size_t i = strlen(_str), count = 0; (substr = strrnstr(_str, _substr, i)); count++)
    {
        i = (size_t)(substr - _str) / sizeof(char);

        if (count == _index)
        {
            _strdel(i, _str, _substr, nsub);

            return 1;
        }
    }

    return 0;
}



int strrmodx(char *_str, size_t _strsz, const char *_oldstr, const char *_newstr, size_t _index)
{
    if (!_str)
        return -1;
    if (!_oldstr)
        return -2;
    if (!_newstr)
        return -3;

    size_t nold = strlen(_oldstr);
    size_t nnew = strlen(_newstr);
    if (!nold)
        return 0;

    char *str = NULL;
    for (size_t i = strlen(_str), count = 0; (str = strrnstr(_str, _oldstr, i)); count++)
    {

        i = (size_t)(str - _str) / sizeof(char);

        if (_index == count)
        {
            _strmod(i, _str, _strsz, _oldstr, nold, _newstr, nnew);

            return 1;
        }
    }

    return 0;
}
