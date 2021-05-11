#ifndef __DECIMAL_H__
#define __DECIMAL_H__

//typedef long long Decimal_t;
typedef double Decimal_t;

typedef struct Decimal
{
    Decimal_t a;
    Decimal_t b;
} Decimal;

Decimal decimalmin(Decimal _score);
Decimal decimaladd(Decimal _score1, Decimal _score2);
Decimal decimalsub(Decimal _score1, Decimal _score2);
Decimal decimalmul(Decimal _score1, Decimal _score2);
Decimal decimaldiv(Decimal _score1, Decimal _score2);
Decimal decimalpow(Decimal _score, Decimal _p);
Decimal decimala(Decimal _m, Decimal _n);
Decimal decimalc(Decimal _m, Decimal _n);
Decimal decimale(Decimal _m, Decimal _n);

double decimalcc(Decimal _score);

#endif