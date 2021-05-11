#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibncpy_s

char *strlibncpy_s(char *_dst, size_t _indexdst, const char *_src, size_t _max)
{
    const size_t index = strnlen(_dst, _indexdst);

    const size_t n = strnlen(_src, _max) + index;

    _dst = (char *)realloc(_dst, n + 1);

    strncpy(_dst + index, _src, _max);

    _dst[n] = '\0';

    return _dst;
}
