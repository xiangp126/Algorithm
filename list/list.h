#ifndef _LIST_H_
#define _LIST_H_

#include "config.h"

typedef struct list_node_s list_node_t;
typedef struct list_s      list_t;

struct list_node_s {
    list_node_t *prev;
    list_node_t *next;
    void *data;
};

/*
 * s denotes structure, t for type
 *
 * list_s
 *
 *   --------- --------- --------- -------- ----------
 *  |  head * | tail *  |  count  | free() |  dump()  |
 *   --------- ---------  --------- -------- ---------
 *
 * head:  points to the first element of the list
 * tail:  points to the last element of the list
 * count: total elements the list has
 * free: free func of the list
 * dump: dump func of the list
 */
struct list_s {
    list_node_t *head;
    list_node_t *tail;
    uint count;
    void (*freeFunc)(void *);
    void (*dumpFunc)(void *);
};

#define LIST_HEAD(list)       (list->head)
#define LIST_SIZE(list)       (list->count)
#define LIST_TAIL_DATA(list)  (list->tail->data)
#define LIST_ISEMPTY(list)    ((list == NULL) || (list->head == NULL) \
                                              || (list->tail == NULL))
#define LIST_NODE_NEXT(node)  (node = node->next)
#define LIST_NODE_DATA(node)  (node->data)

#ifdef __cplusplus
extern "C" {
#endif

/*
 * list_init | init a list
 * @free_func: pointer to the free function
 * @dump_func: pointer to the dump function
 * @return new list pointer
 */
list_t *list_init(void (*free_func)(void *), void (*dump_func)(void *));


#ifdef __cplusplus
}
#endif

#endif /* ifndef _LIST_H_ */
