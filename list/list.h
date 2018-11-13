/*
 * illustrated by hi.pxiang@gmail.com
 * modified from linux kernel
 */
#ifndef _LIST_H_
#define _LIST_H_

#include "config.h"

/*
 * list_head_t double-linked circular list
 * list was embeded into the structure itself
 * @type: the type of the structure @head points to
 * @list: embeded member of the @type
 * @head: the start entry of this double-linked circular list
 *
 * struct dpip_obj {
 *     struct list_head_s list;
 *     char *name;
 *     void *param;
 *     int (*parse)(struct dpip_obj *obj, struct dpip_conf *conf);
 *     int (*check)(const struct dpip_obj *obj, dpip_cmd_t cmd);
 * };
 * struct list_head_s head;
 *
 *                                  node-1                 node-2
 *                                  +-------------+         +-------------+
 *                                  |             |         |             |
 *                                  +-------------+         +-------------+
 *                                  |             |         |             |
 *          +-------------+         +-------------+         +-------------+
 *          |             | ------> |             | ------> |             |
 *          |    head     | <-----  |     list    | <-----  |     list    |
 *          +-------------+         +-------------+         +-------------+
 *                                  | ...         |         | ...         |
 *                                  +-------------+         +-------------+
 *
 *           node-m                  node-n
 *           +-------------+         +-------------+
 *           |             |         |             |
 *           +-------------+         +-------------+
 *           |             |         |             |
 *           +-------------+         +-------------+         +-------------+
 *   ------> |             | ------> |             | ....... |             |
 *   <-----  |     list    | <-----  |     list    | <-----> |     head    |
 *           +-------------+         +-------------+         +-------------+
 *           | ...         |         | ...         |
 *           +-------------+         +-------------+
 *
 *
 */
typedef struct list_head_s list_head_t;
struct list_head_s {
    list_head_t *prev;
    list_head_t *next;
};

#define LIST_HEAD_INIT(head) {&(head), &(head)}
#define LIST_HEAD(head) \
    list_head_t head = LIST_HEAD_INIT(head)
#define INIT_LIST_HEAD(head) do { \
    (head)->next = (head); \
    (head)->prev = (head); \
} while(0)

/*
 * note: priority of '->' is higher than get address '&' and type cast '()'
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
#define container_of(ptr, type, member) \
    (type *)((char *)(ptr) - (char *) &((type *)0)->member)
#endif

#define LIST_POISON1  ((void *) 0x00100100)
#define LIST_POISON2  ((void *) 0x00200200)

#ifdef __cplusplus
extern "C" {
#endif

/*
 * __list_add insert new entry between two known consecutive entries
 * @newEntry: the entry about to insert
 * @prevEntry: previous entry after @newEntry inserted
 * @nxtEntry:  next entry after @newEntry inserted
 * @return void
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries alread!
 */
static inline void __list_add(list_head_t *newEntry, list_head_t *prevEntry,
                              list_head_t *nxtEntry) {
    nxtEntry->prev  = newEntry;
    prevEntry->next = newEntry;
    newEntry->prev = prevEntry;
    newEntry->next = nxtEntry;
}

/*
 * list_add - add a new entry @newEntry into list @head
 * @new: new entry to be added
 * @head: list head to add it after
 *
 * Insert a new entry after the specified head.
 * This is good for implementing stacks.
 *
 * H denotes for (list) head:
 *                                                       -----
 *     .-------------.                           .------>| 2 |-------.
 *     |             v                           |       -----       .
 *   -----         -----                         |                   v
 *   | H |         | 1 |      Add node "2"     -----               -----
 *   -----         -----     =============>    | H |               | 1 |
 *     ^             |                         -----               -----
 *     ---------------                           ^                   |
 *                                               ---------------------
 *
 */
static inline void list_add(list_head_t *newEntry, list_head_t *head) {
    __list_add(newEntry, head, head->next);
}

/*
 * list_add_tail - add a new entry
 * @new: new entry to be added
 * @head: list head to add it before
 *
 * Insert a new entry before the specified head.
 * This is useful for implementing queues.
 *
 * H denotes for (list) head:
 *
 *
 *      .-------------.                           .-------------------.
 *      |             v                           |                   v
 *    -----         -----                       -----               -----
 *    | H |         | 1 |      Add node "2"     | H |               | 1 |
 *    -----         -----     =============>    -----               -----
 *      ^             |                           ^       -----       |
 *      ---------------                           --------| 2 | <------
 *                                                        -----
 *
 */
static inline void list_add_tail(list_head_t *newEntry, list_head_t *head) {
    __list_add(newEntry, head->prev, head);
}

/*
 * Delete a list entry by making the prev/next entries
 * point to each other.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __list_del(list_head_t *prevEntry, list_head_t *nxtEntry) {
    nxtEntry->prev  = prevEntry;
    prevEntry->next = nxtEntry;
}

/*
 * list_del - deletes entry from list.
 * @entry: the element to delete from the list.
 *
 * Note: list_empty() on entry does not return true after this, the entry is
 * in an undefined state.
 */
