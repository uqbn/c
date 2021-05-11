#include "sort.h"

#undef sort_selet

void sort_select(sort_t *_data, size_t _site1, size_t _site2)
{
    _data += _site1;
    _site2 -= _site1;

    for (size_t i = 0; i < _site2; i++)
    {
        size_t k = i;

        for (size_t j = i + 1; j <= _site2; j++)
        {
            if (_data[j] < _data[k])
                k = j;
        }

        if (k != i)
        {
            swap(_data + i, _data + k, sizeof(sort_t));
        }
    }

    return;
}