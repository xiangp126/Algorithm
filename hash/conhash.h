#ifndef __CON_HASH_H_
#define __CON_HASH_H_

#include "rbtree.h"

#define CONHASH_DEBUG  0
typedef struct conhash_node_s conhash_node_t;
typedef struct conhash_vnode_s conhash_vnode_t;
typedef struct conhash_s conhash_t;

/*
 * NODE_FLAG_INIT: node was just initialized | 0x0000 0001
 * NODE_FLAG_IN: node was already added into the hash table 0x0000 0010
 */
#define NODE_FLAG_INIT 0x01
#define NODE_FLAG_IN   0x02
#define conhash_isempty(conhash) (conhash->vnodeCnt == 0)

/* return status of consistent hash routine */
typedef enum conhash_status_s {
    CONHASH_ERROR = -1,
    CONHASH_OK = 0
} conhash_status_t;

/*
 * s for structure, t for type
 *
 * conhash_node_s
 * @identity: identifies the node itself, can be ip address of server
 * @replicas: repeat number of the virtual nodes
 * @flag: if the node was already in the hash table
 */
struct conhash_node_s {
    char identity[BUFSIZ];
    uint replicas;
    uint  flag;
};

/*
 * conhash_vnode_s
 * @hash: the hash value of virtual node
 * @node: pointer to real node
 */
struct conhash_vnode_s {
    ulong hash;
    conhash_node_t *node;
};

/*
 * conhash_s | consistent hash structure
 * @vnodeTree: rbtree of virtual nodes
 * @vnodeCnt: count of virtual nodes
 * @hashfunc: the hash function, can be user-defined
 */
struct conhash_s {
    util_rbtree_t vnodeTree;
    volatile uint vnodeCnt;
    ulong (*hashfunc)(const char *);
};

typedef ulong (*conhash_cb_hashfunc)(const char *);

#ifdef __cplusplus
extern "C" {
#endif

/*
 * hashfunc_md5 | default hash function using md5
 * @str: input string for hashing
 * @return hash value
 */
ulong hashfunc_md5(const char *str);

/*
 * conhash_init | consistent hash init routine
 * @pHashfunc: the hash function this conhash will use
 * @return a new initialized consistent hash table
 */
conhash_t *conhash_init(conhash_cb_hashfunc pHashfunc);

/*
 * conhash_set_node | set node in the consistent hash table
 * @node: node that will be put in the hash table
 * @identity: string that identify the node
 * @replicas: repeat number of the virtual nodes
 */
void conhash_set_node(conhash_node_t *node, const char *identity, uint replicas);

/*
 * conhash_add_node | add node into consistent hash table
 * @conhash: the consistent hash table
 * @node: the node will be added into hash table
 * @return CONHASH_ERROR  when error
 */
int conhash_add_node(conhash_t *conhash, conhash_node_t *node);

/*
 * conhash_vnode_cnt
 *
 * @conhash: the consistent hash table
 * @return the vnode cnt of conhash
 */
uint conhash_vnode_cnt(const conhash_t *conhash);

/*
 * conhash_lookup
 *
 * @conhash: the consistent hash table
 * @object: input object
 * @return NULL if not found
 */
conhash_node_t *conhash_lookup(conhash_t *conhash, const char *object);

/*
 * conhash_del_node | del node in consistent hash table
 * @conhash: the consistent hash table
 * @node: the node in the hash table that will be deleted
 * @return CONHASH_ERROR when error
 */
int conhash_del_node(conhash_t *conhash, conhash_node_t *node);

#ifdef __cplusplus
}
#endif

#endif /* ifndef __CON_HASH_H_ */
