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

char *strlibrdel1(char *_str, const char *const _substr)
{
    if (!_str)
        return NULL;
    if (!_substr)
        return _str;

    char *substr = strrstr(_str, _substr);
    if (substr)
    {
        size_t nsub = strlen(_substr);
        size_t nstr = strlen(_str) + 1;

        size_t i = (size_t)(substr - _str) / sizeof(char);

        for (; i + nsub < nstr; i++)
        {
            _str[i] = _str[i + nsub];
        }

        _str = realloc(_str, nstr - nsub);
    }
    
    return _str;
}

char *strlibrdeln(char *_str, const char *const _substr, size_t n)
{
    if (!_str)
        return NULL;
    if (!_substr)
        return _str;

    size_t count = strcount(_str, _substr);

    for (size_t i = 0; i < n && i < count; i++)
    {
        _str = strlibrdel1(_str, _substr);
    }

    return _str;
}

char *strlibrdelx(char *_str, const char *const _substr, size_t n)
{
    if (!_str)
        return NULL;
    if (!_substr)
        return _str;

    size_t nsub = strlen(_substr);
    size_t nstr = strlen(_str) + 1;

    char *substr = NULL;
    for (size_t i = nstr - 1, count = 0; (substr = strnrstr(_str, _substr,i)); count++)
    {
        i = (size_t)(substr - _str) / sizeof(char);

        if (count == n)
        {
            for (; i + nsub < nstr; i++)
            {
                _str[i] = _str[i + nsub];
            }

            _str = realloc(_str, nstr - nsub);

            return _str;
        }
    }

    return NULL;
}

char *strlibrsub1(char *_str, const char *const _oldstr, const char *const _newstr)
{
    if (!_str)
        return NULL;
    if (!_oldstr || !_newstr)
        return _str;

    char *str = strrstr(_str, _oldstr);
    if (str)
    {
        size_t nold = strlen(_oldstr);
        size_t nnew = strlen(_newstr);
        size_t nstr = strlen(_str);

        size_t i = (size_t)(str - _str) / sizeof(char);

        if (nold < nnew)
        {
            size_t nsub = nnew - nold;

            _str = realloc(_str, nstr + 1 + nsub);

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

            _str = realloc(_str, nstr + 1 - nsub);
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

char *strlibrsubn(char *_str, const char *const _oldstr, const char *const _newstr, size_t n)
{
    if (!_str)
        return NULL;
    if (!_oldstr || !_newstr)
        return _str;

    size_t count = strcount(_str, _oldstr);

    for (size_t i = 0; i < n && i < count; i++)
    {
        _str = strlibrsub1(_str, _oldstr, _newstr);
    }

    return _str;
}

char *strlibrsubx(char *_str, const char *const _oldstr, const char *const _newstr, size_t n)
{
    if (!_str)
        return NULL;
    if (!_oldstr || !_newstr)
        return _str;

    size_t nold = strlen(_oldstr);
    size_t nnew = strlen(_newstr);
    size_t nstr = strlen(_str);

    char *str = NULL;
    for (size_t i = nstr, count = 0; (str = strnrstr(_str, _oldstr,i)); count++)
    {

        i = (size_t)(str - _str) / sizeof(char);
        if (n == count)
        {
            if (nold < nnew)
            {
                size_t nsub = nnew - nold;

                _str = realloc(_str, nstr + 1 + nsub);

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

                _str = realloc(_str, nstr + 1 - nsub);
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
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    char *str = calloc(strlen(argv[1]) + 1, sizeof(char));
    strcpy(str, argv[1]);
    printf("%s\n", strlibrsubn(str, "12","x",2));
    printf("%s\n", str);
    free(str);
    return 0;
}