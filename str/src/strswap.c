#include "str.h"

#undef strswap

static void swapc(char *_ch1, char *_ch2)
{
    char ch = *_ch1;
    *_ch1 = *_ch2;
    *_ch2 = ch;

    return;
}

int strswap(char *_str, size_t _index1, size_t _len1, size_t _index2, size_t _len2)
{
    size_t min = _len1 < _len2 ? _len1 : _len2;
    size_t max = _len1 > _len2 ? _len1 : _len2;
    size_t i = 0;

    for (i = 0; i < min; i++)
        swapc(_str + _index1++, _str + _index2++);

    return 0;
}