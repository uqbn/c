#include <stdio.h>
#include <stdlib.h>
#include "cmdlib.h"

#undef cmdargstr

char *cmdargstr(const char *_str)
{
    if (_str == NULL)
        return NULL;

    char *cmdarg = NULL;

    size_t j = 0;
    for (size_t i = 0; _str[i]; i++)
    {
        if (!i)
            cmdarg = (char *)malloc(sizeof(char));

        if (_str[i] == '\'')
        {
            cmdarg = realloc(cmdarg, j + 2);
            cmdarg[j++] = '\'';
        }

        cmdarg = realloc(cmdarg, j + 2);
        cmdarg[j++] = _str[i];
    }

    cmdarg[j] = '\0';

    return cmdarg;
}
