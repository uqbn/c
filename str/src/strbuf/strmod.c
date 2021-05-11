#include <string.h>
#include "strbuf.h"

#undef strmod

void strmod(char *_str, size_t _strsz, size_t _index, size_t _oldsz, const char *_newstr, size_t _newsz)
{
    size_t nstr = strlen(_str);

    if (_oldsz < _newsz)
    {
        size_t nsub = _newsz - _oldsz;

        for (size_t j = nstr; j + 1 > _index + _oldsz; j--)
        {
            if (j + nsub > _strsz - 1)
                continue;
            else if (j + nsub == _strsz - 1)
                _str[_strsz - 1] = '\0';
            else
                _str[j + nsub] = _str[j];
        }

        for (size_t j = 0; _index + j < _strsz && j < _newsz; j++)
        {
            _str[_index + j] = _newstr[j];
            if (_index + j == _strsz - 1)
                _str[_strsz - 1] = '\0';
        }
    }
    else if (_oldsz > _newsz)
    {
        size_t nsub = _oldsz - _newsz;

        for (size_t j = 0; j < _newsz; j++)
        {
            _str[_index + j] = _newstr[j];
        }

        for (size_t j = _index + _oldsz; j < nstr + 1; j++)
        {
            _str[j - nsub] = _str[j];
        }
    }
    else
    {
        for (size_t j = 0; j < _newsz; j++)
        {
            _str[_index + j] = _newstr[j];
        }
    }

    return;
}
