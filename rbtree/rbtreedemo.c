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

#define N       100000
#define DEBUG   0
#define BUFFER_SIZE 20
/* maximum key value */
#define KEY_MAX N
/* sleep time unit second */
#define SLEEPTIME 4
util_rbtree_node_t rbtreeNodes[N];

/*
 * rbnode_handle_data | handle data of the node
 * @node: the node to handle
 * @return void
 */
static void rbnode_handle_data(util_rbtree_node_t *node);
static inline
void ECHO_TIME(const char *str, time_t startClock, time_t endClock);
/* need implement by youself, for what exactly node->void points to did known */
void rbtree_free_node(util_rbtree_node_t *node);
void rbtree_free_tree(util_rbtree_t *rbtree);

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
        char *str = (char *)malloc(BUFFER_SIZE);
        memset(str, '\0', BUFFER_SIZE);
        snprintf(str, BUFFER_SIZE, "River%d",  i + 1);

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
    util_rbtree_mid_travel(rbtree, rbnode_handle_data);
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
        rbnode_handle_data(pF);
    }
    ECHO_TIME("Search", searchStart, searchEnd);
    /* rbnode_handle_data(pF); */
    sleep(SLEEPTIME);

#if 1
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

        pF = util_rbtree_search(rbtree, key);
        if (pF == NULL) {
            printf(" Not Found\n");
        } else {
            printf(" Found\n");
            rbnode_handle_data(pF);
            util_rbtree_delete(rbtree, pF);
            rbtree_free_node(pF);
        }
    }
    delEnd = clock();

    /* rbnode_handle_data(pF); */
    ECHO_TIME("\nDelete", delStart, delEnd);
    sleep(SLEEPTIME);
#endif

#if 0
    /* start to insert node */
    insertStart = clock();
    for (int i = 0; i < N; ++i) {
        char *str = (char *)malloc(BUFFER_SIZE);
        memset(str, '\0', BUFFER_SIZE);

        util_rbtree_node_t *node =
            (util_rbtree_node_t *)malloc(sizeof(util_rbtree_node_t));
        if (node == NULL) {
            oops("malloc node failed");
        }

        snprintf(str, BUFFER_SIZE, "River%d",  i + 1);

        node->key = i + 1;
        node->data = (void *)str;
        util_rbtree_insert(rbtree, node);
        printf("%d th Node inserted\n", i + 1);
    }
    insertEnd = clock();
#endif

    /* mid travel the whole tree */
    printf("\nInorder Travel the RB-Tree:\n");
    sleep(SLEEPTIME);
#if DEBUG
    util_rbtree_mid_travel(rbtree, rbnode_handle_data);
#endif
    printf("\nRB-Tree Size: %d\n", rbtree->size);
    printf("\nRB-Tree Height: %d\n", util_rbtree_height(rbtree));
    printf("\n");

    /*
     * free this tree safely
     */
    rbtree_free_tree(rbtree);
    return 0;
}

/*
 * rbnode_handle_data | handle data of the tree node
 * @node: the node to handle
 * @return void
 */
void rbnode_handle_data(util_rbtree_node_t *node) {
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

void rbtree_free_node(util_rbtree_node_t *node) {
    char *str = (char *)node->data;
    free(str);
    /* node here was not malloc in Heap */
    /* free(node); */
}

void rbtree_free_tree(util_rbtree_t *rbtree) {
    if (rbtree != NULL) {
        while (! util_rbtree_isempty(rbtree)) {
            /* delete from root node */
            util_rbtree_node_t *node = rbtree->root;
            util_rbtree_delete(rbtree, node);
            rbtree_free_node(node);
        }
        free(rbtree);
    }
}
