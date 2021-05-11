#include <stdio.h>
#include "memhex.h"

void memhex32(FILE *restrict _stream, const void *restrict _mem, size_t _size)
{
    if (!_mem)
    {
        fprintf(_stream, "(null)\n");
        return;
    }

    unsigned int data32 = 0;

    for (size_t i = 0; i < _size; i++)
    {
        unsigned char byte = ((const unsigned char *)_mem)[i];
        data32 = (data32 & 0xFFFFFF00) | byte;

        if (i % 4 == 0)
        {
            fprintf(_stream, "%p ", (const unsigned char *)_mem + i);
        }

        for (unsigned char j = 7U; j < 8U; j--)
        {
            if ((byte >> j) & 0x01)
            {
                fputc('1', _stream);
            }
            else
            {
                fputc('0', _stream);
            }
        }

        if ((i + 1U) % 4 == 0)
        {
            fprintf(_stream, " 0x%08X", data32);
            fputc('\n', _stream);
        }
        else
        {
            data32 <<= 8;
            fputc(' ', _stream);
        }
    }

    return;
}

void memhex(FILE *restrict _stream, const void *restrict _mem, size_t _size)
{
    if (!_mem)
    {
        fprintf(_stream, "(null)\n");
        return;
    }

    for (size_t i = 0; i < _size; i++)
    {
        unsigned char byte = ((const unsigned char *)_mem)[i];

        fprintf(_stream, "%p ", (const unsigned char *)_mem + i);

        for (unsigned char j = 7U; j < 8U; j--)
        {
            if ((byte >> j) & 0x01)
            {
                fputc('1', _stream);
            }
            else
            {
                fputc('0', _stream);
            }
        }

        fprintf(_stream, " 0x%02X", byte);
        fputc('\n', _stream);
    }

    return;
}