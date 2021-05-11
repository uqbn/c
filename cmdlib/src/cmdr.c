#include <stdio.h>
#include <stdlib.h>
#include "cmdlib.h"

#undef cmdr

char *cmdr(const char *_cmd)
{
    FILE *pipe = popen(_cmd, "r");

    if (pipe == NULL)
    {
        perror(_cmd);
        return NULL;
    }

    char *str = NULL;

    size_t i = 0;
    while (1)
    {
        char ch = fgetc(pipe);

        if (feof(pipe))
            break;

        if (!i)
            str = (char *)malloc(sizeof(char));

        str = realloc(str, i + 2);
        str[i++] = ch;
    }

    str[i] = '\0';
    fflush(pipe);

    pclose(pipe);

    return str;
}
