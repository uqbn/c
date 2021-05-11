#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iconv.h>

static unsigned long Next = 1;
const char *encodetable = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void srands(unsigned long seed)
{
    Next = seed;
}

unsigned rands(void)
{
    Next = Next * 1103515245 + 12345;
    return (unsigned)((Next / 65536) % 32768);
}

char password[1025] = {};

void encrypt(char *buff, char *pass)
{
    int i = 0,
        j = 0;
    int table_n = strlen(encodetable);
    int pass_n = strlen(pass);

    for (; i < 64 * 16; i += 16)
    {
        char ch = '\0';
        int site = -1;
        if (j < pass_n)
        {
            ch = pass[j++];
            site = rand() % 4 * 4;
        }
        for (int k = 0; k < 16;)
        {
            int temp = k + i + 1;
            if (k == site)
            {
                srands(ch);
                temp = 0;
            }
            buff[i + k++] = encodetable[(rands() + temp) % table_n];
            buff[i + k++] = encodetable[(rands() + temp * 2) % table_n];
            buff[i + k++] = encodetable[(rands() + temp * 3) % table_n];
            buff[i + k++] = encodetable[(rands() + temp * 4) % table_n];
        }
    }
    buff[i] = '\0';

    return;
}

int code_convert(char *from_charset, char *to_charset, char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
    iconv_t cd;
    //int rc;
    char **pin = &inbuf;
    char **pout = &outbuf;

    cd = iconv_open(to_charset, from_charset);
    if (cd == 0)
        return -1;
    memset(outbuf, 0, outlen);
    if (iconv(cd, pin, &inlen, pout, &outlen) == -1)
        return -1;
    iconv_close(cd);
    return 0;
}

int u2g(char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
    return code_convert("utf-8", "gb2312", inbuf, inlen, outbuf, outlen);
}

int g2u(char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
    return code_convert("gb2312", "utf-8", inbuf, inlen, outbuf, outlen);
}

void dncrypt(char *buff, char *pass)
{
    int i = 0,
        j = 0;
    int table_n = strlen(encodetable);

    for (; i < 64 * 16; i += 16)
    {
        char ch = '\0';
        for (int k = 0; k < 16; k += 4)
        {
            for (char t = '!'; t <= '~'; t++)
            {
                srands(t);
                if (buff[i + k + 0] == encodetable[rands() % table_n] &&
                    buff[i + k + 1] == encodetable[rands() % table_n] &&
                    buff[i + k + 2] == encodetable[rands() % table_n] &&
                    buff[i + k + 3] == encodetable[rands() % table_n])
                {
                    ch = t;
                    break;
                }
            }
            if (ch != '\0')
                break;
        }
        pass[j++] = ch;
        if (ch == '\0')
            break;
    }
    pass[j] = '\0';
    return;
}

int main(int argc, char *argv[])
{
    char pass[65] = {};
    //encrypt(password, argv[1]);
    //dncrypt(password, pass);
    printf("%s\n", argv[1]);
    u2g(argv[1], strlen(argv[1]) + 1, password, 1024);
    printf("%s\n", password);
    g2u(password, 1024, password, 1024);
    printf("%s\n", password);
    /*int table_n = strlen(encodetable);
    srands('a');
    pass[0] = encodetable[rands() % table_n];
    pass[1] = encodetable[rands() % table_n];
    srands('a');
    if (pass[0] == encodetable[rands() % table_n] &&
        pass[1] == encodetable[rands() % table_n])*/
    printf("%s", pass);
    return 0;
}