static inline void __list_del_entry(list_head_t *entry) {
    __list_del(entry->prev, entry->next);
}

static inline void list_del(list_head_t *entry) {
    __list_del(entry->prev, entry->next);
    entry->next = LIST_POISON1;
    entry->prev = LIST_POISON2;
}

/*
 * list_replace - replace old entry by new one
 * @oldEntry: the element to be replaced
 * @newEntry: the new element to insert
 *
 * If @oldEntry was empty, it will be overwritten.
 */
static inline void list_replace(list_head_t *oldEntry,
                                list_head_t *newEntry) {
    newEntry->next = oldEntry->next;
    newEntry->next->prev = newEntry;
    newEntry->prev = oldEntry->prev;
    newEntry->prev->next = newEntry;
}

static inline void list_replace_init(list_head_t *oldEntry,
                                     list_head_t *newEntry) {
    list_replace(oldEntry, newEntry);
    INIT_LIST_HEAD(oldEntry);
}

/*
 * list_del_init - deletes entry from list and reinitialize it.
 * @entry: the element to delete from the list.
 */
static inline void list_del_init(list_head_t *entry) {
    __list_del_entry(entry);
    INIT_LIST_HEAD(entry);
}

/*
 * list_move - delete from one list and add as another's head
 * @list: the entry to move
 * @head: the head that will precede our entry
 */
static inline void list_move(list_head_t *list, list_head_t *head) {
    __list_del_entry(list);
    list_add(list, head);
}

/*
 * list_move_tail - delete from one list and add as another's tail
 * @list: the entry to move
 * @head: the head that will follow our entry
 */
static inline void list_move_tail(list_head_t *list, list_head_t *head) {
    __list_del_entry(list);
    list_add_tail(list, head);
}

/*
 * list_is_last - tests whether @list is the last entry in list @head
 * @list: the entry to test
 * @head: the head of the list
 */
static inline int list_is_last(const list_head_t *list,
            const list_head_t *head) {
    return list->next == head;
}

/*
 * list_empty - tests whether a list is empty
 * @head: the list to test.
 */
static inline int list_empty(const list_head_t *head) {
    return head->next == head;
}

/*
 * list_entry - cast a member of a structure out to the containing structure
 *            - just as container_of
 * @ptr:	the pointer to the member.
 * @type:	the type of the container struct @member was embedded in.
 * @member:	the name of the member within the struct.
 */
#define list_entry(ptr, type, member) container_of(ptr, type, member)

/*
 * list_first_entry - get the first entry from a list
 * @head: head of the list
 * @type: type of the struct that @member was embeded in
 * @member: the name of the member within the struct
 */
#define list_first_entry(head, type, member) \
    list_entry((head)->next, type, member)

/*
 * list_first_entry_or_null - get the first entry from a list
 * @head: head of the list
 * @type: type of the struct that @member was embeded in
 * @member: the name of the member within the struct
 *
 * Note that if the list is empty, it returns NULL.
 */
#define  list_first_entry_or_null(head, type, member) \
    (!list_empty(head) ? list_first_entry(head, type, member) : NULL)

/*
 * list_for_each - iterate over a list
 * @pos:  the &struct list_head to use as a loop cursor(temporary storage)
 * @head: the head for your list.
 */
#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

/*
 * list_for_each_prev - iterate over a list backwards
 * @pos:  the &struct list_head to use as a loop cursor(temporary storage)
 * @head: the head for your list.
 */
#define list_for_each_prev(pos, head) \
    for (pos = (head)->prev; pos != (head); pos = pos->prev)

/*
 * list_for_each_safe - iterate over a list safe against removal of list entry
 * @pos: the &struct list_head to use as a loop cursor(temporary storage)
 * @n: another &struct list_head to use as temporary storage
 * @head: the head for your list.
 */
#define list_for_each_safe(pos, n, head) \
    for (pos = (head)->next, n = pos->next; pos != (head); \
                pos = n, n = pos->next)

/*
 * list_for_each_entry iterate over list of given type
 * @pos:  the type * to use as a loop counter(temporary storage)
 * @head: head of the list
 * @member: the name of the member within the list structure
 */
#define list_for_each_entry(pos, head, member) \
    for (pos = list_entry((head)->next, typeof(*pos), member); \
                &pos->member != (head); \
                pos = list_entry(pos->member.next, typeof(*pos), member))

/*
 * list_for_each_entry_reverse - iterate backwards over list of given type.
 * @pos:  the type * to use as a loop counter(temporary storage)
 * @head: head of the list
 * @member: the name of the member within the list structure
 */
#define list_for_each_entry_reverse(pos, head, member)			\
    for (pos = list_entry((head)->prev, typeof(*pos), member);	\
                &pos->member != (head); 	\
                pos = list_entry(pos->member.prev, typeof(*pos), member))

#ifdef __cplusplus
}
#endif

#endif /* ifndef _LIST_H_ */
