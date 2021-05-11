#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibncat

/* Append SRC on the end of DEST.  */

char *strlibncat(char *_dst, const char *_src, size_t _max)
{
    _dst = (char *)realloc(_dst, strlen(_dst) + strnlen(_src, _max) + 1);

    strncat(_dst, _src, _max);

    return _dst;
}