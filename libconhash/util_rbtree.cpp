#include <stdio.h>
#include <stdlib.h>
#include "util_rbtree.h"

static void rbtree_left_rotate(util_rbtree_t *rbtree,
                               util_rbtree_node_t *node);
static void rbtree_right_rotate(util_rbtree_t *rbtree,
                                util_rbtree_node_t *node);
static void rbtree_insert_fixup(util_rbtree_t *rbtree,
                                util_rbtree_node_t *node);
static void rbtree_mid_travel(util_rbtree_node_t *node,
                              util_rbtree_node_t *sentinel,
                              void (*opera)(util_rbtree_node_t *, void *),
                              void *data);

void util_rbtree_init(util_rbtree_t *rbtree) {
    if (rbtree != NULL) {
        // NIL must be black
        util_rbt_black(_NIL(rbtree));
        rbtree->root = _NIL(rbtree);
        rbtree->size = 0;
    }
}

// An insert node is deemed color to Red
void util_rbtree_insert(util_rbtree_t *rbtree, util_rbtree_node_t *node) {
    util_rbtree_node_t *x, *y;
    if ((rbtree == NULL) && (node == NULL) && (node == _NIL(rbtree))) {
        return;
    }
    // the tree is empty
    if (rbtree->root == _NIL(rbtree)) {
        rbtree->root = node;
        node->parent = _NIL(rbtree);
    } else {
        x = rbtree->root;
        while (x != _NIL(rbtree)) {
            y = x;
            if (node->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        // now y is node's parent
        node->parent = y;
        if (node->key < y->key) {
            y->left = node;
        } else {
            y->right = node;
        }
    }
    // Initialize node's link and color
    node->left = _NIL(rbtree);
    node->right = _NIL(rbtree);
    util_rbt_red(node);
    // fix up insert
    rbtree_insert_fixup(rbtree, node);
    rbtree->size++;
}

void util_rbtree_delete(util_rbtree_t *rbtree, util_rbtree_node_t *node) {
    int isblack;
    util_rbtree_node_t *pTmp, *subst;
    if ((rbtree == NULL) || (node == NULL) || (node == _NIL(rbtree))) {
        return;
    }
    // if node's left is NULL
    if (node->left == _NIL(rbtree)) {
        pTmp = node;
        subst = node->right;
    } else {
        // node's left not NULL, right NULL
        if (node->right == _NIL(rbtree)) {
            pTmp = node;
            subst = node->left;
        } else {
            // node's left & right aren't NULL

        }
    }

    if (pTmp == rbtree->root) {

    }
}

// insert may violate the rbtree properties, need fix up the tree
void rbtree_insert_fixup(util_rbtree_t *rbtree, util_rbtree_node_t *node) {
    // np denotes node's parent, nu for uncle, ng for grandparent
    util_rbtree_node_t *np, *nu, *ng;
    // fix up the property recursive
    while (util_rbt_isred(node->parent)) {
        np = node->parent;
        ng = np->parent;
        // if parent is the left child of its parent (node's grandparent)
        if (np == ng->left) {
            /*
             * N for new node, P for parent, U for uncle, G for grandparent
             * P is left child of G
             *
             *          |
             *          G
             *        /   \
             *       P     U
             *     /
             *    N
             *
             */
            nu = np->right;
            // case 1: parent & uncle are red
            if (util_rbt_isred(nu)) {
                /*
                 * N for new node, P for parent, U for uncle, G for grandparent
                 * R for red, B for black
                 *
                 *          |                   |                      |
                 *          G                   B       color          R
                 *        /   \     or        /   \     ---->        /   \
                 *       P     U             R     R               B      B
                 *     /                   /                      /
                 *    N                   R                      R
                 *
                 */
                util_rbt_black(np);
                util_rbt_black(nu);
                util_rbt_red(ng);
                node = ng;
            } else {
                // case 2: parent red, uncle black, node is right child
                if (node == np->right) {
                    /*
                     * N for new node, P for parent, U for uncle
                     * G for grandparent, S for sibling
                     * LR denotes for left rotate, RR for right rotate
                     * Manipulate:
                     * <1> Left Rotate at P
                     * <2> swap P and N to prepar the following right rotation
                     *
                     *         |                     |
                     *         G     LR at P         G
                     *       /   \   ------>       /   \
                     *      P     U               N     U
                     *    /   \                 /
                     *   S     N               P
                     *                       /
                     *                      S
                     *
                     *
                     *               |                        |
                     *               G                        N
                     *             /   \     RR at G        /   \
                     *   np -->   N     U    ------>      P      G
                     *          /                        /         \
                     *         P  <-- node              S           U
                     *       /
                     *      S
                     *
                     * Or
                     * R for red, B for black
                     *
                     *         |                       |                     |
                     *         B        LR             B      color          R
                     *       /   \      -->          /   \    ---->        /   \
                     *      R     B                 R     B               B     B
                     *    /   \                   /                     /
                     *   B     R                 R            node --> R
                     *                         /                     /
                     *                        B                     B
                     *
                     *                |
                     *   RR           B
                     *   -->        /   \
                     *             R      R
                     *           /         \
                     *          B            B
                     *
                     */
                    node = np;
                    /* left rotate at New Node's parent */
                    rbtree_left_rotate(rbtree, node);
                    np = node->parent;
                    /*  Upper 3 line code operates same as below */
                    // rbtree_left_rotate(rbtree, np);
                    // util_rbtree_node_t *pTmp = np;
                    // np = node;
                    // node = pTmp;
                }
                // case 3: parent red, uncle black, node is left child
                /*
                 * N for new node, P for parent, U for uncle
                 * G for grandparent, S for sibling
                 *
                 *         |                           |
                 *         G        RR at G            P
                 *       /   \      ------>          /   \
                 *      P     U                     N     G
                 *    /   \                             /   \
                 *   N     S                           S     U
                 *
                 * Or
                 * R for red, B for black
                 *
                 *         |                      |                |
                 *         B       color          R       RR       B
                 *       /   \     ---->        /   \     -->    /   \
                 *      R     B                B     B          R     R
                 *    /   \                  /   \                  /   \
                 *   R     B                R     B                B     B
                 *
                 */
                util_rbt_black(np);
                util_rbt_red(ng);
                /* right rotate at New Node's grandparent */
                rbtree_right_rotate(rbtree, ng);
            }
        } else {
            /* parent is the right child of its parent (node's grandparent)
             * Operation Symmetric
             */
            /*
             * N for new node, P for parent, U for uncle, G for grandparent
             * P is right child of G
             *
             *          |
             *          G
             *        /   \
             *       U     P
             *            /
             *          N
             *
             */
            nu = np->left;
            // case 1: parent & uncle are red
            if (util_rbt_isred(nu)) {
                /*
                 * N for new node, P for parent, U for uncle, G for grandparent
                 * R for red, B for black
                 *
                 *          |                  |                      |
                 *          G                  B        color         R
                 *        /   \       or     /   \      ---->       /   \
                 *       U     P            R     R                B      B
                 *            /                 /                       /
                 *           N                 R                       R
                 *
                 */
                util_rbt_black(np);
                util_rbt_black(nu);
                util_rbt_red(ng);
                node = ng;
            } else {
                // case 2: parent red, uncle black, node is left child
                if (node == np->left) {
                    /*
                     * N for new node, P for parent, U for uncle
                     * G for grandparent, S for sibling
                     * LR denotes for left rotate, RR for right rotate
                     * Manipulate:
                     * <1> Right Rotate at P
                     * <2> swap P and N to prepar the following left rotation
                     *
                     *         |                         |
                     *         G        RR at P          G
                     *       /   \      ------>        /   \
                     *      U     P                   U     N
                     *          /   \                         \
                     *         N     S                          P
                     *                                           \
                     *                                            S
                     *
                     *         |                                         |
                     *         G                                         N
                     *       /   \                  LR at G            /   \
                     *      U     N  <-- np         ------>           G      P
                     *              \                               /         \
                     *                P  <-- node                  U           S
                     *                 \
                     *                  S
                     *
                     *
                     * Or
                     * R for red, B for black
                     *
                     *       |                |                     |
                     *       B        RR      B          color      R
                     *     /   \      -->   /   \        ---->    /   \
                     *    B     R          B     R               B     B <-- np
                     *        /   \                \                     \
                     *       R     B                 R            node --> R
                     *                                \                     \
                     *                                 B                     B
                     *
                     *
                     *                |
                     *   LR           B
                     *   -->        /   \
                     *             R      R
                     *           /         \
                     *          B            B
                     *
                     */
                    node = np;
                    /* right rotate at New Node's parent */
                    rbtree_right_rotate(rbtree, node);
                    np = node->parent;
                    /*  Upper 3 line code operates same as below */
                    // rbtree_right_rotate(rbtree, np);
                    // util_rbtree_node_t *pTmp = np;
                    // np = node;
                    // node = pTmp;
                }
                // case 3: parent red, uncle black, node is right child
                /*
                 * N for new node, P for parent, U for uncle
                 * G for grandparent, S for sibling
                 *
                 *         |                        |
                 *         G        LR at G         P
                 *       /   \      ------>       /   \
                 *      U     P                  G     N
                 *          /   \              /   \
                 *         S     N            U     S
                 *
                 * Or
                 * R for red, B for black
                 *
                 *         |                  |                     |
                 *         B       color      R         LR          B
                 *       /   \     ---->    /   \       -->       /   \
                 *      B     R            B     B               R     B
                 *          /   \              /   \           /   \
                 *         B     R            B     B         B     B
                 *
                 */
                util_rbt_black(np);
                util_rbt_red(ng);
                /* left rotate at New Node's grandparent */
                rbtree_left_rotate(rbtree, ng);
            }
        }
    }
    // mark root as black
    util_rbt_black(rbtree->root);
}

// left rotate based on 'node', make 'node' left child of other's
void rbtree_left_rotate(util_rbtree_t *rbtree, util_rbtree_node_t *node) {
    /*
     * N for new node
     *
     *      |                       |
     *      N                       S
     *    /   \       -->         /   \
     *   A     S                 N     D
     *       /   \             /  \
     *      C     D           A    C
     *
     */
    // np denotes node's parent, rc denotes right child, lc left child
    util_rbtree_node_t *np = node->parent;
    util_rbtree_node_t *rc = node->right;
    util_rbtree_node_t *rclc = rc->left;
    // make rc replace node's position
    rc->parent = np;
    // if 'node' is the root of the tree
    if (node  == rbtree->root) {
        rbtree->root = rc;
    } else {
        // 'node' is the left child of its parent
        if (node == np->left) {
            np->left = rc;
        } else {
            np->right = rc;
        }
    }
    // make node to be rc's left child
    node->parent = rc;
    rc->left = node;
    // rc's left child to be node's right child
    node->right = rclc;
    // if rclc not NIL node
    if (rclc != _NIL(rbtree)) {
        rclc->parent = node;
    }
}

// right rotate based on 'node', make 'node' right child of other's
void rbtree_right_rotate(util_rbtree_t *rbtree, util_rbtree_node_t *node) {
    /*
     * S for node, just the reverse operation of left rotation
     *
     *         |                       |
     *         S                       N
     *       /   \       -->         /   \
     *      N     D                 A     S
     *    /  \                          /   \
     *   A    C                        C     D
     *
     */
    // np denotes node's parent, lc denotes left child, rc right child
    util_rbtree_node_t *np = node->parent;
    util_rbtree_node_t *lc = node->left;
    util_rbtree_node_t *lcrc = lc->right;
    // make lc replace node's position
    lc->parent = np;
    // if 'node' is the root of the tree
    if (node == rbtree->root) {
        rbtree->root = lc;
    } else {
        // 'node' is the left child of its parent
        if (node == np->left) {
            np->left = lc;
        } else {
            np->right = lc;
        }
    }
    // make node lc's right child
    lc->right = node;
    node->parent = lc;
    // lc's right child to be node's left child
    node->right = lcrc;
    // if lcrc not NIL node
    if (lcrc != _NIL(rbtree)) {
        lcrc->parent = node;
    }
}

util_rbtree_node_t* util_rbtree_search(util_rbtree_t *rbtree, util_key_t key) {
    if (rbtree != NULL) {
        util_rbtree_node_t *node = rbtree->root;
        util_rbtree_node_t *nil = _NIL(rbtree);
        while (node != nil) {
            if (key < node->key) {
                node = node->left;
            } else {
                if (key > node->key) {
                    node = node->right;
                } else {
                    return node;
                }
            }
        }
    }
    return NULL;
}

util_rbtree_node_t* util_rbtree_lookup(util_rbtree_t *rbtree, util_key_t key) {
    if (rbtree != NULL && ! util_rbtree_isempty(rbtree)) {
        util_rbtree_node_t *node = NULL;
        util_rbtree_node_t *pTmp = rbtree->root;
        util_rbtree_node_t *nil = _NIL(rbtree);
        while (pTmp != nil) {
            if (key <= pTmp->key) {
                node = pTmp;
                pTmp = pTmp->left;
            } else {
                pTmp = pTmp->right;
            }
        }
        // if node is default NULL, return minimum node of the tree
        return (node != NULL) ? node : util_rbtree_min(rbtree);
    }
    return NULL;
}

util_rbtree_node_t* util_rbsubtree_min(util_rbtree_node_t *node,
                                       util_rbtree_node_t *sentinel) {
    if (node == sentinel) {
        return NULL;
    }
    while (node->left != sentinel) {
        node = node->left;
    }
    return node;
}

util_rbtree_node_t* util_rbsubtree_max(util_rbtree_node_t *node,
                                       util_rbtree_node_t *sentinel) {
    if (node == sentinel) {
        return NULL;
    }
    while (node->right != sentinel) {
        node = node->right;
    }
    return node;
}

void util_rbtree_mid_travel(util_rbtree_t *rbtree,
                            void (*opera)(util_rbtree_node_t *, void *),
                            void *data) {
    if (rbtree != NULL && ! util_rbtree_isempty(rbtree)) {
        rbtree_mid_travel(rbtree->root, _NIL(rbtree), opera, data);
    }
}

void rbtree_mid_travel(util_rbtree_node_t *node,
                       util_rbtree_node_t *sentinel,
                       void (*opera)(util_rbtree_node_t *, void *),
                       void *data) {
    if (node->left != sentinel) {
        rbtree_mid_travel(node->left, sentinel,  opera, data);
    }
    opera(node, data);
    if (node->right != sentinel) {
        rbtree_mid_travel(node->right, sentinel,  opera, data);
    }
}
