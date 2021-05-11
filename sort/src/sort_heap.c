#include "sort.h"

#undef sort_heap

void heapify(sort_t *_data, size_t _site1, size_t _site2)
{
#if 1
    sort_t data = _data[_site1];

    for (size_t i = 2U * _site1 + 1U; i < _site2; i = 2U * i + 1U)
    {
        /* 左孩子 2*i + 1，右孩子 2*i + 2 */
        if (i + 1U < _site2 && _data[i] < _data[i + 1U])
        {
            i++; ///< 如果左子结点小于右子结点，i指向右子结点
        }

        if (data < _data[i])
        {
            _data[_site1] = _data[i]; // 将根节点设置为子节点的较大值
            _site1 = i;               // 继续往下
        }
        else
        {
            break; // 已经满足大根堆
        }
    }

    _data[_site1] = data; // 将temp值放到最终的位置

#else
    // 建立父節點指標和子節點指標
    size_t dad = _site1;
    size_t son = dad * 2U + 1U;

    while (son < _site2)
    {                                                          // 若子節點指標在範圍內才做比較
        if (son + 1U < _site2 && _data[son] < _data[son + 1U]) // 先比較兩個子節點大小，選擇最大的
        {
            son++;
        }
        if (_data[dad] >= _data[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
        {
            return;
        }
        else
        { // 否則交換父子內容再繼續子節點和孫節點比較
            swap(_data + dad, _data + son, sizeof(sort_t));
            dad = son;
            son = dad * 2U + 1U;
        }
    }
#endif
    return;
}

void sort_heap(sort_t *_data, size_t _site1, size_t _site2)
{
    _data += _site1;
    _site2 = _site2 + 1U - _site1;

    size_t i = 0U;

    // 先将数组构造成大顶堆
    /* ((size_t)0U - (size_t)1U) == SIZE_MAX */
    for (i = _site2 / 2U - 1U; i < _site2; i--)
    {
        heapify(_data, i, _site2); // 从第一个非叶子结点从下至上，从右至左调整结构
    }

    // 调整堆结构+交换堆顶元素与末尾元素
    for (i = _site2 - 1U; i > 0U; i--)
    {
        swap(_data, _data + i, sizeof(sort_t)); // 将堆顶元素与末尾元素进行交换
        heapify(_data, 0U, i);                   // 重新对堆进行调整
    }
}