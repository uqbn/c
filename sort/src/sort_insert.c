#include "sort.h"

#undef sort_insert

void sort_insert(sort_t *_data, size_t _site1, size_t _site2)
{
    _data += _site1;
    _site2 -= _site1;

    for (size_t i = 1U; i <= _site2; i++)
    {
        if (_data[i] < _data[i - 1U])
        {
            sort_t data = _data[i];

            size_t j = i - 1U;
            /* ((size_t)0U - (size_t)1U) == SIZE_MAX */
            while (j < i && data < _data[j])
            {
                _data[j + 1U] = _data[j];
                j -= 1U;
            }

            _data[j + 1U] = data;
        }
    }

    return;
}