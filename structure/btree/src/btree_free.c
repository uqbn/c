#include "btree.h"
#include <stdlib.h>

#undef btree_free

void btree_free(Btree *_root)
{
    if (!_root)
        return;
    btree_free(_root->left);
    btree_free(_root->right);
    free(_root);
    return;
}