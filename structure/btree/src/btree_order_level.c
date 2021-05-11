#include "btree.h"
#include "queue_btree.h"

#undef btree_order_level

unsigned int btree_order_level(Btree *_root)
{
    unsigned int count = 0U;
    if (!_root)
    {
        return 0U;
    }

    Queue *queue = queue_init();
    (void)queue_push(queue, _root);
    while (queue_front(queue, &_root) == 1)
    {
        (void)queue_pop(queue, &_root);
        count = btree_visit(_root);
        if (_root->left)
            (void)queue_push(queue, _root->left);
        if (_root->right)
            (void)queue_push(queue, _root->right);
    }
    queue_free(queue);
    return count;
}