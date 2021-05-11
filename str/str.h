#ifndef __STR_H__
#define __STR_H__

#include <string.h>

size_t strcou(const char *_str, const char *_substr);
size_t strcou_s(const char *_str, size_t _max, const char *_substr);
size_t strncou(const char *_str, const char *_substr, size_t _max);
size_t strncou_s(const char *_str, size_t _max1, const char *_substr, size_t _max2);

char *strnstr(const char *_str, const char *_substr, size_t _max);
char *strnstr_s(const char *_str, size_t _max1, const char *_substr, size_t _max2);

char *strrstr(const char *_str, const char *_substr);
char *strrnstr(const char *_str, const char *_substr, size_t _max);
char *strrnstr_s(const char *_str, size_t _max1, const char *_substr, size_t _max2);

int strswap(char *_str, size_t _index1, size_t _len1, size_t _index2, size_t _len2);

#endif