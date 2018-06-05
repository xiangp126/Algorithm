#include <stdio.h>
#include <stdlib.h>
#include "util_rbtree.h"

#define N 10

int main(int argc, char *argv[])
{
    util_rbtree_t *rbtree = (util_rbtree_t *)malloc(sizeof(util_rbtree_t));
    util_rbtree_init(rbtree);

    for (int i = 0; i < N; ++i) {
        // util_rbtree_insert(rbtree, node);
    }
    util_rbtree_node_t *node = (util_rbtree_node_t *)malloc(sizeof(util_rbtree_node_t));
    node->key = 3;
    util_rbtree_insert(rbtree, node);

    return 0;
}
