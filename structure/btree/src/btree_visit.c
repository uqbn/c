#include "btree.h"
#include <stdio.h>

#undef btree_visit

unsigned int btree_visit(Btree *_node)
{
    unsigned int count = _node->count;
    while (count--)
    {
        printf("%i ", _node->data);
    }
    return _node->count;
}