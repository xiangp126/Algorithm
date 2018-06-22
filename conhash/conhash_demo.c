/*
 * Copyright (C) hi.pxiang@gmail.com
 */

#include "conhash.h"

#define NODECNT     5
#define ECHO_TRAVEL 0
conhash_node_t conhashNodes[NODECNT];

static void rbnode_travel_func(util_rbtree_node_t *node);
static void conhash_dump(conhash_t *conhash, char *buff);

int main(int argc, char *argv[])
{
    char buff[BUFSIZ];
    conhash_t *conhash = conhash_init(NULL);

    /*
     *
     *                             key (hashVal)
     *                            /
     *                    rbnode *
     *                   /        \
     *          vnodeTree          data * -> hashVal
     *        /          \ ...               conhash_node_t *node -> identity
     * conhash  vnodeCnt                                             replicas
     *        \                                                      flag
     *          hashfunc
     *
     *
     */
    if (conhash != NULL) {
        conhash_set_node(&conhashNodes[0], "China", 32);
        conhash_set_node(&conhashNodes[1], "America", 24);
        conhash_set_node(&conhashNodes[2], "Russia", 25);
        conhash_set_node(&conhashNodes[3], "Canada", 10);
        conhash_set_node(&conhashNodes[4], "England", 48);

        conhash_add_node(conhash, &conhashNodes[0]);
        conhash_add_node(conhash, &conhashNodes[1]);
        conhash_add_node(conhash, &conhashNodes[2]);
        conhash_add_node(conhash, &conhashNodes[3]);
        conhash_add_node(conhash, &conhashNodes[4]);

        printf("Total Virtual Node Count : %d\n", conhash_vnode_cnt(conhash));
        printf("------------------ Consistent Hash ------------------------\n");

#if ECHO_TRAVEL
        printf("\nIn-Order travel RB-Tree\n");
        util_rbtree_mid_travel(&conhash->vnodeTree, rbnode_travel_func);
#endif

        conhash_dump(conhash, buff);

        conhash_node_t *delNode = &conhashNodes[1];
        conhash_del_node(conhash, &conhashNodes[1]);
        printf("\nDelete Node [%s], Total Virtual Node Count: %d\n\n",
                            delNode->identity, conhash_vnode_cnt(conhash));
        printf("------------------ Consistent Hash ------------------------\n");
#if ECHO_TRAVEL
        printf("\nIn-Order travel RB-Tree\n");
        util_rbtree_mid_travel(&conhash->vnodeTree, rbnode_travel_func);
#endif

        conhash_dump(conhash, buff);
    }

    /*
     * free this consistent hash table
     */
    conhash_free(conhash);
    return 0;
}

/*
 * conhash_dump | dump message in the consistent hash table
 * @conhash: the consistent hash table
 * @buff: used for buffer
 * return void
 */
void rbnode_travel_func(util_rbtree_node_t *rbnode) {
    if (rbnode != NULL) {
        conhash_vnode_t *vnode = (conhash_vnode_t *)rbnode->data;
        printf("Node key = %lu, data = %s\n", vnode->hash,
                                              vnode->node->identity);
    }
}

/*
 * conhash_dump | dump message in the consistent hash table
 * @conhash: the consistent hash table
 * @buff: used for buffer
 * return void
 */
void conhash_dump(conhash_t *conhash, char *buff) {
    conhash_node_t *node;
    for(int idx = 0; idx < 20; idx++) {
        snprintf(buff, BUFSIZ - 1, "PENG%03d", idx);
        node = conhash_lookup(conhash, buff);
        if(node) {
            printf("[%10s ] ------ Hash To ------> [%10s ]\n",
                        buff, node->identity);
        }
    }
}
