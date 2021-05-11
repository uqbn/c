#include "decimal.h"

#undef decimalcc

double decimalcc(Decimal _score)
{
    return (double)_score.a / _score.b;
}
