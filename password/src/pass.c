#include "smf.h"

static unsigned long Next = 1;

void srands(unsigned long seed)
{
    Next = seed;
}

int rands(void)
{
    Next = Next * 1103515245 + 12345;
    return (unsigned)((Next / 65536) % 32768);
}

int encrypt(char *buff, char *pass, int n)
{
    int i = 0;
    char ch = '\0';
    for (i = 0; i < n * 2 && pass[i / 2] != '\0';)
    {
        ch = pass[i / 2];
        srands(ch + i * 3);
        int j = 'z' - '!' + 1;
        buff[i++] = '!' + rands() % j;
        buff[i++] = '!' + rands() % j;
    }
    buff[i] = '\0';
    return i;
}

int dncrypt(char *buff, char *pass, int n)
{
    int i = 0;
    for (i = 0; i < n && pass[i] != '\0'; i++)
    {
        char ch = '!';
        int j = 'z' - '!' + 1;
        while (ch < 'z')
        {
            srands(ch + i * 3);
            if (pass[i] == '!' + rands() % j && pass[i + 1] == '!' + rands() % j)
                break;
            if (ch == 'z')
            {
                printf("DATA ERROR!");
                exit(1);
            }
            ch++;
        }
        buff[i++ / 2] = ch;
    }
    buff[i / 2] = '\0';
    return i;
}

int chtob(char *buff, char *name, int n)
{
    char ch = '\0';
    char temp[10] = {};
    int i = 0;
    for (i = 0; i < n && name[i] != '\0'; i++)
    {
        ch = name[i];
        sprintf(temp, "%X", ch);
        printf("%s", temp);
        strncat(buff, temp, 10);
    }
    return i;
}

int btoch(char *buff, char *name, int n)
{
    int i = 0;
    int num = 0;
    for (i = 0; i < n && name[i] != '\0'; i++)
    {
        char temp[3] = {name[i], name[i + 1], '\0'};
        sscanf(temp, "%X", &num);
        buff[i++ / 2] = (char)num;
    }
    buff[i / 2] = '\0';
    return 0;
}