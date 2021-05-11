#include "decimal.h"

#undef decimalsub

Decimal decimalsub(Decimal _score1, Decimal _score2)
{
    Decimal score;

    _score1 = decimalmin(_score1);
    _score2 = decimalmin(_score2);

    score.a = _score1.a * _score2.b - _score1.b * _score2.a;
    score.b = _score1.b * _score2.b;

    return decimalmin(score);
}
