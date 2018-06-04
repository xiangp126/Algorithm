#ifndef __UTIL_RBTREE_H_
#define __UTIL_RBTREE_H_

#include "configure.h"

/* In addition to the requirements imposed on a binary search tree
 * the following must be satisfied by a red–black tree:
 * <1> Each node is either red or black.
 * <2> The root is black. This rule is sometimes omitted.
 * <3> All leaves (NIL) are black.
 * <4> If a node is red, then both its children are black.
 * <5> Every path from a given node to any of its descendant
 * NIL nodes contains the same number of black nodes.
 */

typedef struct util_rbtree_node_s util_rbtree_node_t;
typedef struct util_rbtree_s util_rbtree_t;

struct util_rbtree_node_s {
    long key;
    util_rbtree_node_t *parent;
    util_rbtree_node_t *left;
    util_rbtree_node_t *right;
    int color;
    void *data;
};

struct util_rbtree_s {
    util_rbtree_node_t *root;
    // all NIL node in the tree will point to it
    util_rbtree_node_t null;
    u_int size;
};

#define util_rbt_black(rbnode)    ((rbnode)->color = 1)
#define util_rbt_red(rbnode)      ((rbnode)->color = 0)
#define util_rbt_isblack(rbnode)  ((rbnode)->color == 1)
#define util_rbt_isred(rbnode)    ((rbnode)->color == 0)

#define util_rbtree_isempty(rbtree) ((rbtree)->root == &(rbtree)->null)

#define util_rbtree_min(rbtree) util_rbsubtree_min((rbtree)->root, &(rbtree)->null)
#define util_rbtree_max(rbtree) util_rbsubtree_max((rbtree)->root, &(rbtree)->null)

void util_rbtree_init(util_rbtree_t *rbtree);
void util_rbtree_insert(util_rbtree_t *rbtree, util_rbtree_node_t *node);
void util_rbtree_delete(util_rbtree_t *rbtree, util_rbtree_node_t *node);



#endif /* ifndef __UTIL_RBTREE_H_ */
