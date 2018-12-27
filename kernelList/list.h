/*
 * Illustrated by hi.pxiang@gmail.com
 * modified from linux kernel
 */
#ifndef _LIST_H_
#define _LIST_H_

/*
 * list_head_t double-linked circular list
 * list was embeded into the structure itself
 * @type: the type of the structure @head points to
 * @list: embeded member of the @type
 * @head: the start entry of this double-linked circular list
 *
 * struct dpip_obj {
 *     struct list_head list;
 *     char *name;
 *     void *param;
 *     int (*parse)(struct dpip_obj *obj, struct dpip_conf *conf);
 *     int (*check)(const struct dpip_obj *obj, dpip_cmd_t cmd);
 * };
 * struct list_head head;
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
typedef struct list_head list_head_t;

struct list_head {
    list_head_t *next;
    list_head_t *prev;
};

#define LIST_HEAD_INIT(head) {&(head), &(head)}
#define LIST_HEAD(name) \
    list_head_t name = LIST_HEAD_INIT(name)
#define INIT_LIST_HEAD(head) do { \
    (head)->next = (head); \
    (head)->prev = (head); \
} while(0)

/*
 * calculate offset of a member in the structure
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
    (type *)((char *)(ptr) - offsetof(type, member))
#endif

/*
 * These are non-NULL pointers that will result in page faults
 * under normal circumstances, used to verify that nobody uses
 * non-initialized list entries.
 */
#define LIST_POISON1  ((void *) 0x00100100)
#define LIST_POISON2  ((void *) 0x00200200)

#ifdef __cplusplus
extern "C" {
#endif

/*
 * __list_add insert new entry between two known consecutive entries
 * @__new:  the entry about to insert
 * @__prev: previous entry after @__new inserted
 * @__next: next entry after @__new inserted
 * @return void
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __list_add(list_head_t *__new, list_head_t *__prev,
                              list_head_t *__next) {
    __prev->next = __new;
    __new->prev  = __prev;
    __next->prev = __new;
    __new->next  = __next;
}

/*
 * list_add - add a new entry @__new into list @head
 * @__new: new entry to be added
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
static inline void list_add(list_head_t *__new, list_head_t *head) {
    __list_add(__new, head, head->next);
}

/*
 * list_add_tail - add a new entry
 * @__new: new entry to be added
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
static inline void list_add_tail(list_head_t *__new, list_head_t *head) {
    __list_add(__new, head->prev, head);
}

/*
 * Delete a list entry by making the prev/next entries
 * point to each other.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __list_del(list_head_t *__prev, list_head_t *__next) {
    __next->prev = __prev;
    __prev->next = __next;
}

/*
 * list_del - deletes entry from list.
 * @__del: the element to delete from the list.
 *
 * Note: list_empty() on entry does not return true after this, the entry is
 * in an undefined state.
 */
static inline void __list_del_entry(list_head_t *__del) {
    __list_del(__del->prev, __del->next);
}

static inline void list_del(list_head_t *__del) {
    __list_del(__del->prev, __del->next);
    __del->next = LIST_POISON1;
    __del->prev = LIST_POISON2;
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
 * list_last_entry - get the last entry from a list
 * @head: head of the list
 * @type: type of the struct that @member was embeded in
 * @member: the name of the member within the struct
 */
#define list_last_entry(head, type, member) \
    list_entry((head)->prev, type, member)

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
 * list_for_each_entry_safe - iterate over list of given type safe against removal of list entry
 * @pos:	the type * to use as a loop cursor.
 * @n:		another type * to use as temporary storage
 * @head:	the head for your list.
 * @member:	the name of the list_struct within the struct.
 */
#define list_for_each_entry_safe(pos, n, head, member)			\
    for (pos = list_entry((head)->next, typeof(*pos), member),	\
         n = list_entry(pos->member.next, typeof(*pos), member);	\
         &pos->member != (head); 					\
         pos = n, n = list_entry(n->member.next, typeof(*n), member))

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

typedef struct hlist_head hlist_head_t;
typedef struct hlist_node hlist_node_t;

struct hlist_head {
    struct hlist_node *first;
};

struct hlist_node {
    struct hlist_node *next;
    struct hlist_node **pprev;
};

#define HLIST_HEAD_INIT { .first = NULL }
#define HLIST_HEAD(name) struct hlist_head name = { .first = NULL }
#define INIT_HLIST_HEAD(ptr) ((ptr)->first = NULL)
static inline void INIT_HLIST_NODE(struct hlist_node *node) {
    node->next  = NULL;
    node->pprev = NULL;
}

static inline int hlist_empty(const struct hlist_node *node) {
    return !node->pprev;
}

static inline void
hlist_add_head(struct hlist_node *__new, struct hlist_head *head) {
    struct hlist_node *first = head->first;
    // head->first was initialized NULL
    __new->next = first;

    if (first) {
        first->pprev = &__new->next;
    }
    head->first  = __new;
    __new->pprev = &head->first;
}

static inline void __hlist_del(struct hlist_node *__del) {
    struct hlist_node *__next   = __del->next;
    struct hlist_node **__pprev = __del->pprev;
    *__pprev = __next;
    if (__next) {
        __next->pprev = __pprev;
    }
}

static inline void hlist_del(struct hlist_node *__del) {
    __hlist_del(__del);
    __del->next  = LIST_POISON1;
    __del->pprev = LIST_POISON2;
}

#define hlist_entry(ptr, type, member) container_of(ptr, type, member)

#define hlist_for_each(pos, head) \
    for (pos = (head)->first; pos; pos = pos->next)

#define hlist_for_each_safe(pos, n, head) \
    for (pos = (head)->first; pos && ({ n = pos->next; 1; }); \
         pos = n)

#define hlist_entry_safe(ptr, type, member) \
    ({ typeof(ptr) ____ptr = (ptr); \
     ____ptr ? hlist_entry(____ptr, type, member) : NULL; \
     })

/*
 * hlist_for_each_entry	- iterate over list of given type
 * @pos:	the type * to use as a loop cursor.
 * @head:	the head for your list.
 * @member:	the name of the hlist_node within the struct.
 */
#define hlist_for_each_entry(pos, head, member)				\
    for (pos = hlist_entry_safe((head)->first, typeof(*(pos)), member);\
         pos;							\
         pos = hlist_entry_safe((pos)->member.next, typeof(*(pos)), member))

/*
 * hlist_for_each_entry_safe - iterate over list of given type safe against removal of list entry
 * @pos:	the type * to use as a loop cursor.
 * @n:		another &struct hlist_node to use as temporary storage
 * @head:	the head for your list.
 * @member:	the name of the hlist_node within the struct.
 */
#define hlist_for_each_entry_safe(pos, n, head, member) 		\
    for (pos = hlist_entry_safe((head)->first, typeof(*pos), member);\
         pos && ({ n = pos->member.next; 1; });			\
         pos = hlist_entry_safe(n, typeof(*pos), member))

#ifdef __cplusplus
}
#endif

#endif /* ifndef _LIST_H_ */
