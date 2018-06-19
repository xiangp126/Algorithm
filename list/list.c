#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*
 * list_init | init a list
 * @free_func: pointer to the free function
 * @dump_func: pointer to the dump function
 * @return new list pointer
 */
list_t *list_init(void (*free_func)(void *), void (*dump_func)(void *)) {
    list_t *nList = (list_t *)malloc(sizeof(list_t));
    if (nList == NULL) {
        oops("malloc list_t failed!");
    }
    nList->freeFunc = free_func;
    nList->dumpFunc  = dump_func;
    nList->count = 0;
    nList->head = nList->tail = NULL;

    return nList;
}

/*
 * list_add | add a node into the list
 * @list:
 * @data:
 * @return
 */
void list_add(list_t *list, void *data) {
    list_node_t *node = (list_node_t *)malloc(sizeof(list_node_t));
    if (! node) {
        oops("malloc list node failed!");
    }

    node->data = data;

    node->prev = list->tail;
    if (list->head == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }

    list->tail = node;
    ++list->count;
}

void list_free(list_t *list) {
    if (list != NULL) {
        
    }
}

void list_dump(list_t *list) {
    list_node_t *node = LIST_HEAD(list);
    while (node != NULL) {
        if (list->dumpFunc != NULL) {
            list->dumpFunc(node->data);
        }
        node = node->next;
    }
}
