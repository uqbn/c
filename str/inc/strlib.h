#ifndef __STRLIB_H__
#define __STRLIB_H__

#include <stdlib.h>
#include <string.h>
#include "str.h"

/* Append SRC on the end of DEST.  */
char *strlibcat(char *_dst, const char *_src);
char *strlibncat(char *_dst, const char *_src, size_t _max);
/* Copy SRC to DEST.  */
char *strlibcpy(char *_dst, const char *_src);
char *strlibncpy(char *_dst, const char *_src, size_t _max);

char *strlibcpy_s(char *_dst, size_t _indexdst, const char *_src);
char *strlibncpy_s(char *_dst, size_t _indexdst, const char *_src, size_t _max);

char *strlibins(char *_str, size_t _index, const char *_substr);
char *strlibnins(char *_str, size_t _index, const char *_substr, size_t _max);

char *strlibdel(char *_str, size_t _index1, size_t _index2);
char *strlibcut(char *_str, size_t _index1, size_t _index2);
char *strlibmod(char *_str, size_t _index, size_t _size, const char *_newstr);

char *strlibdels(char *_str, const char *_substr);
char *strlibdel1(char *_str, const char *_substr);
char *strlibrdel1(char *_str, const char *_substr);
char *strlibdeln(char *_str, const char *_substr, size_t _max);
char *strlibrdeln(char *_str, const char *_substr, size_t _max);
char *strlibdeli(char *_str, const char *_substr, size_t _index);

char *strlibmods(char *_str, const char *_oldstr, const char *_newstr);
char *strlibmod1(char *_str, const char *_oldstr, const char *_newstr);
char *strlibrmod1(char *_str, const char *_oldstr, const char *_newstr);
char *strlibmodn(char *_str, const char *_oldstr, const char *_newstr, size_t _max);
char *strlibmodi(char *_str, const char *_oldstr, const char *_newstr, size_t _index);
char *strlibrmodn(char *_str, const char *_oldstr, const char *_newstr, size_t _max);

#endif