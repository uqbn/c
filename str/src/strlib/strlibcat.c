#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibcat

/* Append SRC on the end of DEST.  */

char *strlibcat(char *_dst, const char *_src)
{
    _dst = (char *)realloc(_dst, strlen(_dst) + strlen(_src) + 1);

    strcat(_dst, _src);

    return _dst;
}