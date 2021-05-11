#include "btree.h"
#include <stdlib.h>

#undef btree_init

Btree *btree_init(btree_t _data)
{
    Btree *node = (Btree *)calloc(1U, sizeof(Btree));
    node->data = _data;
    node->count = 1;
    return node;
}