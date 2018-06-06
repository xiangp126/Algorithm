#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util_rbtree.h"
#include "md5.h"

#define N 100

void util_rbnode_opera(util_rbtree_node_t *node, void *data);
void md5_digest(const uchar *str, uchar *digest);
ulong hash_def(const char *str);

int main(int argc, char *argv[])
{
    util_rbtree_t *rbtree = (util_rbtree_t *)malloc(sizeof(util_rbtree_t));
    util_rbtree_init(rbtree);

    for (int i = 0; i < N; ++i) {
        char *str = (char *)malloc(BUFSIZ);
        memset(str, '\0', BUFSIZ);

        util_rbtree_node_t *node = (util_rbtree_node_t *)malloc(sizeof(util_rbtree_node_t));
        if (node == NULL) {
            oops("malloc node failed");
        }

        // node->left = _NIL(rbtree);
        // node->right = _NIL(rbtree);
        snprintf(str, BUFSIZ, "River%d",  i + 1);

        node->key = hash_def(str);
        node->data = (void *)str;
        util_rbtree_insert(rbtree, node);
    }

    util_rbtree_mid_travel(rbtree, util_rbnode_opera, (void *)0);

    return 0;
}

/*
 * util_rbnode_opera
 * @node: the node to handle
 * @data:
 */
void util_rbnode_opera(util_rbtree_node_t *node, void *data) {
    if (node != NULL) {
        printf("Node key = %lu, data = %s\n", node->key, node->data);
    }
}

/*
 * hash_def
 * @str: input string for hashing
 * return hash value
 */
ulong hash_def(const char *str) {
    ulong hash = 0;
    uchar digest[16];
    md5_digest((const uchar *)str, digest);

    /* use successive 4-bytes from hash as numbers */
    for(int i = 0; i < 4; i++) {
        hash += ((long)(digest[i*4 + 3]&0xFF) << 24)
              | ((long)(digest[i*4 + 2]&0xFF) << 16)
              | ((long)(digest[i*4 + 1]&0xFF) <<  8)
              | ((long)(digest[i*4 + 0]&0xFF));
    }
    return hash;
}

void md5_digest(const uchar *str, uchar *digest) {
    md5_state_t md5state;

    md5_init(&md5state);
    /* strlen(const char *) */
    md5_append(&md5state, str, strlen((const char *)str));
    md5_finish(&md5state, digest);
}
