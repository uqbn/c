#include <stdio.h>

#define MAXLEN BUFSIZ
typedef struct SList
{
    int buffer[MAXLEN];
    int len;
} SList;

void show(SList num)
{
    for (size_t i = 0; i < num.len; i++)
        printf("%i ", num.buffer[i]);
    putchar('\n');
    return;
}

void sort(SList *num)
{
    for (size_t i = 0; i < num->len; i++)
    {
        size_t j = 0;

        while (i + j < num->len && num->buffer[i + j] == 0)
            j++;

        if (j)
        {
            show(*num);
            for (size_t k = i + j; k < num->len; k++)
                num->buffer[k - j] = num->buffer[k];
            num->len -= j;
        }
    }

    return;
}

/**
 * step0:令i=0
 * step1:如果i小于len，进入step2,否则,结束循环;
 * step2:令j=0,如果i+j小于len并且下标为i+j的值为0，j加1，否则,进入step3;
 * step3:如果j大于0，令k=i+j,进入step4，否则，进入step1;
 * step4:如果k小于len，下标为k的值赋给下标为k-j的变量，否则,len减去j，进入step1;
*/

int main(int argc, char *argv[])
{
    SList num = {.buffer = {10, 2, 0, 0, 5, 7, 0, 4, 0, 0}, .len = 10};

    sort(&num);
    show(num);

    return 0;
}