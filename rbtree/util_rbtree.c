/*
 * RB-Tree implementation and check source
 * Copyright by (C) 2018 PENG hi.pxiang@gmail.com
 */
#include <stdio.h>
#include <stdlib.h>
#include "util_rbtree.h"

static void rbtree_left_rotate(util_rbtree_t *rbtree,
                               util_rbtree_node_t *node);
static void rbtree_right_rotate(util_rbtree_t *rbtree,
                                util_rbtree_node_t *node);
static void rbtree_insert_fixup(util_rbtree_t *rbtree,
                                util_rbtree_node_t *node);
static void rbtree_delete_fixup(util_rbtree_t *rbtree,
                                util_rbtree_node_t *node);
static void rbtree_mid_travel(util_rbtree_node_t *node,
                              util_rbtree_node_t *sentinel,
                              void (*opera)(util_rbtree_node_t *));
static int rbtree_get_height(util_rbtree_node_t *node,
                             util_rbtree_node_t *sentinel);
static void rbtree_transplant(util_rbtree_t *rbtree,
                              util_rbtree_node_t *orig,
                              util_rbtree_node_t *newt);

/*
 * initialize a RB-Tree
 */
void util_rbtree_init(util_rbtree_t *rbtree) {
    if (rbtree != NULL) {
        util_rbtree_node_t *nil = _NIL(rbtree);
        /*
         * clear NIL's link
         * set NIL color black
         *
         * It doesn't matter what NIL's other element was
         *
         * nil->left = nil;
         * nil->right = nil;
         */
        rbt_clear_link(nil);
        util_rbt_black(nil);

        rbtree->root = nil;
        rbtree->size = 0;
    }
}

/*
 * util_rbtree_insert
 * @rbtree: the RB-Tree
 * @node: the node to insert
 */
void util_rbtree_insert(util_rbtree_t *rbtree, util_rbtree_node_t *node) {
    if ((rbtree == NULL) || (node == NULL) || (node == _NIL(rbtree))) {
        return;
    }
    util_rbtree_node_t *pIter = rbtree->root;
    util_rbtree_node_t *pTmp = _NIL(rbtree);
    /* find out the insert position, indicated by pIter */
    while (pIter != _NIL(rbtree)) {
        pTmp = pIter;
        if (node->key < pIter->key) {
            pIter = pIter->left;
        } else {
            pIter = pIter->right;
        }
    }
    /* pIter points to the insert position, and pTmp is the parent */
    node->parent = pTmp;
    /* if tree is empty */
    if (pTmp == _NIL(rbtree)) {
        rbtree->root = node;
    } else {
        /* adjust parent's left & right pointer */
        if (node->key < pTmp->key) {
            pTmp->left = node;
        } else {
            pTmp->right = node;
        }
    }
    node->left  = _NIL(rbtree);
    node->right = _NIL(rbtree);
    /* always color newly inserted node to RED */
    util_rbt_red(node);
    rbtree_insert_fixup(rbtree, node);

    ++rbtree->size;
}

/*
 * rbtree_transplant | use for util_rbtree_delete
 *
 * replace subtree root with Node 'orig' by subtree root with Node 'newt'
 *
 * @rbtree: the RB-Tree
 * @orig: the subtree root with Node orig
 * @newt: the subtree root with Node newt
 * Did not handle the children of orig, leave for function call this to do it
 */
void rbtree_transplant(util_rbtree_t *rbtree, util_rbtree_node_t *orig,
                                              util_rbtree_node_t *newt) {
    /*
     * D for Node orig, S for Node newt
     *
     *            |                     |
     *            D                     S
     *          /   \      -->        /   \
     *         A     S               B     C
     *             /   \
     *            B     C
     *
     */
    /* if orig is the root */
    if (orig == rbtree->root) {
        rbtree->root = newt;
    } else {
        /* orig was left child of its parent */
        if (orig == orig->parent->left) {
            orig->parent->left = newt;
        } else {
            orig->parent->right = newt;
        }
    }
    /* first node's parent points to _NIL(rbtree) */
    newt->parent = orig->parent;
}

/*
 * util_rbtree_delete
 * @rbtree: the RB-Tree
 * @node: the node to delete
 * @return void
 */
