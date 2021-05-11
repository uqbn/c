#include <stdint.h>
#include "swap.h"

#undef swap

inline void swap(void *restrict _mem1, void *restrict _mem2, size_t _size)
{
    size_t i = 0U;

    if (_size % sizeof(uint64_t) == 0U)
    {
        _size /= sizeof(uint64_t);

        while (i < _size)
        {
            ((uint64_t *)_mem1)[i] ^= ((uint64_t *)_mem2)[i];
            ((uint64_t *)_mem2)[i] ^= ((uint64_t *)_mem1)[i];
            ((uint64_t *)_mem1)[i] ^= ((uint64_t *)_mem2)[i];

            i++;
        }
    }
    else if (_size % sizeof(uint32_t) == 0U)
    {
        _size /= sizeof(uint32_t);

        while (i < _size)
        {
            ((uint32_t *)_mem1)[i] ^= ((uint32_t *)_mem2)[i];
            ((uint32_t *)_mem2)[i] ^= ((uint32_t *)_mem1)[i];
            ((uint32_t *)_mem1)[i] ^= ((uint32_t *)_mem2)[i];

            i++;
        }
    }
    else if (_size % sizeof(uint16_t) == 0U)
    {
        _size /= sizeof(uint16_t);

        while (i < _size)
        {
            ((uint16_t *)_mem1)[i] ^= ((uint16_t *)_mem2)[i];
            ((uint16_t *)_mem2)[i] ^= ((uint16_t *)_mem1)[i];
            ((uint16_t *)_mem1)[i] ^= ((uint16_t *)_mem2)[i];

            i++;
        }
    }
    else
    {
        while (i < _size)
        {
            ((uint8_t *)_mem1)[i] ^= ((uint8_t *)_mem2)[i];
            ((uint8_t *)_mem2)[i] ^= ((uint8_t *)_mem1)[i];
            ((uint8_t *)_mem1)[i] ^= ((uint8_t *)_mem2)[i];

            i++;
        }
    }

    return;
}