#include <stdio.h>
#include <stdlib.h>
#include "cmdlib.h"

#undef cmdrno

int cmdrno(const char *_cmd)
{
    char buff[BUFSIZ] = {};

    FILE *pipe = popen(_cmd, "r");

    if (pipe == NULL)
    {
        perror(_cmd);
        return -1;
    }

    do
    {
        fgets(buff, BUFSIZ, pipe);
    } while (!feof(pipe));
    fflush(pipe);

    pclose(pipe);

    return 0;
}