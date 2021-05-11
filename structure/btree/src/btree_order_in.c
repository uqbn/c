#include "btree.h"
#include <stdio.h>

#undef btree_order_in

unsigned int btree_order_in(Btree *_root)
{
    unsigned int count = 0U;
    if (!_root)
    {
        return 0U;
    }

    count += btree_order_in(_root->left);

    count += btree_visit(_root);

    count += btree_order_in(_root->right);

    return count;
}
