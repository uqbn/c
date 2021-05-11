#include "decimal.h"

#undef decimalmin

static Decimal_t maxfactor(Decimal_t _a, Decimal_t _b);
static Decimal_t maxfactor(Decimal_t _a, Decimal_t _b)
{
    long long temp = 0;

    while ((long long)_b)
    {
        temp = (long long)_a % (long long)_b;
        _a = _b;
        _b = temp;
    }

    return _a;
}

Decimal decimalmin(Decimal _score)
{
    Decimal_t max = maxfactor(_score.a, _score.b);

    if (max)
    {
        _score.a /= max;
        _score.b /= max;
    }

    if (_score.b < 0)
    {
        _score.a = -_score.a;
        _score.b = -_score.b;
    }

    return _score;
}