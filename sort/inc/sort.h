#ifndef __SORT_H__
#define __SORT_H__

#include <stddef.h>
#include "swap.h"

typedef int sort_t;

void sort_bubble(sort_t *_data, size_t _site1, size_t _site2);
void sort_select(sort_t *_data, size_t _site1, size_t _site2);
void sort_insert(sort_t *_data, size_t _site1, size_t _site2);
void sort_shell(sort_t *_data, size_t _site1, size_t _site2);
void sort_merge(sort_t *_data, size_t _site1, size_t _site2);
void sort_quick(sort_t *_data, size_t _site1, size_t _site2);
void sort_heap(sort_t *_data, size_t _site1, size_t _site2);

#endif