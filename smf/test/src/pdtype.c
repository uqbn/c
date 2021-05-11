#include "passowrd.h"

char *typestr(Pd_type type)
{
    switch (type)
    {
    case PD_ALPHA:
        return "alpha";
    case PD_LOWER:
        return "lower";
    case PD_UPPER:
        return "upper";
    case PD_PUNCT:
        return "punct";
    case PD_DIGIT:
        return "digit";
    case PD_GRAPH:
        return "graph";
    case PD_PRINT:
        return "print";
    case PD_XDIGIT:
        return "xdigit";
    default:
        return "alnum";
    }
}

char *fgetstr(FILE *fp, char flag)
{
    char *str = malloc(sizeof(char));

    size_t i = 0;
    for (; i < BUFSIZ;)
    {
        char ch = (char)getc(fp);
        if (feof(fp))
            break;

        if (ch == flag || ch == '\n')
            break;

        str = realloc(str, i + 2);
        str[i++] = ch;
    }

    str[i] = '\0';

    return str;
}
