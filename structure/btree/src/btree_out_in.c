#include "btree.h"
#include <stdlib.h>

#undef btree_out_in

int btree_out_in(Btree *_root, btree_t **_dest, unsigned int *_count)
{
    if (!_root)
        return -1;
    if (!_dest)
        return -2;
    if (!_count)
        return -3;

    (void)btree_out_in(_root->left, _dest, _count);

    unsigned int count = _root->count;
    while (count--)
    {
        if (!*_dest)
        {
            *_dest = (btree_t *)malloc(sizeof(btree_t));
        }
        else
        {
            *_dest = (btree_t *)realloc(*_dest, (*_count + 1U) * sizeof(btree_t));
        }
        (*_dest)[*_count] = _root->data;
        (*_count)++;
    }

    (void)btree_out_in(_root->right, _dest, _count);

    return 0;
}