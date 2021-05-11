#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int getpwd(char *buff, char *bin)
{
    size_t n = strlen(bin);
    size_t i = n;
    int mark = 0;

    while (i--)
    {
        if (bin[i] == '/')
        {
            mark = 1;
            break;
        }
        else if (bin[i] == '\\')
        {
            mark = -1;
            break;
        }
    }

    buff[i + 1] = '\0';

    for (;; i--)
    {
        buff[i] = bin[i];
        if (i == 0)
            break;
    }

    return mark;
}

int ungets(char *str, FILE *fp)
{
    size_t i = strlen(str);

    while (i--)
    {
        ungetc(str[i], fp);

        if (i == 0)
            break;
    }

    return 0;
}

int isnum(char *str)
{
    double temp = 0;
    return sscanf(str, "%lf", &temp);
}

void showps(int op)
{
    printf("\r");

    if (op == 0)
        putchar('d');
    else if (op == 1)
        putchar('a');
    else if (op == 2)
        putchar('p');

    printf("> ");
}

int main(int argc, char *argv[])
{
    char option[8] = {};
    char data[BUFSIZ - 8] = {};
    char pwd[BUFSIZ] = {};
    char buff[BUFSIZ] = {};
    int op = 0;

    getpwd(pwd, argv[0]);
#if WINNT || WIN64 || WIN32 || __WINNT__
    system("chcp 65001");
#endif

    while (1)
    {
        showps(op);

        fgets(data, BUFSIZ - 8, stdin);

        if (!isnum(data))
        {
            sscanf(data, " %s", option);
            if (strcmp(option, "d") == 0)
                op = 0;
            else if (strcmp(option, "a") == 0)
                op = 1;
            else if (strcmp(option, "p") == 0)
                op = 2;
            else if (strcmp(option, "q") == 0)
                exit(0);
            option[0] = '\0';
        }
        else
        {
            switch (op)
            {
            case 0:
                sprintf(buff, "%s%s %s", pwd, "decimal", data);
                break;
            case 1:
                sprintf(buff, "%s%s %s", pwd, "angle", data);
                break;
            case 2:
                sprintf(buff, "%s%s %s", pwd, "prob", data);
                break;
            default:
                break;
            }
        }

        if (option[0] == '\0')
            system(buff);
    }
    return 0;
}
