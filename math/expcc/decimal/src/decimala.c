#include "decimal.h"

#undef decimala

Decimal decimala(Decimal _m, Decimal _n)
{
    Decimal result = {.a = 1, .b = 1};
    int min = decimalcc(_m) <= decimalcc(_n) ? (int)decimalcc(_m) : (int)decimalcc(_n);

    for (int i = 0; i < min; i++)
    {
        Decimal temp = {.a = 1, .b = 1};
        result = decimalmul(result, _m);
        _m = decimalsub(_m, temp);
    }

    return result;
}
