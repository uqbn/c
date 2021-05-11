#include <stdio.h>
#include "expcc.h"

static const char tabop[OPLEN][4] = {"+", "-", "*", "/", "e", "**", "!", "_"};
static const int tabopp[OPLEN] = {1, 1, 2, 2, 4, 4, 3, 3};

int main(int argc, char *argv[])
{
    for (size_t i = 1; i < argc; i++)
    {
        Decimal result = expcc(argv[i]);
        printf(" = %g %g/%g\n", decimalcc(result), result.a, result.b);
    }

    if (argc > 1)
        return 0;

    printf("q cancel,c clear,h help\n");

    char buff[BUFSIZ] = {};
    Decimal num;

    for (size_t i = 0; i < OPLEN; i++)
    {
        printf("%-2s ", tabop[i]);
    }
    putchar('\n');
    for (size_t i = 0; i < OPLEN; i++)
    {
        printf("%-2d ", tabopp[i]);
    }
    putchar('\n');

    while (1)
    {
        printf(">> ");

        fgets(buff, BUFSIZ, stdin);
        buff[strlen(buff) - 1] = '\0';

        if (!strcmp(buff, "q"))
            break;
        else if (!strcmp(buff, "c"))
        {
            system("clear");
            continue;
        }
        else if (!strcmp(buff, "h"))
        {
            printf("1 + 1e-1 = 11/10\n1e1 - 1 = 9\n2 / 3 * -2 = -4/3\n2 / -2** -2 = 8\n0x10 ** (-1 / 4) = 1/2\n4 ! 2 ** 2 = 24\n4 _ 3 = 4\n");
            continue;
        }
        else if (!strcmp(buff, "") || isalpha(buff[0]))
            continue;

        num = expcc(buff);

#ifdef SHOW
        printf(" = ");
#endif

        printf("%g\t%g/%g\n", decimalcc(num), num.a, num.b);
    }

    return 0;
}