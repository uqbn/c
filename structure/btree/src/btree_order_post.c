#include "btree.h"
#include <stdio.h>

#undef btree_order_post

unsigned int btree_order_post(Btree *_root)
{
    unsigned int count = 0;
    if (!_root)
    {
        return 0U;
    }

    count += btree_order_post(_root->left);

    count += btree_order_post(_root->right);

    count += btree_visit(_root);

    return count;
}
