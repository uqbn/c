#include <stdio.h>
#include "strlib.h"

int main(int argc, char *argv[])
{
    char *str1 = calloc(1, sizeof(char));
    char *str2 = calloc(1, sizeof(char));

    str1 = strlibcat(str1, "1234567890");

    strswap(str1, 1, 2, 4, 4);

    puts(str1);

    free(str1);

    /*
    str1 = strlibdel1(str1, "|");
    puts(str1);
    str1 = strlibdeln(str1, "|", 1);
    puts(str1);
    str1 = strlibdelx(str1, "|", 1);
    puts(str1);

    str1 = strlibmod1(str1, "|", "0");
    puts(str1);
    str1 = strlibrmod1(str1, "0", "0101010101");
    puts(str1);
    str1 = strlibmodx(str1, "0", "", 2);
    puts(str1);
    str1 = strlibrmodn(str1, "0", "", 2);
    puts(str1);
    str1 = strlibmod(str1, "0", "");
    puts(str1);

    free(str1);
    str1 = NULL;
    free(str2);
    str2 = NULL;

    printf("-----------------------------------\n");

    char buff[BUFSIZ] = {};

    strcpy(buff, "1234567890");
    puts(buff);

    strdel1(buff, "1");
    puts(buff);

    strmod1(buff, BUFSIZ, "23", "xxxxxxxxxxxxxxxxxx");
    puts(buff);
*/
    return 0;
}