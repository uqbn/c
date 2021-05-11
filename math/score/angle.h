#ifndef __ANGLE_H__
#define __ANGLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "decimal.h"

typedef struct Angle
{
    int a;
    int b;
    int c;
} Angle;

Decimal angletodecimal(Angle angle);
Angle decimacltoangle(Decimal score);

Angle angleadd(Angle angle1, Angle angle2);
Angle anglesub(Angle angle1, Angle angle2);
Angle anglemul(Angle angle1, Angle angle2);
Angle anglediv(Angle angle1, Angle angle2);
double anglecc(Angle angle);
double anglepow(Angle angle, Decimal p);

#endif