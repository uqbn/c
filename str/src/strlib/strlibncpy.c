#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibncpy

/* Copy SRC to DEST.  */

char *strlibncpy(char *_dst, const char *_src, size_t _max)
{
    const size_t n = strnlen(_src, _max);

    _dst = (char *)realloc(_dst, n + 1);

    strncpy(_dst, _src, _max);

    _dst[n] = '\0';

    return _dst;
}