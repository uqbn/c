#include "btree.h"

#undef btree_leaf_count

unsigned int btree_leaf_count(Btree *_root)
{
    static unsigned int count = 0;
    if (!_root)
        return 0U;

    if (!_root->left && !_root->right)
        count++;

    (void)btree_leaf_count(_root->left);
    (void)btree_leaf_count(_root->right);

    return count;
}