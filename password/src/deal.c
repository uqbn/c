#include "smf.h"

Pass *initpass()
{
    Pass *p = callpass(1);
    strcpy(p->name, "NAME");
    strcpy(p->password, "PASSWORD");
    p->pnext = NULL;
    return p;
}

int addpass(Pass *phead, Pass *pbody)
{
    Pass *p = phead;
    Pass *p2 = pbody;
    while (p->pnext != NULL)
    {
        p = p->pnext;
    }
    if (strcmp(pbody->name, "NAME") == 0)
    {
        p2 = pbody->pnext;
        free(pbody);
    }
    p->pnext = p2;
    return 1;
}

int delpass(Pass *phead, char *name)
{
    Pass *p = phead;
    Pass *pre = phead;
    int count = 0;
    while (p != NULL)
    {
        if (strncmp(p->name, name, NAME_LEN - 1) == 0)
        {
            free(pre->pnext);
            pre->pnext = p->pnext;
            count++;
        }
        pre = p;
        p = p->pnext;
    }
    return count;
}

Pass *findpass(Pass *phead, char *name)
{
    Pass *p = phead;
    Pass *ptable = NULL;
    Pass *ptemp = NULL;
    int mark = 1;
    while (p != NULL)
    {
        if (strstr(p->name, name) != NULL)
        {
            if (mark)
            {
                ptable = initpass();
                mark = 0;
            }
            ptemp = callpass(1);
            *ptemp = *p;
            ptemp->pnext = NULL;
            addpass(ptable, ptemp);
        }
        p = p->pnext;
    }
    return ptable;
}

int editpass(Pass *phead, char *name)
{
    Pass *p = phead;
    while (p != NULL)
    {
        if (strcmp(p->name, name) == 0)
        {
            inputpass(p->password, p->len, p->type);
        }
        p = p->pnext;
    }
    return 0;
}

Pass *inputpassn(int n)
{
    Pass *p = initpass();
    Pass *ptemp = NULL;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        ptemp = callpass(1);
        ptemp->pnext = NULL;
        ptemp->type = inputi("TYPE:");
        ptemp->len = inputi("LEN:");
        inputstr("NAME:", ptemp->name, NAME_LEN);
        inputpass(ptemp->password, ptemp->len, ptemp->type);
        addpass(p, ptemp);
    }
    return p;
}

int display(Pass *phead, int n)
{
    Pass *p = phead;
    int i = 0;
    if (p == NULL)
        return 0;
    if (strcmp(p->name, "NAME") == 0)
    {
        printf("%-4s %-6s %-20s %-20s\n", "TYPE", "LENGTH", p->password, p->name);
        p = p->pnext;
    }
    for (i = 0; p != NULL && i < n; i++)
    {
        printf("%-4d %-6d %-20s %-20s\n", p->type, p->len, p->password, p->name);
        p = p->pnext;
    }
    return i;
}

int displaytype(Pass *phead, int n, int type)
{
    Pass *p = phead;
    int i = 0;
    if (p == NULL)
        return 0;
    if (strcmp(p->name, "NAME") == 0)
    {
        printf("%-4s %-6s %-20s %-20s\n", "TYPE", "LENGTH", p->password, p->name);
        p = p->pnext;
    }
    for (i = 0; p != NULL && i < n;)
    {
        if (p->type == type)
        {
            printf("%-4d %-6d %-20s %-20s\n", p->type, p->len, p->password, p->name);
            i++;
        }
        p = p->pnext;
    }
    return i;
}

int wpass(char *filename, Pass *phead)
{
    if (phead == NULL)
        return 0;
    FILE *fp = wfile(filename);
    Pass *p = phead;
    int i = 0;
    if (strcmp(p->name, "NAME") == 0)
    {
        p = p->pnext;
    }
    for (i = 0; p != NULL; i++)
    {
        char buff1[BUFSIZ] = {};
        encrypt(buff1, p->password, strlen(p->password));
        fprintf(fp, "%d|%d|%s|%s|", p->type, p->len, buff1, p->name);
        p = p->pnext;
    }
    fclose(fp);
    return i;
}

Pass *rpass(char *filename)
{
    FILE *fp = rfile(filename);
    Pass *phead = initpass();
    Pass *p = NULL;
    while (1)
    {
        p = callpass(1);
        p->pnext = NULL;
        if (EOF == fscanf(fp, "%d|%d|", &p->type, &p->len))
        {
            free(p);
            p = NULL;
            break;
        }
        char buff1[BUFSIZ] = {};
        rstr(buff1, fp);
        dncrypt(p->password, buff1, strlen(buff1));
        addpass(phead, p);
        rstr(p->name, fp);
    }
    fclose(fp);
    return phead;
}

int nexists(Pass *phead, char *name)
{
    Pass *p = phead;
    while (p != NULL)
    {
        if (strcmp(name, p->name) == 0)
            return 1;
        p = p->pnext;
    }
    return 0;
}

char num(int n)
{
    char ch = '0';
    for (int i = 0; i < n; i++)
    {
        if (ch == '9')
            ch = '0';
        else
            ch++;
    }
    return ch;
}

char alnum(int n)
{
    char ch = '0';
    for (int i = 0; i < n; i++)
    {
        if (ch == '9')
            ch = 'A';
        else if (ch == 'Z')
            ch = 'a';
        else if (ch == 'z')
            ch = '0';
        else
            ch++;
    }
    return ch;
}

char alnum2(int n)
{
    char ch = '!';
    for (int i = 0; i < n; i++)
    {
        if (ch == 'z')
            ch = '!';
        else
            ch++;
    }
    return ch;
}

int createpass(char *buff, int len, int type)
{
    int i = 0;
    char ch = '\0';
    int min = len > (PASS_LEN - 1) ? (PASS_LEN - 1) : len;
    srand((unsigned)time(NULL));
    for (i = 0; i < min; i++)
    {
        ch = '\0';
        if (type == 2)
        {
            ch = num(rand() % 10);
        }
        else if (type == 3)
        {
            ch = alnum2(rand() % 89);
        }
        else
        {
            ch = alnum(rand() % 62);
        }

        buff[i] = ch;
    }
    return i;
}