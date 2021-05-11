/**
 * 作者:苏梦凡
 * author:smf
 * target:cmd
 * **/
#ifndef __CMD_H__
#define __CMD_H__
/*------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*------------------------------------------------------*/
//#define CMD_SHOW
/*------------------------------------------------------*/
/*------------------------------------------------------*/

extern char *cmd(const char *const cmd);

extern int cmdno(const char *const cmd);

extern char *cmdstr(const char *const str);

extern char *cmdcat(char *const ptr, const char *const str);

/*------------------------------------------------------*/
#endif