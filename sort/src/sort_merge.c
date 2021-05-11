#include <stdlib.h>
#include "sort.h"

#undef sort_merge
#undef MIN

#define MIN(x, y) ((x) > (y) ? (y) : (x))

void sort_merge(sort_t *_data, size_t _site1, size_t _site2)
{
    sort_t *a = _data + _site1;
    sort_t *b = (sort_t *)malloc((_site2 = _site2 + 1U - _site1) * sizeof(sort_t));

    for (size_t seg = 1U; seg < _site2; seg += seg)
    {
        for (size_t start = 0U; start < _site2; start += seg * 2)
        {
            size_t low = start;
            size_t mid = MIN(start + seg, _site2);
            size_t high = MIN(start + seg * 2, _site2);

            size_t start1 = low;
            size_t end1 = mid;

            size_t start2 = mid;
            size_t end2 = high;

            size_t k = low;

            while (start1 < end1 && start2 < end2)
            {
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            }

            while (start1 < end1)
            {
                b[k++] = a[start1++];
            }

            while (start2 < end2)
            {
                b[k++] = a[start2++];
            }
        }

        swap(&a, &b, sizeof(&a));
    }

    if (a != _data + _site1)
    {
        for (size_t i = 0; i < _site2; i++)
        {
            b[i] = a[i];
        }
        b = a;
    }

    free(b);
    b = NULL;

    return;
}

#undef MIN