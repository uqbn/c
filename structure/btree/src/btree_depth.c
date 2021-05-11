#include "btree.h"

#undef btree_depth

unsigned int btree_depth(Btree *_root)
{
    if (!_root)
    {
        return 0U;
    }

    unsigned int l = btree_depth(_root->left);
    unsigned int r = btree_depth(_root->right);

    l = r < l ? l : r;

    return l + 1U;
}
