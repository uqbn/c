#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strrstr(char *const _str, const char *const _substr)
{
    char *p = NULL;
    if (!_str)
        return NULL;
    if (!_substr)
        return _str;

    for (p = _str + strlen(_str) - 1; p >= _str; p--)
    {
        if (*p == *_substr && !memcmp(p, _substr, strlen(_substr)))
        {
            return p;
        }
    }

    return NULL;
}

char *strnrstr(char *const _str, const char *const _substr, size_t n)
{
    char *p = NULL;
    if (!_str)
        return NULL;
    if (!_substr)
        return _str;

    for (p = _str + strnlen(_str, n) - 1; p >= _str; p--)
    {
        if (*p == *_substr && !memcmp(p, _substr, strlen(_substr)))
        {
            return p;
        }
    }

    return NULL;
}

size_t strcount(const char *const _str, const char *const _substr)
{
    size_t count = 0;
    if (!_str || !_substr)
        return count;

    size_t nsub = strlen(_substr);

    char *substr = NULL;
    for (size_t i = 0; (substr = strstr(_str + i, _substr)); count++)
    {
        i = (size_t)(substr - _str) / sizeof(char) + nsub;
    }

    return count;
}

char *strlibins(char *_str, const char *const _substr, size_t i)
{
    if (!_str)
        return NULL;
    if (!_substr)
        return _str;

    size_t nstr = strlen(_str);

    if (nstr < i)
        return NULL;

    size_t nsub = strlen(_substr);
    
    _str = (char *)realloc(_str, nstr + 1 + nsub);

    for (size_t j = nstr; j >= i; j--)
    {
        _str[j + nsub] = _str[j];
    }
    
    for (size_t j = 0; j < nsub; j++)
    {
        _str[i + j] = _substr[j];
    }
    
    return _str;
}

char *strlibdel(char *_str, const char *const _substr)
{
    if (!_str)
        return NULL;
    if (!_substr)
        return _str;

    size_t nsub = strlen(_substr);

    char *substr = NULL;
    for (size_t i = 0; (substr = strstr(_str + i, _substr));)
    {
        size_t nstr = strlen(_str) + 1;

        i = (size_t)(substr - _str) / sizeof(char);

        for (size_t j = i + nsub; j < nstr; j++)
        {
            _str[j - nsub] = _str[j];
        }

        _str = (char*)realloc(_str, nstr - nsub);
    }

    return _str;
}

char *strlibdel1(char *_str, const char *const _substr)
{
    if (!_str)
        return NULL;
    if (!_substr)
        return _str;

    char *substr = strstr(_str, _substr);
    if (substr)
    {
        size_t nsub = strlen(_substr);
        size_t nstr = strlen(_str) + 1;

        size_t i = (size_t)(substr - _str) / sizeof(char);

        for (; i + nsub < nstr; i++)
        {
            _str[i] = _str[i + nsub];
        }

        _str = (char *)realloc(_str, nstr - nsub);
    }
    
    return _str;
}

char *strlibdeln(char *_str, const char *const _substr, size_t n)
{
    if (!_str)
        return NULL;
    if (!_substr)
        return _str;

    size_t count = strcount(_str, _substr);

    for (size_t i = 0; i < n && i < count; i++)
    {
        _str = strlibdel1(_str, _substr);
    }

    return _str;
}

char *strlibdelx(char *_str, const char *const _substr, size_t n)
{
    if (!_str)
        return NULL;
    if (!_substr)
        return _str;

    size_t nsub = strlen(_substr);
    size_t nstr = strlen(_str) + 1;

    char *substr = NULL;
    for (size_t i = 0, count = 0; (substr = strstr(_str + i, _substr)); count++)
    {
        i = (size_t)(substr - _str) / sizeof(char);

        if (count == n)
        {
            for (; i + nsub < nstr; i++)
            {
                _str[i] = _str[i + nsub];
            }

            _str = (char*)realloc(_str, nstr - nsub);

            return _str;
        }

        i += nsub;
    }

    return NULL;
}

char *strlibsub(char *_str, const char *const _oldstr, const char *const _newstr)
{
    if (!_str)
        return NULL;
    if (!_oldstr || !_newstr)
        return _str;

    size_t nold = strlen(_oldstr);
    size_t nnew = strlen(_newstr);

    char *str = NULL;
    for (size_t i = 0; (str = strstr(_str + i, _oldstr));)
    {
        size_t nstr = strlen(_str);

        i = (size_t)(str - _str) / sizeof(char);

        if (nold < nnew)
        {
            size_t nsub = nnew - nold;

            _str = (char*)realloc(_str, nstr + 1 + nsub);

            for (size_t j = nstr; j >= i + nsub; j--)
            {
                _str[j + nsub] = _str[j];
            }

            for (size_t j = 0; j < nnew; j++)
            {
                _str[i + j] = _newstr[j];
            }
        }
        else if (nold > nnew)
        {
            size_t nsub = nold - nnew;

            for (size_t j = 0; j < nnew; j++)
            {
                _str[i + j] = _newstr[j];
            }

            for (size_t j = i + nold; j < nstr + 1; j++)
            {
                _str[j - nsub] = _str[j];
            }

            _str = (char*)realloc(_str, nstr + 1 - nsub);
        }
        else
        {
            for (size_t j = 0; j < nnew; j++)
            {
                _str[i + j] = _newstr[j];
            }
        }
    }

    return _str;
}

