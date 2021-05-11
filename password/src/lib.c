#include "smf.h"

FILE *rfile(char *filename)
{
    FILE *fp = NULL;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror(__FUNCTION__);
        exit(1);
    }
    return fp;
}

FILE *wfile(char *filename)
{
    FILE *fp = NULL;
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        perror(__FUNCTION__);
        exit(1);
    }
    return fp;
}

Pass *callpass(int n)
{
    Pass *p = calloc(n, sizeof(Pass));
    if (p == NULL)
    {
        perror(__FUNCTION__);
        exit(1);
    }
    return p;
}
Node *callnode(int n)
{
    Node *p = calloc(n, sizeof(Node));
    if (p == NULL)
    {
        perror(__FUNCTION__);
        exit(1);
    }
    return p;
}

void freepass(Pass *phead)
{
    if (phead == NULL)
        return;
    freepass(phead->pnext);
    free(phead);
    return;
}