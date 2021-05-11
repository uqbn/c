/**
 * @file memhex.h
 * @brief the header file of @ref memhex.c
 * @details provide a api of memory display
 * @author tqfx
 * @date 2020-11-27
 * @version 0.01
 * @copyright Copyright (c) 2020-2020
*/
#ifndef __MEMHEX_H__
#define __MEMHEX_H__

#include <stdio.h>

/**
 * @brief display 32 bits on a row
 * @param _stream the pointer of stream
 * @param _mem the header pointer of memory
 * @param _size the size of memory
 * @return void
*/
void memhex32(FILE *restrict _stream, const void *restrict _mem, size_t _size);

/**
 * @brief display 8 bits on a row
 * @param _stream the pointer of stream
 * @param _mem the header pointer of memory
 * @param _size the size of memory
 * @return void
*/
void memhex(FILE *restrict _stream, const void *restrict _mem, size_t _size);

#endif