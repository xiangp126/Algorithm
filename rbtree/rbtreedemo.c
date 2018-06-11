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

/* #define N       1000000 */
#define N       2
#define DEBUG   1
/* maximum key value */
#define KEY_MAX N
/* sleep time unit second */
#define SLEEPTIME 4
util_rbtree_node_t rbtreeNodes[N];

/*
 * treenode_data_handle | handle data of the node
 * @node: the node to handle
 * @return void
 */
static void treenode_data_handle(util_rbtree_node_t *node);
static inline
void ECHO_TIME(const char *str, time_t startClock, time_t endClock);

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
    /* random seed */
    srand((unsigned)time(0));

    /* start to insert node */
    time_t insertStart, insertEnd;
    util_rbtree_node_t *node;

    insertStart = clock();
    for (int i = 0; i < N; ++i) {
        /* every node should has its own str */
        char *str = (char *)malloc(BUFSIZ);
        memset(str, '\0', BUFSIZ);
        snprintf(str, BUFSIZ, "River%d",  i + 1);

        node = &rbtreeNodes[i];
        node->key = rand() % KEY_MAX;
        node->data = (void *)str;
        util_rbtree_insert(rbtree, node);
        printf("%d th Node inserted\n", i + 1);
    }
    insertEnd = clock();

#if DEBUG
    /* mid travel the whole tree */
    printf("\nMid Travel the RB-Tree:\n");
    util_rbtree_mid_travel(rbtree, treenode_data_handle);

#endif
    ECHO_TIME("Insert", insertStart, insertEnd);
    printf("\nRB-Tree Size: %d\n", rbtree->size);
    printf("RB-Tree Height: %d\n", util_rbtree_height(rbtree));
    /* unit second */
    sleep(SLEEPTIME);

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
        treenode_data_handle(pF);
    }
    ECHO_TIME("Search", searchStart, searchEnd);
    /* treenode_data_handle(pF); */
    sleep(SLEEPTIME);

    /*
     * Check to delete a Node, record the time
     *
     * random delete
     */
    time_t delStart, delEnd;
    delStart = clock();
    for (int i = 0; i < 100; ++i) {
        key = rand() % KEY_MAX;
        printf("\nWant to Delete Node Key: %lu", key);

        node = &rbtreeNodes[key];
        util_rbtree_delete(rbtree, node);
    }
    delEnd = clock();

    /* treenode_data_handle(pF); */
    ECHO_TIME("Delete", delStart, delEnd);
    sleep(SLEEPTIME);

    return 0;

#if 0
    /* start to insert node */
    insertStart = clock();
    for (int i = 0; i < N; ++i) {
        char *str = (char *)malloc(BUFSIZ);
        memset(str, '\0', BUFSIZ);

        util_rbtree_node_t *node =
            (util_rbtree_node_t *)malloc(sizeof(util_rbtree_node_t));
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
    util_rbtree_mid_travel(rbtree, treenode_data_handle);
    printf("\nRB-Tree Size: %d\n", rbtree->size);
    printf("\nRB-Tree Height: %d\n", util_rbtree_height(rbtree));
#endif

    printf("\n");

    return 0;
}

/*
 * treenode_data_handle | handle data of the tree node
 * @node: the node to handle
 * @return void
 */
void treenode_data_handle(util_rbtree_node_t *node) {
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
