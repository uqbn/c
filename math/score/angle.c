#include "angle.h"

Decimal angletodecimal(Angle angle)
{
    Decimal score = {.a = abs(angle.c) + abs(angle.b) * 60 + abs(angle.a) * 3600, .b = 3600};

    if (angle.a < 0)
        score.a *= -1;

    return decimalmin(score);
}

Angle decimacltoangle(Decimal score)
{
    Angle angle;

    score = decimalmin(score);

    score.a *= 3600.0 / score.b;

    angle.c = (int)fabs(score.a) % 60;
    angle.b = (int)fabs(score.a) / 60 % 60;
    angle.a = score.a / 60 / 60;

    return angle;
}

Angle angleadd(Angle angle1, Angle angle2)
{
    Decimal score1 = angletodecimal(angle1);
    Decimal score2 = angletodecimal(angle2);

    return decimacltoangle(decimaladd(score1, score2));
}

Angle anglesub(Angle angle1, Angle angle2)
{
    Decimal score1 = angletodecimal(angle1);
    Decimal score2 = angletodecimal(angle2);

    return decimacltoangle(decimalsub(score1, score2));
}

Angle anglemul(Angle angle1, Angle angle2)
{
    Decimal score1 = angletodecimal(angle1);
    Decimal score2 = angletodecimal(angle2);

    return decimacltoangle(decimalmul(score1, score2));
}

Angle anglediv(Angle angle1, Angle angle2)
{
    Decimal score1 = angletodecimal(angle1);
    Decimal score2 = angletodecimal(angle2);

    return decimacltoangle(decimaldiv(score1, score2));
}

double anglecc(Angle angle)
{
    return decimalcc(angletodecimal(angle));
}

double anglei(Angle angle)
{
    return anglecc(angle) / 180 * M_PI;
}

double anglepow(Angle angle, Decimal p)
{
    return pow(decimalcc(angletodecimal(angle)), decimalcc(p));
}

//#define MAIN
#ifdef MAIN
int main(int argc, char *argv[])
{
    Angle angle1 = {.a = 0, .b = 0, .c = 0};
    Angle angle2 = {.a = 0, .b = 0, .c = 0};
    Angle angle;

    if (argc == 7)
    {
        angle1.a = atoi(argv[1]);
        angle1.b = atoi(argv[2]);
        angle1.c = atoi(argv[3]);
        angle2.a = atoi(argv[4]);
        angle2.b = atoi(argv[5]);
        angle2.c = atoi(argv[6]);
    }
    else if (argc == 5)
    {
        angle1.a = atoi(argv[1]);
        angle1.b = atoi(argv[2]);
        angle2.a = atoi(argv[3]);
        angle2.b = atoi(argv[4]);
    }
    else if (argc == 3)
    {
        angle1.a = atoi(argv[1]);
        angle2.a = atoi(argv[2]);
    }

    if (argc > 1 && argc % 2)
    {
        angle1 = decimacltoangle(angletodecimal(angle1));
        angle2 = decimacltoangle(angletodecimal(angle2));

        printf("\r1: %+d°%02d′%02d″\t%+g°\n", angle1.a, angle1.b, angle1.c, anglecc(angle1));
        printf("2: %+d°%02d′%02d″\t%+g°\n", angle2.a, angle2.b, angle2.c, anglecc(angle2));

        angle = angleadd(angle1, angle2);
        printf("+: %+d°%02d′%02d″\t%+g°\n", angle.a, angle.b, angle.c, anglecc(angle));

        angle = anglesub(angle1, angle2);
        printf("-: %+d°%02d′%02d″\t%+g°\n", angle.a, angle.b, angle.c, anglecc(angle));

        angle = anglemul(angle1, angle2);
        printf("*: %+d°%02d′%02d″\t%+g°\n", angle.a, angle.b, angle.c, anglecc(angle));

        angle = anglediv(angle1, angle2);
        printf("/: %+d°%02d′%02d″\t%+g°\n", angle.a, angle.b, angle.c, anglecc(angle));

        printf("^: %+g°\t%+g°\n", anglepow(angle1, angletodecimal(angle2)), anglei(angle));
    }
    else
    {
        printf("\rmissing number\n");
    }

    return 0;
}

#undef MAIN
#endif
