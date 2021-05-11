#include "smf.h"

int initdir(char *dir)
{
    char buff[BUFSIZ] = {};
    sprintf(buff, "mkdir %s", dir);
    if (NULL == opendir(dir))
    {
        system(buff);
        if (NULL == opendir(dir))
        {
            printf("INITDIR ERROR!\n");
            exit(1);
        }
    }
    return 0;
}

void timename(char *buff, int n, char *filename)
{
    time_t time0 = 0;
    time(&time0);
    struct tm *infotime = localtime(&time0);
    char tempstr[NAME_LEN] = {};
    sprintf(tempstr, "%s.%%Y-%%m-%%d-%%H-%%M-%%S", filename);
    strftime(buff, n, tempstr, infotime);
    return;
}

void backup(char *filename, char *dir)
{
    initdir(dir);
    char tempname[NAME_LEN] = {};
    char buff[NAME_LEN] = {};
    timename(tempname, NAME_LEN, filename);
    strncpy(buff, dir, NAME_LEN - 1);
    strncat(buff, "/", 2);
    strncat(buff, tempname, strlen(buff) - strlen(tempname) > 0 ? strlen(buff) - strlen(tempname) : 0);

    Pass *phead = rpass(filename);
    wpass(buff, phead);
    freepass(phead);
    phead = NULL;

    return;
}