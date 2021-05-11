#include "btree.h"

#undef btree_pointer_depth
unsigned int btree_pointer_depth(Btree *_root, btree_t _data)
{
    return btree_depth(btree_pointer(_root, _data));
}