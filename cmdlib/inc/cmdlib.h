#ifndef __CMDLIB_H__
#define __CMDLIB_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *cmdargstr(const char *_str);
int cmdrno(const char *_cmd);
char *cmdr(const char *_cmd);

#endif