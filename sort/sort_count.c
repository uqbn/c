#include <stdlib.h>
#include <string.h>
#include "sort.h"

#undef sort_count

int sort_count(sort_t *_data, size_t _site1, size_t _site2)
{
    _data += _site1;
    _site2 -= _site1;

    size_t i;
    sort_t max_val = *_data;

    for (i = 1; i < _site2; i++)
        if (_data[i] > max_val)
            max_val = _data[i];

    /*为计数器数组分配空间*/
    sort_t *counts = (size_t *)malloc((max_val + 1) * sizeof(size_t));
    /*为已排序元素临时存放数组分配空间*/
    sort_t *temp = (size_t *)malloc(_site2 * sizeof(size_t));

    if (counts == NULL)
        return -1;

    if (temp == NULL)
        return -1;

    /* 初始化计数数组 */
    for (i = 0U; i < max_val + 1; i++)
        counts[i] = 0;

    /* 统计每个元素出现的次数（counts的下标索引即是要统计的元素本身）*/
    for (i = 0U; i < _site2; i++)
        counts[_data[i]]++;

    /* 将元素本身的次数加上它前一个元素的次数(得到元素偏移量) */
    for (i = 1; i < max_val + 1; i++)
        counts[i] += counts[i - 1];

    /* 关键代码：使用上面得到的计数数组去放置每个元素要排序的位置 */
    for (i = _site2 - 1; i < _site2; i--)
    {
        temp[counts[_data[i]] - 1] = _data[i]; /* counts的值是元素要放置到 temp中的偏移量 */
        counts[_data[i]]--;                    /* counts的计数减 1 */

        //        temp[--counts[arr[i]]] = arr[i];
    }

    /* 将 Counting_Sort已排序的元素从 temp拷贝回 data */
    memcpy(_data, temp, _site2 * sizeof(sort_t));

    /*释放前面分配的空间*/
    free(counts);
    free(temp);

    return 0;
}