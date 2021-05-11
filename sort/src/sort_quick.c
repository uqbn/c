#include "sort.h"

#undef sort_quick

sort_t mid_three(sort_t *_data, size_t _site1, size_t _site2)
{
    size_t mid = (_site1 + _site2) / 2U;

    if (_data[mid] > _data[_site2])
        swap(_data + mid, _data + _site2, sizeof(sort_t));

    if (_data[_site1] > _data[_site2])
        swap(_data + _site1, _data + _site2, sizeof(sort_t));

    if (_data[mid] > _data[_site1])
        swap(_data + mid, _data + _site1, sizeof(sort_t));

    return _data[_site1];
}

size_t partition(sort_t *_data, size_t _site1, size_t _site2)
{
    size_t i = _site1;
    size_t j = _site2;
    sort_t x = mid_three(_data, i, j);

    while (i < j)
    {
        while (i < j && x <= _data[j])
        {
            j--;
        }
        if (i < j)
        {
            _data[i++] = _data[j];
        }

        while (i < j && x >= _data[i])
        {
            i++;
        }
        if (i < j)
        {
            _data[j--] = _data[i];
        }
    }

    _data[i] = x;

    return i;
}

void sort_quick(sort_t *_data, size_t _site1, size_t _site2)
{
    size_t i = _site1;
    size_t j = _site2;

    while (i < j)
    {
        size_t site = partition(_data, i, j);
        if (site - 1U > j)
            break;
        sort_quick(_data, i, site - 1U);
        i = site + 1U;
    }

    return;
}