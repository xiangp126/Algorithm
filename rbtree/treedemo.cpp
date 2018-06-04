#include <iostream>
#include "util_rbtree.h"

using namespace std;

int main(int argc, char *argv[])
{
    util_rbtree_t *rbtree = (util_rbtree_t *)malloc(sizeof(util_rbtree_t));
    util_rbtree_init(rbtree);

    util_rbtree_node_t *node = (util_rbtree_node_t *)malloc(sizeof(util_rbtree_node_t));
    node->data = (void *)("Hello World!");
    node->key = 3;
    util_rbtree_insert(rbtree, node);

    util_rbtree_node_t *pNode = util_rbtree_search(rbtree, 3);
    cout << pNode->key << endl;

    return 0;
}
