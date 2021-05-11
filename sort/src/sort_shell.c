#include "sort.h"

#undef sort_shell

void sort_shell(sort_t *_data, size_t _site1, size_t _site2)
{
    _data += _site1;
    _site2 -= _site1;

    for (size_t gap = _site2 >> 1U; gap; gap >>= 1U)
    {
        for (size_t i = gap; i <= _site2; i++)
        {
            /* start insertion sort */
            if (_data[i] < _data[i - gap])
            {
                sort_t data = _data[i];

                size_t j = i - gap;
                /* ((size_t)0U - (size_t)1U) == SIZE_MAX */
                while (j < i && data < _data[j])
                {
                    _data[j + gap] = _data[j];
                    j -= gap;
                }

                _data[j + gap] = data;
            }
            /* stop insertion sort */
        }
    }
}