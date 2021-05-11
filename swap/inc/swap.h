#ifndef __SWAP_H__
#define __SWAP_H__

#include <stddef.h>

/**
 * @brief swap memory
 * @param _mem1 the pointer of the first memory
 * @param _mem2 the pointer of the second memory
 * @param _size the size of memory need to swap
 * @return None
*/
void swap(void *restrict _mem1, void *restrict _mem2, size_t _size);


int swapc(char *_x, char *_y);

#endif