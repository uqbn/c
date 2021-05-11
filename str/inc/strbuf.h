#ifndef __STRBUFF_H__
#define __STRBUFF_H__

#include <string.h>
#include "str.h"

int strins(char *_str, size_t _bufsz, size_t _index, const char *_substr);
int strnins(char *_str, size_t _bufsz, size_t _index, const char *_substr, size_t _subsz);

void strdel(char *_str, size_t _index, size_t _subsz);
size_t strdels(char *_str, const char *_substr);
int strdel1(char *_str, const char *_substr);
int strrdel1(char *_str, const char *_substr);
size_t strdeln(char *_str, const char *_substr, size_t _max);
size_t strrdeln(char *_str, const char *_substr, size_t _max);
int strdeli(char *_str, const char *_substr, size_t _index);

void strmod(char *_str, size_t _strsz, size_t _index, size_t _oldsz, const char *_newstr, size_t _newsz);
size_t strmods(char *_str, size_t _strsz, const char *_oldstr, const char *_newstr);
int strmod1(char *_str, size_t _strsz, const char *_oldstr, const char *_newstr);
int strrmod1(char *_str, size_t _strsz, const char *_oldstr, const char *_newstr);
size_t strmodn(char *_str, size_t _strsz, const char *_oldstr, const char *_newstr, size_t _max);
size_t strrmodn(char *_str, size_t _strsz, const char *_oldstr, const char *_newstr, size_t _max);
int strmodi(char *_str, size_t _strsz, const char *_oldstr, const char *_newstr, size_t _index);

#endif