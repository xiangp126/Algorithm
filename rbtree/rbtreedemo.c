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

#define N       1000000
#define DEBUG   1
#define KEY_MAX 1000000
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

        node->key = rand() % KEY_MAX;
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
     * random key to search
     */
    time_t searchStart, searchEnd;
    util_key_t key = rand() % KEY_MAX;

    printf("\nWant to Search Node Key: %lu", key);
    searchStart = clock();
    util_rbtree_node_t *pF = util_rbtree_search(rbtree, key);
    searchEnd = clock();

    if (pF == NULL) {
        printf(" Not Found\n");
    } else {
        printf(" Found\n");
        util_rbnode_opera(pF, NULL);
    }
    ECHO_TIME("Search", searchStart, searchEnd);
    /* util_rbnode_opera(pF, NULL); */
    sleep(SLEEPTIME);
#endif

    /*
     * Check to delete a Node, record the time
     *
     * random delete
     */
    time_t delStart, delEnd;
    key = rand() % KEY_MAX;

    printf("\nWant to Delete Node Key: %lu", key);
    sleep(SLEEPTIME);

    delStart = clock();
    pF = util_rbtree_search(rbtree, key);
    util_rbtree_delete(rbtree, pF);
    delEnd = clock();

    if (pF == NULL) {
        printf(" Not Found\n");
    } else {
        printf(" Found\n");
        util_rbnode_opera(pF, NULL);
    }
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
    printf("%s Time Elapsed: %ld ms %ld us\n", str, elapsedTime / 1000,
                                                      elapsedTime % 1000);
}