void util_rbtree_delete(util_rbtree_t *rbtree, util_rbtree_node_t *node) {
    if (rbtree == NULL || util_rbtree_isempty(rbtree)
                       || node == NULL || node == _NIL(rbtree)) {
        return;
    }
    /*
     * pIter: the node will replace 'node'
     * pIterColor: record original color of *pIter
     * pTmp: temporary pointer
     */
    util_rbtree_node_t *pTmp;
    util_rbtree_node_t *pIter = node;
    util_color_t pIterColor = pIter->color;

    if (node->left == _NIL(rbtree)) {
         /* case 1: left child NIL */
        pTmp = node->right;
        rbtree_transplant(rbtree, node, node->right);
    } else {
        if (node->right == _NIL(rbtree)) {
            /* case 2: right child NIL */
            pTmp = node->left;
            rbtree_transplant(rbtree, node, node->left);
        }
        else {
            /*
             * case 3: both left & child are not NIL
             *
             * find the minimum from the right child subtree
             * pIter has no left child, so pTmp may be NIL
             * pIter will take place of 'node' and 'node' will be deleted,
             *   so below all link to pIter rather than 'node'
             */
            pIter = util_rbsubtree_min(node->right, _NIL(rbtree));
            pIterColor = pIter->color;
            pTmp = pIter->right;
            if (pIter->parent == node) {
                /* pIter is just (right) child of 'node' */
                pTmp->parent = pIter;
            } else {
                rbtree_transplant(rbtree, pIter, pIter->right);
                pIter->right = node->right;
                pIter->right->parent = pIter;
            }
            /*
             * call func transplant node with pIter
             * handle left child of pIter after call rbtree_transplant
             * use original node's color, so need not change the color
             */
            rbtree_transplant(rbtree, node, pIter);
            pIter->left = node->left;
            pIter->left->parent = pIter;
            pIter->color = node->color;
        }
    }

    rbt_clear_link(node);
    /*
     * free(node);
     * for node->data may points to other structure, so leave free(node)
     * to the function calls this 'delete'
     */

    if (pIterColor == BLACK) {
        rbtree_delete_fixup(rbtree, pTmp);
    }
    --rbtree->size;
}

/*
 * rbtree_delete_fixup | fixup RB-Tree property after delete operation
 * @rbtree: the RB-Tree
 * @node: the node may cause fixup
 */
void rbtree_delete_fixup(util_rbtree_t *rbtree, util_rbtree_node_t *node) {
    /*
     * ns denotes node's sibling
     */
    util_rbtree_node_t *ns;
    while (node != rbtree->root && node->color == BLACK) {
        /* node is the left child of its parent */
        if (node == node->parent->left) {
            ns = node->parent->right;
            /* node's sibling is red */
            if (util_rbt_isred(ns)) {
                /*
                 * case 1: node's sibling is red
                 */
                util_rbt_black(ns);
                util_rbt_red(node->parent);
                rbtree_left_rotate(rbtree, node->parent);
                ns = node->parent->right;
            }
            if (util_rbt_isblack(ns->left) && util_rbt_isblack(ns->right)) {
                /*
                 * case 2: node'sibling is black
                 * and left & right child all black
                 */
                util_rbt_red(ns);
                node = node->parent;
            } else {
                if (util_rbt_isblack(ns->right)) {
                    /*
                     * case 3: node’s sibling is black,
                     * sibling’s left child is red, and its right child is black
                     */
                    util_rbt_black(ns->left);
                    util_rbt_red(ns);
                    rbtree_right_rotate(rbtree, ns);
                    ns = node->parent->right;
                }
                /*
                 * case 4: node’s sibling w is black, and sibling’s right
                 * child is red
                 */
                ns->color = node->parent->color;
                util_rbt_black(node->parent);
                util_rbt_black(ns->right);
                rbtree_left_rotate(rbtree, node->parent);
                node = rbtree->root;
            }
        } else {
            /* node is the right child of its parent, symmetric operation */
            ns = node->parent->left;
            /* node's sibling is red */
            if (util_rbt_isred(ns)) {
                /*
                 * case 1: node's sibling is red
                 */
                util_rbt_black(ns);
                util_rbt_red(node->parent);
                rbtree_right_rotate(rbtree, node->parent);
                ns = node->parent->left;
            }
            if (util_rbt_isblack(ns->left) && util_rbt_isblack(ns->right)) {
                /*
                 * case 2: node'sibling is black
                 * and left & right child all black
                 */
                util_rbt_red(ns);
                node = node->parent;
            } else {
                if (util_rbt_isblack(ns->left)) {
                    /*
                     * case 3: node’s sibling is black,
                     * sibling’s left child is black, right child is red
                     */
                    util_rbt_black(ns->right);
                    util_rbt_red(ns);
                    rbtree_left_rotate(rbtree, ns);
                    ns = node->parent->left;
                }
                /*
                 * case 4: node’s sibling is black, and sibling’s left
                 * child is red
                 */
                ns->color = node->parent->color;
                util_rbt_black(node->parent);
                util_rbt_black(ns->left);
                rbtree_right_rotate(rbtree, node->parent);
                node = rbtree->root;
            }
        }
    }
    util_rbt_black(node);
}

