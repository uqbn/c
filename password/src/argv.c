#include "smf.h"

int argvis(int argc, char *argv[], int *pnum, int *pi)
{
    if (*pi < argc)
    {
        int i = atoi(argv[*pi]);
        if (i > 0)
        {
            *pnum = i;
            return 1;
        }
        else
            *pi -= 1;
    }
    return 0;
}

int argvnames(int argc, char *argv[], char *name, int *pi, char *infor)
{
    if (*pi < argc)
    {
        if (argv[*pi][0] == '-')
            *pi -= 1;
        else
        {
            strncpy(name, argv[*pi], NAME_LEN - 1);
            return 1;
        }
    }
    return 0;
}

int argvpass(int argc, char *argv[], char *pass, int create_len, int pass_type, int *pi)
{
    if (*pi == argc)
    {
        inputpass(pass, create_len, pass_type);
        return 1;
    }
    if (argv[*pi][0] == '-')
    {
        inputpass(pass, create_len, pass_type);
        *pi -= 1;
    }
    else
    {
        strncpy(pass, argv[*pi], PASS_LEN - 1);
        return 1;
    }
    return 0;
}

int argvname(int argc, char *argv[], char *name, int *pi, char *infor)
{
    if (*pi == argc)
    {
        inputstr(infor, name, NAME_LEN);
        return 1;
    }
    if (argv[*pi][0] == '-')
    {
        inputstr(infor, name, NAME_LEN);
        *pi -= 1;
    }
    else
    {
        strncpy(name, argv[*pi], NAME_LEN - 1);
        return 1;
    }
    return 0;
}

int argvi(int argc, char *argv[], int *pnum, int *pi, char *infor)
{
    if (*pi == argc)
    {
        *pnum = inputi(infor);
        return 1;
    }
    if (argv[*pi][0] == '-')
    {
        *pnum = inputi(infor);
        *pi -= 1;
    }
    else
    {
        int i = atoi(argv[*pi]);
        if (i > 0)
        {
            *pnum = i;
            return 1;
        }
    }
    return 0;
}