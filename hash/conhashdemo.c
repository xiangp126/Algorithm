#include "conhash.h"

#define NODECNT 5
conhash_node_t conhashNodes[NODECNT];

static void conhash_vnode_opera(util_rbtree_node_t *node, void *data);

int main(int argc, char *argv[])
{
    conhash_node_t *node;
    char buff[BUFSIZ];
    conhash_t *conhash = conhash_init(NULL);

    /*
     *
     *                           key (hashVal)
     *                          /
     *                    rbnode
     *                   /      \
     *          vnodeTree        data * -> hashVal
     *        /          \ ...             node * -> identity
     * conhash  vnodeCnt                             replicas
     *        \                                      flag
     *          hashfunc
     *
     *
     */
    if (conhash != NULL) {
        conhash_set_node(&conhashNodes[0], "titanic", 32);
        conhash_set_node(&conhashNodes[1], "terminator2018", 24);
        conhash_set_node(&conhashNodes[2], "Xenomorph", 25);
        conhash_set_node(&conhashNodes[3], "True Lies", 10);
        conhash_set_node(&conhashNodes[4], "avantar", 48);

        conhash_add_node(conhash, &conhashNodes[0]);
        conhash_add_node(conhash, &conhashNodes[1]);
        conhash_add_node(conhash, &conhashNodes[2]);
        conhash_add_node(conhash, &conhashNodes[3]);
        conhash_add_node(conhash, &conhashNodes[4]);

        printf("virtual nodes number %d\n", conhash_vnode_cnt(conhash));
        printf("the hashing results--------------------------------------:\n");

        /* util_rbtree_mid_travel(&conhash->vnodeTree, conhash_vnode_opera, NULL); */

        for(int idx = 0; idx < 20; idx++) {
            snprintf(buff, BUFSIZ - 1, "James.km%03d", idx);
            node = conhash_lookup(conhash, buff);
            if(node) {
                printf("[%16s] is in node: [%16s]\n", buff, node->identity);
            }
        }
    }

    return 0;
}

void conhash_vnode_opera(util_rbtree_node_t *rbnode, void *data) {
    if (rbnode != NULL) {
        conhash_vnode_t *vnode = (conhash_vnode_t *)rbnode->data;
        printf("Node key = %lu, data = %s\n", vnode->hash, vnode->node->identity);
    }
}
