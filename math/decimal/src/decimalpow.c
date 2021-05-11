#include <math.h>
#include "decimal.h"

#undef decimalpow

Decimal decimalpow(Decimal _score, Decimal _p)
{
    double tempdouble = decimalcc(_p);
    if (tempdouble < 0)
    {
        tempdouble = -tempdouble;
        Decimal_t temp = _score.a;
        _score.a = _score.b;
        _score.b = temp;
    }

    _score.a = (Decimal_t)pow(_score.a, tempdouble);
    _score.b = (Decimal_t)pow(_score.b, tempdouble);

    return _score;
}
