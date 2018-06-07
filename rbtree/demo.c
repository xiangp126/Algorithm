#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "md5.h"
#include "util_rbtree.h"

/* #define N 1000000 */
#define N 10000
#define DEBUG 1

void util_rbnode_opera(util_rbtree_node_t *node, void *data);
void md5_digest(const uchar *str, uchar *digest);
ulong hash_def(const char *str);
inline void ECHO_TIME(const char *str, time_t startClock, time_t endClock);

int main(int argc, char *argv[])
{
    util_rbtree_t *rbtree = (util_rbtree_t *)malloc(sizeof(util_rbtree_t));
    util_rbtree_init(rbtree);

    srand((unsigned)time(0));
    time_t startClock, insertClock, searchClock, endClock;

    startClock = clock();
    for (int i = 0; i < N; ++i) {
        char *str = (char *)malloc(BUFSIZ);
        memset(str, '\0', BUFSIZ);

        util_rbtree_node_t *node = (util_rbtree_node_t *)malloc(sizeof(util_rbtree_node_t));
        if (node == NULL) {
            oops("malloc node failed");
        }

        snprintf(str, BUFSIZ, "River%d",  i + 1);

        node->key = hash_def(str);
        node->data = (void *)str;
        util_rbtree_insert(rbtree, node);
        printf("%d th Node inserted\n", i + 1);
    }
    insertClock = clock();

    /* mid travel the whole tree */
    printf("\nMid Travel the RB-Tree:\n");
    util_rbtree_mid_travel(rbtree, util_rbnode_opera, (void *)0);
    printf("\nRB-Tree Size: %d\n", rbtree->size);
    printf("\nRB-Tree Height: %d\n", util_rbtree_height(rbtree));

    /*
     * Check to search a Node, record the time
     *
     * Node key = 16623759665, data = River872339
     */
    util_key_t key = 16623759665;
    searchClock = clock();
    util_rbtree_node_t *pF = util_rbtree_search(rbtree, key);
    endClock = clock();

    ECHO_TIME("Insert", startClock, insertClock);
    ECHO_TIME("Search", searchClock, endClock);

    util_rbnode_opera(pF, NULL);

#if 1
    /*
     * Check to delete a Node, record the time
     *
     * Node key = 16359823583, data = River1040
     */
    key = 16359823583;
    pF = util_rbtree_search(rbtree, key);
    util_rbtree_delete(rbtree, pF);

    /* mid travel the whole tree */
    printf("\nMid Travel the RB-Tree:\n");
    util_rbtree_mid_travel(rbtree, util_rbnode_opera, (void *)0);
    printf("\nRB-Tree Size: %d\n", rbtree->size);
    printf("\nRB-Tree Height: %d\n", util_rbtree_height(rbtree));
#endif

    printf("\n");

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

void ECHO_TIME(const char *str, time_t startClock, time_t endClock) {
    time_t elapsedTime = ((endClock - startClock) * 1000000)
                                             / (double)CLOCKS_PER_SEC;
    printf("\n%s Time Elapsed: %ld ms %ld us\n", str, elapsedTime / 1000,
                                                      elapsedTime % 1000);
}
