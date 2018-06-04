#include <stdio.h>
#include <stdlib.h>
#include "util_rbtree.h"

#define _NULL(rbtree) (&((rbtree)->null))

static void rbtree_insert_fixup(util_rbtree_t *rbtree, util_rbtree_node_t *node);
static void rbtree_left_rotate(util_rbtree_t *rbtree, util_rbtree_node_t *node);
static void rbtree_right_rotate(util_rbtree_t *rbtree, util_rbtree_node_t *node);

void util_rbtree_init(util_rbtree_t *rbtree) {
    if (rbtree != NULL) {
        util_rbt_black(_NULL(rbtree));
        rbtree->root = _NULL(rbtree);
        rbtree->size = 0;
    }
}

// An insert node is deemed color to Red
void util_rbtree_insert(util_rbtree_t *rbtree, util_rbtree_node_t *node) {
    util_rbtree_node_t *x, *y;
    if ((rbtree == NULL) && (node == NULL) && (node == _NULL(rbtree))) {
        return;
    }
    // the tree is empty
    if (rbtree->root == _NULL(rbtree)) {
        rbtree->root = node;
        node->parent = _NULL(rbtree);
    } else {
        x = rbtree->root;
        while (x != _NULL(rbtree)) {
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
    node->left = _NULL(rbtree);
    node->right = _NULL(rbtree);
    util_rbt_red(node);
    // fix up insert
    rbtree_insert_fixup(rbtree, node);
    rbtree->size++;
}

// insert may violate the rbtree properties, need fix up the tree
void rbtree_insert_fixup(util_rbtree_t *rbtree, util_rbtree_node_t *node) {
    /*
     * N for new node, P for parent, U for uncle, G for grandparent
     *
     *          |
     *          G
     *        /   \
     *       P     U
     *     /
     *    N
     *
     */
    // np denotes node's parent, nu for uncle, ng for grandparent
    util_rbtree_node_t *np, *nu, *ng;
    // fix up the property recursive
    while (util_rbt_isred(node->parent)) {
        np = node->parent;
        ng = np->parent;
        // if parent is the left child of its parent
        if (np == ng->left) {
            nu = np->right;
            // case 1: parent & uncle are red
            if (util_rbt_isred(nu)) {
                /*
                 * N for new node, P for parent, U for uncle, G for grandparent
                 * R for red, B for black
                 *
                 *          |                      |                  |
                 *          G                      B                  R
                 *        /   \       or         /   \      -->     /   \
                 *       P     U                R     R           B      B
                 *     /                      /                  /
                 *    N                      R                  R
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
                     * <1> Rotate at P
                     * <2> swap P and N to prepar the following right rotation
                     *
                     *         |                    |                     |
                     *         G        LR          G      SWAP           G
                     *       /   \      -->       /   \                 /   \
                     *      P     U              N     U      np -->   N     U
                     *    /   \                /                     /
                     *   S     N              P                     P  <-- node
                     *                      /                     /
                     *                     S                     S
                     *
                     *               |
                     *               N
                     *   RR        /   \
                     *   -->      P      G
                     *          /         \
                     *         S           U
                     *
                     * Or
                     * R for red, B for black
                     *
                     *         |                       |                     |
                     *         B        LR             B      color          R
                     *       /   \      -->          /   \    ---->        /   \
                     *      R     B                 R     B               B     B
                     *    /   \                   /                     /
                     *   B     R                 R                     R
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
                } else {
                    // case 3: parent read, uncle black, node is left child
                    /*
                     * N for new node, P for parent, U for uncle
                     * G for grandparent, S for sibling
                     *
                     *         |                    |
                     *         G                    P
                     *       /   \      -->       /   \
                     *      P     U              N     G
                     *    /   \                      /   \
                     *   N     S                    S     U
                     *
                     * Or
                     * R for red, B for black
                     *
                     *         |                    |                 |
                     *         B                    R                 B
                     *       /   \     -->        /   \      -->    /   \
                     *      R     B              B     B           R     R
                     *    /   \                /   \                   /   \
                     *   R     B              R     B                 B     B
                     *
                     */
                    util_rbt_black(np);
                    util_rbt_red(ng);
                    /* right rotate at New Node's grandparent */
                    rbtree_right_rotate(rbtree, ng);
                }
            }
        }
    }

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
    if (rclc != _NULL(rbtree)) {
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
    if (lcrc != _NULL(rbtree)) {
        lcrc->parent = node;
    }
}
