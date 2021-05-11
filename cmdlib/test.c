#include "cmdlib.h"

int main(int argc, char *argv[])
{
    char *str = cmdr("uname -a");

    printf("%s", str);

    free(str);

    return 0;
}