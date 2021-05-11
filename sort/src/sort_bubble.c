#include "sort.h"

#undef sort_bubble

void sort_bubble(sort_t *_data, size_t _site1, size_t _site2)
{
    _data += _site1;
    _site2 -= _site1;

    for (size_t i = 0U; i < _site2; i++)
    {
        for (size_t j = 0U; j < _site2 - i; j++)
        {
            if (_data[j] > _data[j + 1U])
            {
                swap(_data + j, _data + j + 1U, sizeof(sort_t));
            }
        }
    }

    return;
}