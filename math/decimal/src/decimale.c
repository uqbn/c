#include "decimal.h"

#undef decimale

Decimal decimale(Decimal _m, Decimal _n)
{
    Decimal result = {.a = 10, .b = 1};

    result = decimalpow(result, _n); //**
    result = decimalmul(result, _m); //*

    return result;
}