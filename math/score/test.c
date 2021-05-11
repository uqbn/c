#include <stdio.h>
#define __STDC_WANT_LIB_EXT1__ 1
#include <string.h>
#include "strlib.h"

int main(int argc, char *argv[])
{
    char *str = calloc(1, sizeof(char));
    strlibcpy(str, "345");
    strlibcpy_s(str, 2, "345", 2);
    printf("%s", str);
    free(str);
    return 0;
}