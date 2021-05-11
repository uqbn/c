#include <strlib.h>
#include <string.h>
#include "strlib.h"

#undef strlibcpy

/* Copy SRC to DEST.  */

char *strlibcpy(char *_dst, const char *_src)
{
    _dst = (char *)realloc(_dst, strlen(_src) + 1);

    strcpy(_dst, _src);

    return _dst;
}
