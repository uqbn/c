#include <assert.h>
#include "str.h"

char *strrstr(char *const _str, const char *const _substr)
{
    if (!_str || !_substr)
        return NULL;

    char *p = NULL;
    for (p = _str + strlen(_str) - 1; p >= _str; p--)
    {
        if (*p == *_substr && !memcmp(p, _substr, strlen(_substr)))
        {
            return p;
        }
    }

    return NULL;
}

char *strrnstr(char *const _str, const char *const _substr, size_t _max)
{
    if (!_str || !_substr)
        return NULL;

    for (char *p = _str + strnlen(_str, _max) - 1; p >= _str; p--)
    {
        if (*p == *_substr && !memcmp(p, _substr, strlen(_substr)))
        {
            return p;
        }
    }

    return NULL;
}

size_t strnum(const char *const _str, const char *const _substr)
{
    if (!_str || !_substr)
        return 0;

    size_t count = 0;
    size_t nsub = strlen(_substr);
    if (!nsub)
        return 0;

    char *substr = NULL;
    for (size_t i = 0; (substr = strstr(_str + i, _substr)); count++)
    {
        i = (size_t)(substr - _str) / sizeof(char) + nsub;
    }

    return count;
}

size_t strnnum(const char *const _str, size_t _max, const char *const _substr)
{
    if (!_str || !_substr)
        return 0;

    size_t count = 0;
    size_t nsub = strlen(_substr);
    if (!nsub)
        return 0;

    char *substr = NULL;
    for (size_t i = 0; i < _max && (substr = strstr(_str + i, _substr)); count++)
    {
        i = (size_t)(substr - _str) / sizeof(char) + nsub;
    }

    return count;
}

int strgetpath(char *const _buff, const char *const _fullbin)
{
    if (!_buff || !_fullbin)
        return -1;

    size_t n = strlen(_fullbin);
    size_t i = n;

    int mark = 0;
    while (i--)
    {
        if (_fullbin[i] == '/') //linux
        {
            mark = 1;
            break;
        }
        else if (_fullbin[i] == '\\') //windows
        {
            mark = -1;
            break;
        }
    }

    _buff[i + 1] = '\0';

    do
    {
        _buff[i] = _fullbin[i];
    } while (i--);

    return mark;
}

int strgetbin(char *const _buff, const char *const _fullbin)
{
    if (!_buff || !_fullbin)
        return -1;

    size_t n = strlen(_fullbin);
    size_t i = n;

    int mark = 0;
    while (i--)
    {
        if (_fullbin[i] == '/') //linux
        {
            mark = 1;
            break;
        }
        else if (_fullbin[i] == '\\') //windows
        {
            mark = -1;
            break;
        }
    }

    size_t j = 0;
    for (i++; i < n; i++)
    {
        _buff[j++] = _fullbin[i];
    }
    _buff[j] = '\0';

    return mark;
}
