#include "smf.h"

int inputi(char *infor)
{
    int n = 0;
    int count = 0;
    do
    {
        fflush(stdin);
        printf("%s", infor);
        count = scanf(" %d", &n);
        if (count != 1)
            while ('\n' != getchar())
                ;
        fflush(stdin);
    } while (n <= 0 || count != 1);
    return n;
}

int inputstr(char *infor, char *str, int n)
{
    int i = 0;
    fflush(stdin);
    printf("%s", infor);
    for (i = 0; i < n; i++)
    {
        str[i] = (char)getchar();
        if (str[i] == '\n' && i != 0)
        {
            str[i] = '\0';
            break;
        }
        else if (str[0] == '\n')
            i--;
    }
    if (i == n)
        str[i - 1] = '\0';
    fflush(stdin);
    return i;
}

int inputpass(char *pass, int len, int type)
{
    int i = 0;
    int mark = 0;
    char ch = '\0';
    fflush(stdin);
    if (type == 2)
        printf("%d\tdigital\n", len);
    else if (type == 3)
        printf("%d\tchar\n", len);
    else
        printf("%d\tletter+digital\n", len);
    printf("PASSWORD:");
    for (i = 0; i < len;)
    {
        ch = (char)getchar();
        if (ch == '\n' && i != 0) //如果是回车键
        {
            pass[i] = '\0'; //结束字符
            break;          //跳出循环
        }
        if (type == 2 && isdigit(ch))
            mark = 1;
        else if (type == 3)
            mark = 1;
        else if (isalnum(ch)) //type == 1 &&
            mark = 1;
        if (mark)
        {
            mark = 0;
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    fflush(stdin);
    return i;
}

int delch(char *pstr, char ch)
{
    int i = 0;
    for (int j = 0; pstr[j] != '\0'; j++)
    {
        if (pstr[j] != ch)
        {
            pstr[i] = pstr[j];
            i++;
        }
    }
    pstr[i] = '\0';
    return i;
}

int delch2(char *pstr)
{
    int i = 0;
    for (int j = 0; pstr[j] != '\0'; j++)
    {
        if (j != 1)
        {
            pstr[i] = pstr[j];
            i++;
        }
    }
    pstr[i] = '\0';
    return i;
}

/*
int inputpass(char *pass, int len, int type)
{
    int i = 0;
    int mark = 0;
    char ch = '\0';
    printf("PASSWORD:");
    for (i = 0; i < len;)
    {
        ch = (char)_getch();
        if (ch == '\r') //如果是回车键
        {
            pass[i] = '\0'; //结束字符
            break;          //跳出循环
        }
        if (ch == '\b' && i > 0) //如果是backspace键，并且光标没有到最开始的位置
        {
            printf("%s", "\b \b"); //光标显示退后一个
            if (i > 0)             //光标没有到最开始的位置
                i--;               //上一个字符
        }
        if (type == 0 && isalnum(ch))
            mark = 1;
        else if (type == 1 && isdigit(ch))
            mark = 1;
        else if (type == 2)
            mark = 1;
        if (mark)
        {
            mark = 0;
            putchar(ch);
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    putchar('\n');
    return i;
}*/

int rstr(char *buff, FILE *fp)
{
    char ch = '\0';
    int i = 0;
    for (i = 0;; i++)
    {
        ch = (char)fgetc(fp);
        if (feof(fp))
            return 0;
        if (ch == '\n' || ch == '|')
        {
            if (i != 0)
            {
                buff[i] = '\0';
                break;
            }
        }
        buff[i] = ch;
    }
    return i;
}