#include "btree.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    Btree *root = NULL;
    srand(1000);
    for (size_t i = 0; i < 10U; i++)
    {
        btree_t data = (btree_t)rand() % 10U;
        if (!i)
            root = btree_init(data);
        else
            (void)btree_add(root, data);
        printf("%i ", data);
    }

    printf("\npre:\t");
    printf("\n%u", btree_order_pre(root));
    putchar('\n');

    printf("in:\t");
    printf("\n%u", btree_order_in(root));
    putchar('\n');

    printf("post:\t");
    printf("\n%u", btree_order_post(root));
    putchar('\n');

    printf("level:\t");
    printf("\n%u", btree_order_level(root));
    putchar('\n');

    printf("depth:\t%u\n", btree_depth(root));

    printf("6'depth\t%u\n", btree_pointer_depth(root, 6));

    printf("leaf:\t%u\n", btree_leaf_count(root));

    btree_t *dest = NULL;
    unsigned int count = 0;
    btree_out_in(root, &dest, &count);
    printf("count:%u %u\n", btree_count(root), count);
    for (size_t i = 0; i < count; i++)
    {
        printf("%i ", dest[i]);
    }
    putchar('\n');
    btree_free(root);
    return 0;
}