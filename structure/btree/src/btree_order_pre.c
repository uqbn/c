#include "btree.h"
#include <stdio.h>

#undef btree_order_pre

unsigned int btree_order_pre(Btree *_root)
{
    unsigned int count = 0;
    if (!_root)
    {
        return 0U;
    }

    count += btree_visit(_root);

    count += btree_order_pre(_root->left);

    count += btree_order_pre(_root->right);

    return count;
}