/*
 * rbtree_insert_fixup | fixup RB-Tree property after insert operation
 * @rbtree: the RB-Tree
 * @node: the inserted node, may cause fixup
 */
void rbtree_insert_fixup(util_rbtree_t *rbtree, util_rbtree_node_t *node) {
    /* np denotes node's parent, nu for uncle, ng for grandparent */
    util_rbtree_node_t *np, *nu, *ng;
    while (util_rbt_isred(node->parent)) {
        np = node->parent;
        ng = np->parent;
        /* if parent is the left child of its parent (that is node's grandparent) */
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
            nu = ng->right;
            if (util_rbt_isred(nu)) {
                /*
                 * case 1: parent & uncle are red
                 *
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
                if (node == np->right) {
                    /*
                     * case 2: parent red, uncle black, node is right child
                     *
                     * N for new node, P for parent, U for uncle
                     * G for grandparent, S for sibling
                     * LR denotes for left rotate, RR for right rotate
                     * Manipulate:
                     * <1> Left Rotate at P
                     * <2> swap P and N to prepar the following right rotation
                     *
                     *         |                       |
                     *         G     LR at P           G
                     *       /   \   ------>         /   \
                     *      P     U                 N     U
                     *    /   \                   /
                     *   S     N                 P
                     *                         /
                     *                        S
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
                }
                /*
                 * case 3: parent red, uncle black, node is left child
                 *
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
                util_rbt_black(node->parent);
                util_rbt_red(node->parent->parent);
                /* right rotate at this node's grandparent */
                rbtree_right_rotate(rbtree, node->parent->parent);
            }
        } else {
            /* parent is the right child of its parent (that is node's grandparent)
             * Operation Symmetric
             *
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
            nu = ng->left;
            if (util_rbt_isred(nu)) {
                /*
                 * case 1: parent & uncle are red
                 *
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
                if (node == np->left) {
                    /*
                     * case 2: parent red, uncle black, node is left child
                     *
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
                }
                /*
                 * case 3: parent red, uncle black, node is right child
                 *
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
                util_rbt_black(node->parent);
                util_rbt_red(node->parent->parent);
                /* left rotate at this node's grandparent */
                rbtree_left_rotate(rbtree, node->parent->parent);
            }
        }
    }
    /* mark root as black */
    util_rbt_black(rbtree->root);
}

/*
 * rbtree_left_rotate
 * @rbtree: the RB-Tree
 * @node: the node centered to rotate
 * make 'node' left child of other's
 */
void rbtree_left_rotate(util_rbtree_t *rbtree, util_rbtree_node_t *node) {
    /*
     * np denotes node's parent, rc denotes right child, lc : left child
     *
     * N for new node, S for right child
     *
     *      |                       |
     *      N                       S
     *    /   \       -->         /   \
     *   A     S                 N     D
     *       /   \             /  \
     *      C     D           A    C
     *
     */
    util_rbtree_node_t *rc = node->right;
    util_rbtree_node_t *rclc = rc->left;

    /* make rclc be Node's right child */
    node->right = rclc;
    if (rclc != _NIL(rbtree)) {
        rclc->parent = node;
    }
    /* make rc take place of Node's position */
    rc->parent = node->parent;

    /* if 'node' is the root of the tree */
    if (node == rbtree->root) {
        rbtree->root = rc;
    } else {
        /* 'node' is the left child of its parent */
        if (node == node->parent->left) {
            node->parent->left = rc;
        } else {
            node->parent->right = rc;
        }
    }
    /* make Node be rc's left child */
    rc->left = node;
    node->parent = rc;
}

