/*
 * impmelented by hi.pxiang@gmail.com
 * modified from linux kernel
 */
#ifndef _LIST_H_
#define _LIST_H_

#include "config.h"

/*
 * list_head_t double-linked circular list
 * list was embeded into the structure itself
 * @type: the structure
 * @list: member of the @type
 * @head: head entry of the list
 *
 *                type1                   type2
 *                +-------------+         +-------------+
 *                |             |         |             |
 *                +-------------+         +-------------+
 *                |             |         |             |
 *                +-------------+         +-------------+
 *   head ------> | list_head_t | ------> | list_head_t | ------> ...
 *        <-----  | list        | <-----  | list        | <-----  ...
 *                +-------------+         +-------------+
 *                | data3       |         | data3       |
 *                +-------------+         +-------------+
 *
 *
 *              typem                   typen
 *              +-------------+         +-------------+
 *              | data1       |         | data1       |
 *              +-------------+         +-------------+
 *              | data2       |         | data2       |
 *              +-------------+         +-------------+
 *      ------> | list_head_t | ------> | list_head_t | ------> head
 *      <-----  | list        | <-----  | list        | <----- (circular list)
 *              +-------------+         +-------------+
 *              | data3       |         | data3       |
 *              +-------------+         +-------------+
 *
 */
typedef struct list_head_s list_head_t;

struct list_head_s {
    list_head_t *prev;
    list_head_t *next;
};

/*
 * offsetof - get the offset of member in type
 */
#ifndef offsetof
#define offsetof(type, member) ((size_t) &((type *)0)->member)
#endif

/*
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct @member was embedded in.
 * @member:	the name of the member within the struct.
 */
#ifndef container_of
#define container_of(ptr, type, member) ({ \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
    (type *)( (char *)__mptr - offsetof(type,member) );})
#endif

#define LIST_POISON1  ((void *) 0x00100100)
#define LIST_POISON2  ((void *) 0x00200200)

#define LIST_HEAD_INIT(head) {&(head), &(head)}
#define LIST_HEAD(head) list_head_t head = LIST_HEAD_INIT(head)
#define INIT_LIST_HEAD(head) do { \
    (head)->next = (head); \
    (head)->prev = (head); \
} while(0)


#ifdef __cplusplus
extern "C" {
#endif

/*
 * __list_add insert new one between two consecutive entries
 * @newNode: the node to insert
 * @prevNode: previous one after newNode inserted
 * @nxtNode:  next one after newNode inserted
 * @return void
 */
static inline void __list_add(list_head_t *newNode, list_head_t *prevNode,
                              list_head_t *nxtNode) {
    nxtNode->prev = newNode;
    newNode->next = nxtNode;
    newNode->prev = prevNode;
    prevNode->next = newNode;
}

/*
 * list_head_add add a new one after the specified head
 * @newNode: the one to add
 * @head: list head to add it after
 * @return void
 */
static inline void list_head_add(list_head_t *newNode, list_head_t *head) {
    __list_add(newNode, head, head->next);
}

/*
 * list_tail_add add a new one before the specified head
 * @newNode: the one to add
 * @head: list head to add it before
 * @return
 */
static inline void list_tail_add(list_head_t *newNode, list_head_t *head) {
    __list_add(newNode, head->prev, head);
}

/*
 * __list_del delete an entry by marking prevNode / nxtNode point
 * to each other
 */
static inline void __list_del(list_head_t *prevNode, list_head_t *nxtNode) {
    nxtNode->prev = prevNode;
    prevNode->next = nxtNode;
}

/*
 * list_head_del delete an entry from the list
 * @delNode: the one to delete
 */
static inline void list_head_del(list_head_t *delNode) {
    __list_del(delNode->prev, delNode->next);
    delNode->prev = LIST_POISON1;
    delNode->next = LIST_POISON2;
}

/*
 * list_del_init delete an entry from the list and reinitialize it
 */
static inline void list_del_init(list_head_t *delNode) {
    __list_del(delNode->prev, delNode->next);
    INIT_LIST_HEAD(delNode);
}

/*
 * list_is_first test whether @node is the first one in @head
 * @node: the entry to test
 * @head: the head of the list
 */
static inline int list_is_first(const list_head_t *node,
                                const list_head_t *head) {
    return (node->prev == head);
}

/*
 * list_is_last test whether @node is the last one in @head
 * @node: the one to test
 * @head: head of the list
 */
static inline int list_is_last(const list_head_t *node,
            const list_head_t *head) {
    return (node->next == head);
}

/*
 * list_empty - test if the list is empty
 * @head: head of the list
 */
static inline int list_empty(const list_head_t *head) {
    return head->next == head;
}

/*
 * list_entry - get the struct for this entry
 * @ptr: pointer to one @member
 * @type: type of the struct that @member was embeded in
 * @menber: the name of the member within the struct
 */
#define list_entry(ptr, type, member) container_of(ptr, type, member)

/*
 * list_first_entry - get the first entry from a list
 * @head: head of the list
 * @type: type of the struct that @member was embeded in
 * @menber: the name of the member within the struct
 */
#define list_first_entry(head, type, member) \
    list_entry((head)->next, type, member)

/*
 * list_for_each_entry interate over list of given type
 * @pos: the type * to use as a loop counter
 * @head: head of the list
 * @member: the name of the member within the list structure
 */
#define list_for_each_entry(pos, head, member) \
    for (pos = list_entry((head)->next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = list_entry(pos->member.next, typeof(*pos), member))

#ifdef __cplusplus
}
#endif

#endif /* ifndef _LIST_H_ */
