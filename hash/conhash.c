#include <string.h>
#include "conhash.h"
#include "md5.h"

static void md5_digest(const uchar *str, uchar *digest);
static int conhash_add_replica(conhash_t *conhash, conhash_node_t *node);
static int conhash_del_replica(conhash_t *conhash, conhash_node_t *node);
static void rbtree_free_node(util_rbtree_node_t *node);
void conhash_free(conhash_t *conhash);

/*
 * hashfunc_md5 | default hash function using md5
 * @str: input string for hashing
 * @return hash value
 */
ulong hashfunc_md5(const char *str) {
    ulong hash = 0;
    uchar digest[16];
    md5_digest((const uchar *)str, digest);

    /* use successive 4-bytes from hash as numbers */
    for(int i = 0; i < 4; i++) {
        hash += ((long)(digest[i*4 + 3]&0xFF) << 24)
              | ((long)(digest[i*4 + 2]&0xFF) << 16)
              | ((long)(digest[i*4 + 1]&0xFF) <<  8)
              | ((long)(digest[i*4 + 0]&0xFF));
    }
    return hash;
}

void md5_digest(const uchar *str, uchar *digest) {
    md5_state_t md5state;

    md5_init(&md5state);
    /* strlen(const char *) */
    md5_append(&md5state, str, strlen((const char *)str));
    md5_finish(&md5state, digest);
}

/*
 * conhash_init | consistent hash init routine
 * @pHashfunc: the hash function this conhash will use
 * @return a new initialized consistent hash table
 */
conhash_t *conhash_init(conhash_cb_hashfunc pHashfunc) {
    conhash_t *conhash = (conhash_t *)malloc(sizeof(conhash_t));
    if (conhash == NULL) {
        oops("malloc conhash error");
        return NULL;
    }
    if (pHashfunc != NULL) {
        conhash->hashfunc = pHashfunc;
    } else {
        conhash->hashfunc = hashfunc_md5;
    }
    util_rbtree_init(&conhash->vnodeTree);
    conhash->vnodeCnt = 0;
    return conhash;
}

/*
 * conhash_set_node | set node in the consistent hash table
 * @node: node that will be put in the hash table
 * @identity: string that identify the node
 * @replicas: repeat number of the virtual nodes
 * @return void
 */
void conhash_set_node(conhash_node_t *node, const char *identity,
                                            uint replicas) {
    strncpy(node->identity, identity, sizeof(node->identity) - 1);
    node->replicas = replicas;
    node->flag = NODE_FLAG_INIT;
}

/*
 * conhash_add_node | add node into consistent hash table
 * @conhash: the consistent hash table
 * @node: the node will be added into hash table
 * @return CONHASH_ERROR  when error
 */
int conhash_add_node(conhash_t *conhash, conhash_node_t *node) {
    if (conhash == NULL || node == NULL) {
        return CONHASH_ERROR;
    }

    if (! (node->flag & NODE_FLAG_INIT) || node->flag & NODE_FLAG_IN) {
        return CONHASH_ERROR;
    }

    node->flag |= NODE_FLAG_IN;
    conhash_add_replica(conhash, node);
    return CONHASH_OK;
}

/*
 * conhash_add_replica | add replicas into the RB-Tree of hash table
 * @conhash: the consistent hash table
 * @node: the node that will be added
 * @return CONHASH_ERROR if add error
 */
int conhash_add_replica(conhash_t *conhash, conhash_node_t *node) {
    if (conhash == NULL || node == NULL) {
        return CONHASH_ERROR;
    }

    util_rbtree_t *vnodeTree = &conhash->vnodeTree;
    util_rbtree_node_t *rbnode;
    ulong hashVal;
    char buff[BUFSIZ];

    for (uint idx = 0; idx < node->replicas; ++idx) {
        memset(buff, '\0', BUFSIZ);
        /*
         * %3d -> right align padding 0 if not 3bit width, %-3d -> left align
         * str: Hello
         * Hello-000, Hello-010, Hello-1234
         */
        snprintf(buff, BUFSIZ - 1, "%s-%03d", node->identity, idx);
        /* calculate the hash value */
        hashVal = conhash->hashfunc(buff);

        /*
         * check if this node already exists in the tree before insert
         *
         * conhash -> vnodeTree -> rbnode
         * @rbnode: <key,           value>
         *            |                |-> vnode |    ulong hashVal
         *            |-> hashVal                |->  conhash_node_t *node
         */
        if (util_rbtree_search(vnodeTree, hashVal) == NULL) {
            rbnode = (util_rbtree_node_t *)malloc(sizeof(util_rbtree_node_t));
            if (rbnode != NULL) {
                rbnode->key = hashVal;
                conhash_vnode_t *vnode =
                    (conhash_vnode_t *)malloc(sizeof(conhash_vnode_t));
                if (vnode != NULL) {
                    vnode->hash = hashVal;
                    vnode->node = node;
                    rbnode->data = (void *)vnode;
                } else {
                    free(rbnode);
                    rbnode = NULL;
                    return CONHASH_ERROR;
                }
                /* insert rbnode into vnodeTree of conhash */
                util_rbtree_insert(vnodeTree, rbnode);
                ++conhash->vnodeCnt;
            } else {
                return CONHASH_ERROR;
            }
        }
    }
    return CONHASH_OK;
}