/*
 * rbtree_left_rotate
 * @rbtree: the RB-Tree
 * @node: the node centered to rotate
 * make 'node' right child of other's
 */
void rbtree_right_rotate(util_rbtree_t *rbtree, util_rbtree_node_t *node) {
    /*
     * np denotes node's parent, rc denotes left child, lc : left child
     *
     * S for node, N for left child
     * just the reverse operation of left rotation
     *
     *         |                       |
     *         S                       N
     *       /   \       -->         /   \
     *      N     D                 A     S
     *    /  \                          /   \
     *   A    C                        C     D
     *
     */
    util_rbtree_node_t *lc = node->left;
    util_rbtree_node_t *lcrc = lc->right;

    /* make lcrc be Node's left child */
    node->left = lcrc;
    if (lcrc != _NIL(rbtree)) {
        lcrc->parent = node;
    }
    /* make lc take place of Node's position */
    lc->parent = node->parent;

    /* if 'node' is the root of the tree */
    if (node == rbtree->root) {
        rbtree->root = lc;
    } else {
        /* 'node' is the left child of its parent */
        if (node == node->parent->left) {
            node->parent->left = lc;
        } else {
            node->parent->right = lc;
        }
    }
    /* make Node be rc's right child */
    lc->right = node;
    node->parent = lc;
}

/*
 * util_rbtree_search
 * @rbtree: the RB-Tree
 * @key: the item to compare in the node
 * return NULL if not found
 */
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

/*
 * util_rbtree_lookup
 * @rbtree: the RB-Tree
 * @key: the item to compare in the node
 * return the node meets requirement
 */
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
        /* if node is default NULL, return minimum node of the tree */
        return (node != NULL) ? node : util_rbtree_min(rbtree);
    }
    return NULL;
}

util_rbtree_node_t* util_rbsubtree_min(util_rbtree_node_t *node,
                                       util_rbtree_node_t *sentinel) {
    if (node == NULL || node == sentinel) {
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

/*
 * In-order travel a RB-Tree, read-only operation
 * T for root, L for left, R for right
 *
 *        T
 *      /   \       L -> T -> R
 *     L     R
 *
 * @rbtree: The RB-Tree
 * @nodefunc: function pointer to handle data of the node
 * @return void
 */
void util_rbtree_mid_travel(util_rbtree_t *rbtree,
                            void (*nodefunc)(util_rbtree_node_t *)) {
    if (rbtree != NULL && ! util_rbtree_isempty(rbtree)) {
        rbtree_mid_travel(rbtree->root, _NIL(rbtree), nodefunc);
    }
}

void rbtree_mid_travel(util_rbtree_node_t *node, util_rbtree_node_t *sentinel,
                       void (*nodefunc)(util_rbtree_node_t *)) {
    if (node->left != sentinel) {
        rbtree_mid_travel(node->left, sentinel,  nodefunc);
    }
    /* handle data of the node */
    nodefunc(node);
    if (node->right != sentinel) {
        rbtree_mid_travel(node->right, sentinel,  nodefunc);
    }
}

/*
 * util_rbtree_height
 * @rbtree: The RB-Tree tree
 * recursive method
 */
int util_rbtree_height(util_rbtree_t *rbtree) {
    if ((rbtree != NULL) && (! util_rbtree_isempty(rbtree))) {
        return rbtree_get_height(rbtree->root, _NIL(rbtree));
    }
    return 0;
}

int rbtree_get_height(util_rbtree_node_t *node, util_rbtree_node_t *sentinel) {
    int treeHeight = 0;
    if (node != sentinel) {
        int leftHeight = rbtree_get_height(node->left, sentinel);
        int rightHeight = rbtree_get_height(node->right, sentinel);
        treeHeight
            = leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
    }
    return treeHeight;
}
