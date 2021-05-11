#include "btree.h"

#undef btree_pointer

Btree *btree_pointer(Btree *_root, btree_t _data)
{
    if (!_root)
        return ((void *)0);

    if (_root->data == _data)
        return _root;

    Btree *pleft = btree_pointer(_root->left, _data);
    Btree *pright = btree_pointer(_root->right, _data);

    if (pleft)
        return pleft;
    if (pright)
        return pright;
    return ((void *)0);
}