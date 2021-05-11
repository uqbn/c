#include "decimal.h"

#undef decimalc

Decimal decimalc(Decimal _m, Decimal _n)
{
    if (decimalcc(_m) < decimalcc(_n))
    {
        Decimal temp = {.a = 0, .b = 1};
        return temp;
    }

    return decimaldiv(decimala(_m, _n), decimala(_n, _n));
}