/*
 * conhash_vnode_cnt
 *
 * @conhash: the consistent hash table
 * @return the vnode cnt of conhash
 */
uint conhash_vnode_cnt(const conhash_t *conhash) {
    return conhash == NULL ? 0 : conhash->vnodeCnt;
}

/*
 * conhash_lookup
 *
 * @conhash: the consistent hash table
 * @object: input object for lookup
 * @return NULL if not found
 */
conhash_node_t *conhash_lookup(conhash_t *conhash, const char *object) {
    if (conhash == NULL || conhash_isempty(conhash) || object == NULL) {
        return NULL;
    }

    ulong hashVal = conhash->hashfunc(object);
#if CONHASH_DEBUG
    printf("%s Hash value = %lu\n", (char *)object, hashVal);
#endif
    util_rbtree_node_t *rbnode =
        util_rbtree_lookup(&conhash->vnodeTree, hashVal);
    if (rbnode != NULL) {
        conhash_vnode_t *vnode = (conhash_vnode_t *)rbnode->data;
        return vnode->node;
    }
    return NULL;
}

/*
 * conhash_del_node | del node in consistent hash table
 * @conhash: the consistent hash table
 * @node: the node in the hash table that will be deleted
 * @return CONHASH_ERROR when error
 */
int conhash_del_node(conhash_t *conhash, conhash_node_t *node) {
    if (conhash == NULL || node == NULL) {
        return CONHASH_ERROR;
    }

    /* if (! (node->flag & NODE_FLAG_INIT) || node->flag & NODE_FLAG_IN) { */
        /* return CONHASH_ERROR; */
    /* } */
    /* node->flag |= NODE_FLAG_IN; */

    conhash_del_replica(conhash, node);
    return CONHASH_OK;
}

/*
 * conhash_del_replica | add replicas into the RB-Tree of hash table
 * @conhash: the consistent hash table
 * @node: the node that will be added
 * @return CONHASH_ERROR if add error
 */
int conhash_del_replica(conhash_t *conhash, conhash_node_t *node) {
    if (conhash == NULL || node == NULL) {
        return CONHASH_ERROR;
    }

    util_rbtree_t *vnodeTree = &conhash->vnodeTree;
    util_rbtree_node_t *rbnode;
    ulong hashVal;
    char buff[BUFSIZ];

    for (uint idx = 0; idx < node->replicas; ++idx) {
        memset(buff, '\0', BUFSIZ);
        /*
         * %3d -> right align padding 0 if not 3bit width, %-3d -> left align
         * str: Hello
         * Hello-000, Hello-010, Hello-1234
         */
        snprintf(buff, BUFSIZ - 1, "%s-%03d", node->identity, idx);
        /* calculate the hash value */
        hashVal = conhash->hashfunc(buff);

        rbnode = util_rbtree_search(vnodeTree, hashVal);
        if (rbnode != NULL) {
            conhash_vnode_t *vnode = (conhash_vnode_t *)rbnode->data;
            /*
             * in case has hash collision, double check the condition
             */
            if (vnode->node == node) {
                util_rbtree_delete(vnodeTree, rbnode);
                /*
                 * util_rbtree_delete did not free the node it delete
                 * leave it for the function call it
                 * so, do it here
                 */
                rbtree_free_node(rbnode);
                --conhash->vnodeCnt;
            }
        }
    }
    return CONHASH_OK;
}

/*
 * rbtree_free_node | free rb-node
 * @node: the node in RB-Tree that needs to free
 * @return void
 */
void rbtree_free_node(util_rbtree_node_t *node) {
    conhash_vnode_t *vnode = (conhash_vnode_t *)node->data;
    free(vnode);
    free(node);
}

/*
 * conhash_free_tree | free consistent hash table
 * @node: the hash table needs freed
 * @return void
 */
void conhash_free(conhash_t *conhash) {
    if (conhash != NULL) {
        util_rbtree_t *vnodeTree = &conhash->vnodeTree;
        while (! util_rbtree_isempty(vnodeTree)) {
            /* delete from root node */
            util_rbtree_node_t *node = vnodeTree->root;
            util_rbtree_delete(vnodeTree, node);
            rbtree_free_node(node);
        }
        free(vnodeTree);
    }
}
