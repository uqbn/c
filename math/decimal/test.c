#include <stdio.h>
#include <stdlib.h>
#include "decimal.h"

int main(int argc, char *argv[])
{
    Decimal score;
    Decimal score1 = {.a = 0, .b = 1};
    Decimal score2 = {.a = 0, .b = 1};

    if (argc == 5)
    {
        score1.a = atof(argv[1]);
        score1.b = atof(argv[2]);
        score2.a = atof(argv[3]);
        score2.b = atof(argv[4]);
    }
    else if (argc == 3)
    {
        score1.a = atof(argv[1]);
        score2.a = atof(argv[2]);
    }

    if (argc > 1 && argc % 2)
    {
        score1 = decimalmin(score1);
        score2 = decimalmin(score2);

        printf("\r1: %+g/%g\t%+g\n", score1.a, score1.b, decimalcc(score1));
        printf("2: %+g/%g\t%+g\n", score2.a, score2.b, decimalcc(score2));

        score = decimaladd(score1, score2);
        printf("+: %+g/%g\t%+g\n", score.a, score.b, decimalcc(score));

        score = decimalsub(score1, score2);
        printf("-: %+g/%g\t%+g\n", score.a, score.b, decimalcc(score));

        score = decimalmul(score1, score2);
        printf("*: %+g/%g\t%+g\n", score.a, score.b, decimalcc(score));

        score = decimaldiv(score1, score2);
        printf("/: %+g/%g\t%+g\n", score.a, score.b, decimalcc(score));

        score = decimalpow(score1, score2);
        printf("^: %+g/%g\t%+g\n", score.a, score.b, decimalcc(score));

        score = decimala(score1, score2);
        printf("A: %+g/%g\t%+g\n", score.a, score.b, decimalcc(score));

        score = decimalc(score1, score2);
        printf("C: %+g/%g\t%+g\n", score.a, score.b, decimalcc(score));
    }
    else
    {
        printf("\rmissing number\n");
    }

    return 0;
}