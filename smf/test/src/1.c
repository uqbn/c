#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// base64编码表
unsigned char *encodeTable = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// 对字符串进行base64加密
// str： 要进行加密的字符串
unsigned char *base64EncodeStr(unsigned char str[])
{
    // str_len,要计算的字符串长度
    // encode_len,加密后的字符串长度
    long str_len, encode_len;
    // strlen()看不懂的话，emm，在看看你的c语言书把
    str_len = strlen(str);
    // 计算加密后的字符串长度
    // （字符串长度 + 2） / 3类似与取进一法，向上取整，
    encode_len = (str_len + 2) / 3 * 4;

    //分配内存
    unsigned char *encode;
    encode = (unsigned char *)malloc(sizeof(unsigned char) * encode_len);
    encode[encode_len] = '\0';

    // 进行编码
    int i, j;
    // 循环每三个字节执行操作
    for (i = 0, j = 0; i < encode_len - 2; i += 4, j += 3)
    {
        // 此处进行位操作
        // 字符串第一个字节右移两位，高位补零
        // 获取加密后的第一个字节
        encode[i] = encodeTable[str[j] >> 2];
        // 将字符串第一个字节与0x3(0000 0011)执行与操作，获取第一个字节的低两位
        // 第二个字节右移四位与执行或操作
        // 获取加密后第二个字节
        encode[i + 1] = encodeTable[(str[j] & 0x3) << 4 | str[j + 1] >> 4];
        // 将字符串第二个字节与0xf(0000 1111)执行与操作，获取第二个字节的低四位
        // 第三个字节右移六位与执行或操作
        // 获取加密后的第三个字节
        encode[i + 2] = encodeTable[(str[j + 1] & 0xf) << 2 | str[j + 2] >> 6];
        // 将字符串第三个字节与0x3f(0011 1111)执行与操作，获取第三个字节的低六位
        // 获取加密后第四个字节
        encode[i + 3] = encodeTable[str[j + 2] & 0x3f];
    }

    // 补=
    if (str_len % 3 == 1)
    {
        encode[encode_len - 2] = '=';
        encode[encode_len - 1] = '=';
    }
    else if (str_len % 3 == 2)
    {
        encode[encode_len - 1] = '=';
    }

    return encode;
}

int main(int argc, char *argv[])
{
    printf(base64EncodeStr(argv[1]));
    return 0;
}