#ifndef __BTREE_H__
#define __BTREE_H__

typedef int btree_t;
typedef struct Btree Btree;
struct Btree
{
    unsigned int count;
    btree_t data;
    struct Btree *left;
    struct Btree *right;
};

extern Btree *btree_init(btree_t _data);
extern void btree_free(Btree *_root);
extern Btree *btree_add(Btree *_root, btree_t _data);
extern unsigned int btree_count(Btree *_root);
extern unsigned int btree_visit(Btree *_node);
extern unsigned int btree_order_pre(Btree *_root);
extern unsigned int btree_order_in(Btree *_root);
extern unsigned int btree_order_post(Btree *_root);
extern unsigned int btree_order_level(Btree *_root);
extern unsigned int btree_depth(Btree *_root);
extern Btree *btree_pointer(Btree *_root, btree_t _data);
extern unsigned int btree_pointer_depth(Btree *_root, btree_t _data);
extern unsigned int btree_leaf_count(Btree *_root);
extern int btree_out_in(Btree *_root, btree_t **_dest, unsigned int *_count);

#endif