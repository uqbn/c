#include "btree.h"

#undef btree_add

Btree *btree_add(Btree *_root, btree_t _data)
{
    if (!_root)
    {
        return btree_init(_data);
    }

    if (_data < _root->data)
    {
        if (_root->left)
        {
            return btree_add(_root->left, _data);
        }
        else
        {
            _root->left = btree_init(_data);
            return _root->left;
        }
    }

    if (_data > _root->data)
    {
        if (_root->right)
        {
            return btree_add(_root->right, _data);
        }
        else
        {
            _root->right = btree_init(_data);
            return _root->right;
        }
    }

    _root->count++;
    return _root;
}