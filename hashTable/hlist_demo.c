#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

#define PAIR_TABLE_BITS      4
#define PAIR_TABLE_SIZE      (1 << PAIR_TABLE_BITS)
#define PAIR_TABLE_MASK      (PAIR_TABLE_SIZE - 1)
static struct hlist_head *pair_map;

struct my_pair {
    int key;
    int value;
    struct hlist_node hlist;
};

static int hash_func(struct my_pair *obj) {
    int hashkey = obj->key & PAIR_TABLE_MASK;
    /* hashkey = 2; */

    return hashkey;
}

void dump_entry(struct my_pair *obj) {
    printf("key: %-15d value: %-15d\n", obj->key, obj->value);
}

void dump_hash_table(struct hlist_head *map) {
    int i;
    struct my_pair *pos;
    for (i = 0; i < PAIR_TABLE_SIZE; ++i) {
        hlist_for_each_entry(pos, &map[i], hlist) {
            printf("[bucket %2d]: ", i);
            dump_entry(pos);
        }
    }
}

void flush_hash_table(struct hlist_head *map) {
    int i;
    struct my_pair *pos;
    for (i = 0; i < PAIR_TABLE_SIZE; ++i) {
        hlist_for_each_entry(pos, &map[i], hlist) {
            hlist_del(pos);
            /* free(pos); */
        }
    }
}

int main(int argc, char *argv[])
{
    int i;
    srand(time(NULL));
    pair_map = (struct hlist_head *)
        malloc(sizeof(struct hlist_head) * PAIR_TABLE_SIZE);

    /* init hash table */
    for (i = 0; i < PAIR_TABLE_SIZE; ++i) {
        INIT_HLIST_HEAD(&pair_map[i]);
    }

    struct my_pair *pair;
    int hashkey = 0;
    for (i = 0; i < 5; ++i) {
        pair = (struct my_pair*) malloc(sizeof(struct my_pair));
        pair->key = rand();
        pair->value = pair->key + 1;
        /* calc hash key, i.e. the NO. of buckets */
        hashkey = hash_func(pair);
        /* add entry into hash map */
        hlist_add_head(&pair->hlist, &pair_map[hashkey]);
    }

    dump_hash_table(pair_map);

    /* printf("Del entry key = %d\n", ); */
    flush_hash_table(pair_map);
    /* dump_entry(pair_map); */

    return 0;
}
