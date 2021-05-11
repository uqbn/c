#include "smf.h"

int import(char *filename1, char *filename2)
{
    Pass *p1 = rpass(filename1);
    Pass *p2 = rpass(filename2);
    addpass(p1, p2);
    wpass(filename1, p1);
    freepass(p1);
    return 0;
}

int add(char *filename, int type, int len, char *name, char *pass)
{
    Pass *phead = rpass(filename);
    Pass *p = callpass(1);
    int i = 0,
        j = 0,
        mark = 0;
    p->type = type;
    p->len = len;
    p->pnext = NULL;
    for (i = 0, j = 0; j < len && pass[j] != '\0'; j++)
    {
        if (type == 2 && isdigit((int)pass[j]))
            mark = 1;
        else if (type == 3)
            mark = 1;
        else if (isalnum((int)pass[j])) //type == 1 &&
            mark = 1;

        if (mark)
        {
            mark = 0;
            p->password[i] = pass[j];
            i++;
        }
    }
    if (strncmp(p->password, pass, len) != 0)
    {
        printf("TYPE ERROR!\n");
        freepass(p);
        exit(0);
    }
    while (nexists(phead, name))
    {
        printf("%s EXIST!\n", name);
        inputstr("NEW:", name, NAME_LEN);
    }
    strcpy(p->name, name);
    addpass(phead, p);
    i = wpass(filename, phead);
    printf("%s\n", p->password);
    freepass(phead);
    return i;
}

int del(char *filename, char *name)
{
    Pass *phead = rpass(filename);
    int mark = 0;
    if (nexists(phead, name))
    {
        delpass(phead, name);
        wpass(filename, phead);
        mark = 1;
    }
    else
    {
        mark = 0;
    }
    freepass(phead);
    phead = NULL;
    return mark;
}

int find(char *filename, char *name, int n)
{
    Pass *phead = rpass(filename);
    Pass *p = findpass(phead, name);
    int i = 0;
    i = display(p, n);
    freepass(phead);
    freepass(p);
    return i;
}

int show(char *filename, int n, int type, int type_mark)
{
    Pass *phead = rpass(filename);
    int i = 0;
    if (type_mark == 1)
        displaytype(phead, n, type);
    else
        display(phead, n);
    freepass(phead);
    return i;
}