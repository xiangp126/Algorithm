#ifndef __UTIL_RBTREE_H_
#define __UTIL_RBTREE_H_

/* RB-Tree Property
 * In addition to the requirements imposed on a binary search tree
 * the following must be satisfied by a red–black tree:
 * <1> Each node is either red or black.
 * <2> The root is black. This rule is sometimes omitted.
 * <3> All leaves (NIL) are black.
 * <4> If a node is red, then both its children are black.
 * <5> Every path from a given node to any of its descendant
 * NIL nodes contains the same number of black nodes.
 */

typedef unsigned int  uint;
typedef unsigned char uchar;
typedef unsigned long ulong;

#define oops(msg) { \
    fprintf(stdout, "%s at:", msg); \
    printf ("%s->%s:%u\n", __FILE__, __FUNCTION__, __LINE__); \
    exit(1);\
}

typedef struct util_rbtree_node_s util_rbtree_node_t;
typedef struct util_rbtree_s util_rbtree_t;
typedef unsigned long util_key_t;

/* util_rbtree_node_t
 *
 *     --------- --------- --------- -------- -------- ---------
 *    |  key    | parent  |  left   | right  |  color |  data   |
 *     --------- --------  --------- -------- -------- ---------
 *
 */
/* s denotes structure, t for type */
struct util_rbtree_node_s {
    util_key_t key;
    util_rbtree_node_t *parent;
    util_rbtree_node_t *left;
    util_rbtree_node_t *right;
    int color;
    void *data;
};

/* util_rbtree_t
 *
 *     --------- --------- ---------
 *    |  root  |   nil  |  size    |
 *     --------- --------  ---------
 *
 */
struct util_rbtree_s {
    util_rbtree_node_t *root;
    // all NIL node in the tree will point to it
    util_rbtree_node_t nil;
    uint size;
};

enum RBTREE_COLOR {
    RED = 0,
    BLACK
};
#define _NIL(rbtree)              (&((rbtree)->nil))
#define util_rbt_black(rbnode)    ((rbnode)->color = BLACK)
#define util_rbt_red(rbnode)      ((rbnode)->color = RED)
#define util_rbt_isblack(rbnode)  ((rbnode)->color == BLACK)
#define util_rbt_isred(rbnode)    ((rbnode)->color == RED)

#define util_rbtree_min(rbtree)  util_rbsubtree_min(rbtree->root, _NIL(rbtree))
#define util_rbtree_max(rbtree)  util_rbsubtree_max(rbtree->root, _NIL(rbtree))

/*
 * rbt_clear_link
 * @node: node to clear link
 * only clear node's link, not clear node's color
 */
#define rbt_clear_link(node) do { \
    node->left = NULL; \
    node->right = NULL; \
    node->parent = NULL; \
} while(0)

/*
 * check if the tree is empty
 */
#define util_rbtree_isempty(rbtree) ((rbtree)->root == &(rbtree)->nil)

#ifdef __cplusplus
extern "C" {
#endif

/*
 * initialize a RB-Tree
 */
void util_rbtree_init(util_rbtree_t *rbtree);

/*
 * insert node into the tree
 * will call fix_up routine to maintain RB-Tree property
 */
void util_rbtree_insert(util_rbtree_t *rbtree, util_rbtree_node_t *node);

/*
 * delete a node from the tree
 * will call fix_up routine after deletion
 */
void util_rbtree_delete(util_rbtree_t *rbtree, util_rbtree_node_t *node);

/*
 * find the minimum node of the subtree
 * @node: root of the subtree
 * @sentinel: the sentinel node
 * return NULL if subtree is empty
 */
util_rbtree_node_t* util_rbsubtree_min(util_rbtree_node_t *node,
                                       util_rbtree_node_t *sentinel);

/*
 * find the maximum node of the subtree
 * @node: root of the subtree
 * @sentinel: the sentinel node
 * return NULL if subtree is empty
 */
util_rbtree_node_t* util_rbsubtree_max(util_rbtree_node_t *node,
                                    util_rbtree_node_t *sentinel);

/*
 * search node with key = @key in the tree
 * if no such key exist, return NULL
 */
util_rbtree_node_t* util_rbtree_search(util_rbtree_t *rbtree, util_key_t key);

/*
 * lookup node in the tree (for Consistent Hash use)
 * return the first node with key >= @key
 * if @key > all the key values in the tree, return the node with minimum key
 * return NULL if the tree is empty
 */
util_rbtree_node_t* util_rbtree_lookup(util_rbtree_t *rbtree, util_key_t key);

/*
 * travel through a RB-Tree in in-node sequence, do Read-Only operation
 * T for root, L for left, R for right
 *
 *        T
 *      /   \       L -> T -> R
 *     L     R
 *
 */
void util_rbtree_mid_travel(util_rbtree_t *rbtree,
                            void (*opera)(util_rbtree_node_t *, void *),
                            void *data);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __UTIL_RBTREE_H_ */
