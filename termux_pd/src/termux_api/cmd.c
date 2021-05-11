/**
 * 作者:苏梦凡
 * target:cmd
 * **/
/*include-------------------------------------------*/
#include "cmd.h"

/*function------------------------------------------*/

char *cmdcat(char *const ptr, const char *const str)
{
    size_t len = strlen(ptr);
    len += strlen(str) + 1;

    char *newptr = NULL;
    newptr = realloc(ptr, len);

    if (newptr == NULL)
    {
        perror(str);
        exit(EXIT_FAILURE);
    }

    strcat(newptr, str);

    return newptr;
}

char *cmdstr(const char *const str)
{
    if (str == NULL)
        return NULL;

    char *cmdin = (char *)calloc(1, sizeof(char));

    size_t j = 0;
    for (size_t i = 0; str[i]; i++)
    {
        if (str[i] == '\'')
        {
            cmdin = realloc(cmdin, j + 2);
            cmdin[j++] = '\'';
        }

        cmdin = realloc(cmdin, j + 2);
        cmdin[j++] = str[i];
    }

    cmdin[j] = '\0';

    return cmdin;
}

int cmdno(const char *const cmd)
{

#ifdef CMD_SHOW
    printf("%s\n", cmd);
#endif

    char buff[BUFSIZ] = {};

    FILE *pipe = popen(cmd, "r");

    if (pipe == NULL)
    {
        perror(cmd);
        return -1;
    }

    while (!feof(pipe))
        fgets(buff, BUFSIZ, pipe);

    pclose(pipe);

    return 0;
}

char *cmd(const char *const cmd)
{

#ifdef CMD_SHOW
    printf("%s\n", cmd);
#endif

    FILE *pipe = popen(cmd, "r");

    if (pipe == NULL)
    {
        perror(cmd);
        return NULL;
    }

    char *str = (char *)calloc(1, sizeof(char));

    size_t i = 0;
    while (1)
    {
        char ch = fgetc(pipe);

        if (feof(pipe))
            break;

        str = realloc(str, i + 2);
        str[i++] = ch;
    }

    str[i] = '\0';
    fflush(pipe);

    pclose(pipe);

    return str;
}

