#include "btree.h"

#undef btree_count

unsigned int btree_count(Btree *_root)
{
    if (!_root)
        return 0U;

    unsigned int count = _root->count;
    count += btree_count(_root->left);
    count += btree_count(_root->right);

    return count;
}