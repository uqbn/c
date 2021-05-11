#include "smf.h"

Node *createnode(Pass *pass)
{
    Node *p = callnode(1);
    p->pass = pass;
    p->pleft = NULL;
    p->pright = NULL;
    return p;
}

Node *addnode(Node *proot, Pass *pass)
{
    if (proot == NULL)
        return createnode(pass);
    if (strcmp(pass->name, proot->pass->name) < 0)
    {
        if (proot->pleft == NULL)
        {
            proot->pleft = createnode(pass);
            return proot->pleft;
        }
        else
            return addnode(proot->pleft, pass);
    }
    else if (strcmp(pass->name, proot->pass->name) > 0)
    {
        if (proot->pright == NULL)
        {
            proot->pright = createnode(pass);
            return proot->pright;
        }
        else
            return addnode(proot->pright, pass);
    }
    else
    {
        if (strcmp(proot->pass->password, pass->password) == 0 && proot->pass->type == pass->type) // && proot->pass->len == pass->len
            return NULL;
        fflush(stdin);
        printf("0|%-4s %-6s %-20s %-20s \n", "TYPE", "LENGTH", "PASSWORD", "NAME");
        printf("1|%-4d %-6d %-20s %-20s \n", proot->pass->type, proot->pass->len, proot->pass->password, proot->pass->name);
        printf("2|%-4d %-6d %-20s %-20s \n", pass->type, pass->len, pass->password, pass->name);
        printf("OVERWRITE[y/N]:");
        if (tolower(getchar()) == 'y')
        {
            proot->pass = pass;
            return proot;
        }
        return NULL;
    }
}

void freenode(Node *proot)
{
    if (proot == NULL)
        return;
    if (proot->pleft)
        freenode(proot->pleft);
    if (proot->pright)
        freenode(proot->pright);
    free(proot->pass);
    free(proot);

    return;
}

void wnode(FILE *fp, Node *proot)
{
    if (proot == NULL)
        return;
    if (proot->pleft)
        wnode(fp, proot->pleft);

    char buff1[BUFSIZ] = {};
    encrypt(buff1, proot->pass->password, strlen(proot->pass->password));
    fprintf(fp, "%d|%d|%s|%s|", proot->pass->type, proot->pass->len, buff1, proot->pass->name);

    if (proot->pright)
        wnode(fp, proot->pright);

    return;
}

Node *rnode(char *filename)
{
    FILE *fp = rfile(filename);
    Pass *p = NULL;
    Node *pnode = NULL;
    int mark = 1;
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
        rstr(p->name, fp);
        if (mark)
        {
            mark = 0;
            pnode = addnode(pnode, p);
        }
        else
            addnode(pnode, p);
    }
    fclose(fp);
    return pnode;
}

void sort(char *filename)
{
    Node *pnode = rnode(filename);
    FILE *fp = wfile(filename);
    wnode(fp, pnode);
    freenode(pnode);
    fclose(fp);
    fp = NULL;
    return;
}