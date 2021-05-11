
#ifndef __SMF_PD_H__
#define __SMF_PD_H__
/*------------------------------------------------------------------------------*/
/*include----------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "cJSON.h"
/*define-----------------------------------------------*/
#define PD_NAME "name"
#define PD_TYPE "type"
#define PD_PASSWORD "password"

#define PD_DATA "data"
#define PD_DATANAME ".smf.mm.dat"
/*define-----------------------------------------------*/
#define PD_LEN 64
#define PDLEN PD_LEN * 16
/*typrdef----------------------------------------------*/
typedef enum
{
    PD_ALNUM,  //alnum
    PD_ALPHA,  //alpha
    PD_DIGIT,  //digit
    PD_LOWER,  //lower
    PD_UPPER,  //upper
    PD_PUNCT,  //punct
    PD_GRAPH,  //graph
    PD_PRINT,  //print
    PD_XDIGIT, //xdigit
} Pd_type;

typedef struct Password
{
    Pd_type type;
    char *name;
    char *key;
    int len;
} Password;

/*define-----------------------------------------------*/
/*function---------------------------------------------*/

/*encode*/

/*
    功能:   加密
    参数:
        buff    加密后的缓冲区  内存大于PDLEN 
        pass    需要加密的字符串    长度小于 PD_LEN + 1
    返回:   密码长度
*/
size_t encrypt(char *const buff, const char *const pass);

/*
    功能:   解密
    参数:
        buff    解密的字符  长度等于PDLEN
        pass    密码缓冲区  内存大于PD_LEN
    返回:   密码长度
*/
size_t dncrypt(const char *const buff, char *const pass);

/*lib*/

/*
    功能:读取文件内容
    参数:文件名
    返回:文件内容
*/
char *rfile(const char *const filename);

/*
    功能:写入文件
    参数:文件名     要写入的字符串
    返回:0  成功    -1 失败
*/
int wstr(const char *const filename, const char *const);

/*
    功能:将cJSON密码写入文件
    参数:文件名     cJSON根节点
    返回:0  成功    -1 失败     -2  节点存在
*/
int wpd(const char *const filename, cJSON *root);

/*
    功能:读取文件的内容
    参数:文件名  解密标志 1 解密 0 不解密
    返回:cJSON表
*/
cJSON *pd_read(const char *const dataname, int mark);

/*
    功能:查找item在array的位置
    参数:cJSON根节点    item的object    object的valuestring
    返回:自然数  位置   -1  未找到
*/
int json_objectin(const cJSON *const datajson, const char *const object, const char *const str);

/*
    功能:
    参数:
    返回:
*/
char *json_getobject(const cJSON *const root, const char *const object, size_t i);

/*
    功能:
    参数:
    返回:
*/
int json_objectcmp(const cJSON *const datajson, const char *const object, size_t i, size_t j);

/*
    功能:
    参数:
    返回:
*/
int json_objectsite(const cJSON *const datajson, const char *const object, const char *const str);

/*name*/

/*
    功能:
    参数:
    返回:
*/
int pd_namesite(const cJSON *const datajson, const char *const str);

/*
    功能:
    参数:
    返回:
*/
int pd_namecmp(const cJSON *const root, size_t i, size_t j);

/*pd valuaable*/

/*
    功能:
    参数:
    返回:
*/
void pd_getpd(const cJSON *const root, size_t i, Password *const pd);

/*
    功能:
    参数:
    返回:
*/
void pd_setpd(cJSON *const root, size_t i, Password *const pd);

/*
    功能:
    参数:
    返回:
*/
void pd_set(cJSON *const root, size_t i, size_t j);

/*
    功能:
    参数:
    返回:
*/
void pd_swap(cJSON *const root, size_t i, size_t j);

/*sort*/

/*
    功能:
    参数:
    返回:
*/
void pd_insort(cJSON *const root, int low, int high);

/*
    功能:
    参数:
    返回:
*/
void pd_qsort(cJSON *const root, size_t m, size_t n);

/*pd_ppp*/

/*
    功能:
    参数:
    返回:
*/
char *pd_create(Pd_type type, size_t n);

/*
    功能:
    参数:
    返回:
*/
cJSON *pd_find(const char *const dataname, const char *const name);

/*
    功能:
    参数:
    返回:
*/
int pd_add(const char *const dataname, const char *const name, const char *const password);

/*
    功能:
    参数:
    返回:
*/
int pd_del(const char *const dataname, const char *const name);

/*
    功能:
    参数:
    返回:
*/
int pd_edit(const char *const dataname, const char *const name, const char *const password);

/*
    功能:
    参数:
    返回:
*/
int pd_derive(const char *const dataname, const char *const outdataname);

/*
    功能:
    参数:
    返回:
*/
int pd_import(const char *const dataname, const char *const indataname, int mark);

/*
    功能:
    参数:
    返回:
*/
int pd_init(const char *const confname);
/*------------------------------------------------------------------------------*/
#endif /* __SMD_PD_H__ */