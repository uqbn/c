#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibcpy_s

char *strlibcpy_s(char *_dst, size_t _indexdst, const char *_src)
{
    const size_t index = strnlen(_dst, _indexdst);

    const size_t n = strlen(_src) + index;

    _dst = (char *)realloc(_dst, n + 1);

    strcpy(_dst + index, _src);

    _dst[n] = '\0';

    return _dst;
}
