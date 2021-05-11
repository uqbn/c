#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#if WINNT || WIN64 || WIN32 || __WINNT__
#include <conio.h>
#else
#include <termio.h>
int getch(void)
{
    struct termios tm, tm_old;
    int fd = 0, ch;

    if (tcgetattr(fd, &tm) < 0)
    { //保存现在的终端设置
        return -1;
    }

    tm_old = tm;
    cfmakeraw(&tm); //更改终端设置为原始模式，该模式下所有的输入数据以字节为单位被处理
    if (tcsetattr(fd, TCSANOW, &tm) < 0)
    { //设置上更改之后的设置
        return -1;
    }

    ch = getchar();
    if (tcsetattr(fd, TCSANOW, &tm_old) < 0)
    { //更改设置为最初的样子
        return -1;
    }

    return ch;
}
#endif

int keygets(char *buff, size_t n)
{
    size_t i = 0;
    while (i < n)
    {
        int ch = getch();
        if (ch == 13) //回车键结束输入
        {
            buff[i] = '\0';
            break;
        }
        else if (ch == 0) //gbk
        {
            char ch2 = getch();
            if (ch2 == 75) //方向键 左
                printf("\033[1D");
            else if (ch2 == 77) //方向键 右
                printf("\033[1C");
            else if (ch2 == 72) //方向键 上
                printf("\033[1A");
            else if (ch2 == 80) //方向键 下
                printf("\033[1B");
            else if (ch2 == 83) //删除
                printf("del\n");
            else if (ch2 == 71) //家
                printf("home\n");
            else if (ch2 == 79) //最后
                printf("page end\n");
            else if (ch2 == 73) //上一页
                printf("page up\n");
            else if (ch2 == 81) //下一页
                printf("down\n");
            else
                printf("%d\n", ch2);
        }
        else if (ch == 27) //utf-8
        {
            char ch2 = getch();
            if (ch2 == 91)
            {
                char ch3 = getch();
                if (ch3 == 68) //方向键 左
                    printf("\033[1D");
                else if (ch3 == 67) //方向键 右
                    printf("\033[1C");
                else if (ch3 == 65) //方向键 上
                    printf("\033[1A");
                else if (ch3 == 66) //方向键 下
                    printf("\033[1B");
                else if (ch3 == 72) //家
                    printf("home\n");
                else if (ch3 == 70) //结束
                    printf("end\n");
                else if (ch3 == 53) //上一页
                {
                    getch();
                    printf("page up\n");
                }
                else if (ch3 == 54) //下一页
                {
                    getch();
                    printf("page down\n");
                }
                else if (ch3 == 51) //删除
                {
                    getch();
                    printf("del\n");
                }
                else
                    printf("%d\n", ch3);
            }
            else
            {
                ungetc(ch2, stdin); //退出
                printf("esc\n");
            }
        }
        else if (ch == 9)
        {
        }
        else
        {
            putchar(ch);
            printf("|%d\n", ch);
        }
    }

    return i;
}

int main(void)
{
    char buff[BUFSIZ] = {};
    keygets(buff, BUFSIZ);
    printf(buff);
    return 0;
}