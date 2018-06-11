/*
 * RB-Tree implementation and check source
 * Copyright by (C) 2018 PENG hi.pxiang@gmail.com
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "util_rbtree.h"

#define N 100000
#define DEBUG 1
/* sleep time unit second */
#define SLEEPTIME 4

void util_rbnode_opera(util_rbtree_node_t *node, void *data);
inline void ECHO_TIME(const char *str, time_t startClock, time_t endClock);

/*
 * Check rbtree if works well
 * 1> insert 100 0000 nodes
 * 2> delete 10  0000 nodes
 * 3> in-order travel the tree
 */
int main(int argc, char *argv[])
{
    util_rbtree_t *rbtree = (util_rbtree_t *)malloc(sizeof(util_rbtree_t));
    if (rbtree == NULL) {
        oops("malloc rbtree failed");
    }
    util_rbtree_init(rbtree);
    srand((unsigned)time(0));

    /* start to insert node */
    time_t insertStart, insertEnd;
    insertStart = clock();
    for (int i = 0; i < N; ++i) {
        char *str = (char *)malloc(BUFSIZ);
        memset(str, '\0', BUFSIZ);

        util_rbtree_node_t *node = (util_rbtree_node_t *)malloc(sizeof(util_rbtree_node_t));
        if (node == NULL) {
            oops("malloc node failed");
        }

        snprintf(str, BUFSIZ, "River%d",  i + 1);

        node->key = i + 1;
        node->data = (void *)str;
        util_rbtree_insert(rbtree, node);
        printf("%d th Node inserted\n", i + 1);
    }
    insertEnd = clock();

#if DEBUG
    /* mid travel the whole tree */
    printf("\nMid Travel the RB-Tree:\n");
    util_rbtree_mid_travel(rbtree, util_rbnode_opera, (void *)0);
#endif
    ECHO_TIME("Insert", insertStart, insertEnd);
    printf("\nRB-Tree Size: %d\n", rbtree->size);
    printf("\nRB-Tree Height: %d\n", util_rbtree_height(rbtree));
    /* unit second */
    sleep(SLEEPTIME);

#if 1
    /*
     * Check to search a Node, record the time
     *
     * Node key = 16623759665, data = River872339
     */
    time_t searchStart, searchEnd;
    util_key_t key = 16623759665;

    printf("\nWant to Search Node Key: %lu", key);
    searchStart = clock();
    util_rbtree_node_t *pF = util_rbtree_search(rbtree, key);
    searchEnd = clock();

    ECHO_TIME("Search", searchStart, searchEnd);
    /* util_rbnode_opera(pF, NULL); */
    sleep(SLEEPTIME);
#endif

    /*
     * Check to delete a Node, record the time
     *
     * Before delete
     * Node key = 16359823583, data = River1040
     * Node key = 16423966950, data = River8254
     * Node key = 16456595410, data = River55784
     * Node key = 16515287870, data = River86997
     * Node key = 16540353187, data = River7257
     *
     * Will delete
     * Node key = 16456595410, data = River55784
     */

    time_t delStart, delEnd;

    printf("\nWant to Delete Node Key: %lu", key);
    sleep(SLEEPTIME);

    delStart = clock();
    key = 16456595410;
    pF = util_rbtree_search(rbtree, key);
    util_rbtree_delete(rbtree, pF);
    delEnd = clock();

    ECHO_TIME("Delete", delStart, delEnd);

#if 0
    /* start to insert node */
    insertStart = clock();
    for (int i = 0; i < N; ++i) {
        char *str = (char *)malloc(BUFSIZ);
        memset(str, '\0', BUFSIZ);

        util_rbtree_node_t *node = (util_rbtree_node_t *)malloc(sizeof(util_rbtree_node_t));
        if (node == NULL) {
            oops("malloc node failed");
        }

        snprintf(str, BUFSIZ, "River%d",  i + 1);

        node->key = i + 1;
        node->data = (void *)str;
        util_rbtree_insert(rbtree, node);
        printf("%d th Node inserted\n", i + 1);
    }
    insertEnd = clock();
#endif

#if DEBUG
    /* mid travel the whole tree */
    printf("\nInorder Travel the RB-Tree:\n");
    sleep(SLEEPTIME);
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
        printf("Node key = %lu, data = %s\n", node->key, (char *)node->data);
    }
}

void ECHO_TIME(const char *str, time_t startClock, time_t endClock) {
    time_t elapsedTime = ((endClock - startClock) * 1000000)
                                             / (double)CLOCKS_PER_SEC;
    printf("\n%s Time Elapsed: %ld ms %ld us\n", str, elapsedTime / 1000,
                                                      elapsedTime % 1000);
}