char *strlibsub1(char *_str, const char *const _oldstr, const char *const _newstr)
{
    if (!_str)
        return NULL;
    if (!_oldstr || !_newstr)
        return _str;

    char *str = strstr(_str, _oldstr);
    if (str)
    {
        size_t nold = strlen(_oldstr);
        size_t nnew = strlen(_newstr);
        size_t nstr = strlen(_str);

        size_t i = (size_t)(str - _str) / sizeof(char);

        if (nold < nnew)
        {
            size_t nsub = nnew - nold;

            _str = (char*)realloc(_str, nstr + 1 + nsub);

            for (size_t j = nstr; j >= i + nsub; j--)
            {
                _str[j + nsub] = _str[j];
            }

            for (size_t j = 0; j < nnew; j++)
            {
                _str[i + j] = _newstr[j];
            }
        }
        else if (nold > nnew)
        {
            size_t nsub = nold - nnew;

            for (size_t j = 0; j < nnew; j++)
            {
                _str[i + j] = _newstr[j];
            }

            for (size_t j = i + nold; j < nstr + 1; j++)
            {
                _str[j - nsub] = _str[j];
            }

            _str = (char*)realloc(_str, nstr + 1 - nsub);
        }
        else
        {
            for (size_t j = 0; j < nnew; j++)
            {
                _str[i + j] = _newstr[j];
            }
        }
    }

    return _str;
}

char *strlibsubn(char *_str, const char *const _oldstr, const char *const _newstr, size_t n)
{
    if (!_str)
        return NULL;
    if (!_oldstr || !_newstr)
        return _str;

    size_t count = strcount(_str, _oldstr);

    for (size_t i = 0; i < n && i < count; i++)
    {
        _str = strlibsub1(_str, _oldstr, _newstr);
    }

    return _str;
}

char *strlibsubx(char *_str, const char *const _oldstr, const char *const _newstr, size_t n)
{
    if (!_str)
        return NULL;
    if (!_oldstr || !_newstr)
        return _str;

    size_t nold = strlen(_oldstr);
    size_t nnew = strlen(_newstr);
    size_t nstr = strlen(_str);

    char *str = NULL;
    for (size_t i = 0, count = 0; (str = strstr(_str + i, _oldstr)); count++)
    {

        i = (size_t)(str - _str) / sizeof(char);
        if (n == count)
        {
            if (nold < nnew)
            {
                size_t nsub = nnew - nold;

                _str = (char*)realloc(_str, nstr + 1 + nsub);

                for (size_t j = nstr; j >= i + nsub; j--)
                {
                    _str[j + nsub] = _str[j];
                }

                for (size_t j = 0; j < nnew; j++)
                {
                    _str[i + j] = _newstr[j];
                }
            }
            else if (nold > nnew)
            {
                size_t nsub = nold - nnew;

                for (size_t j = 0; j < nnew; j++)
                {
                    _str[i + j] = _newstr[j];
                }

                for (size_t j = i + nold; j < nstr + 1; j++)
                {
                    _str[j - nsub] = _str[j];
                }

                _str = (char*)realloc(_str, nstr + 1 - nsub);
            }
            else
            {
                for (size_t j = 0; j < nnew; j++)
                {
                    _str[i + j] = _newstr[j];
                }
            }

            return _str;
        }
        i += nold;
    }

    return NULL;
}
size_t strlibndel(char *_str, size_t _max, const char *const _substr)
{
    assert(_str);
    assert(_substr);

    size_t nsub = strlen(_substr);

    size_t count = 0;
    char *substr = NULL;
    for (size_t i = 0; i < _max && (substr = strstr(_str + i, _substr)); count++)
    {
        i = (size_t)(substr - _str) / sizeof(char);

        _strlibdel(i, _str, _substr, nsub);
    }

    return count;
}
size_t strlibnmod(char *_str, size_t _max, const char *const _oldstr, const char *const _newstr)
{
    assert(_str);
    assert(_oldstr);
    assert(_newstr);

    size_t nold = strlen(_oldstr);
    size_t nnew = strlen(_newstr);

    char *str = NULL;
    size_t count = 0;

    for (size_t i = 0; i < _max && (str = strstr(_str + i, _oldstr)); count++)
    {
        i = (size_t)(str - _str) / sizeof(char);

        _strlibmod(i, _str, _oldstr, nold, _newstr, nnew);
    }

    return count;
}

int main(int argc, char *argv[])
{
    char *str = calloc(strlen(argv[1]) + 1, sizeof(char));
    strcpy(str, argv[1]);
    printf("%s\n", strlibdeln(str, "12", 2));
    printf("%s\n", str);
    free(str);
    return 0;
}