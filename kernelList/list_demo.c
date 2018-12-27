#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

struct list_head head;
const int N = 3;
struct my_pair {
    int key;
    int value;
    struct list_head list;
};

void dump_list(struct list_head *head) {
    int i = 0;
    struct my_pair *pos;
    list_for_each_entry(pos, head, list) {
        printf("[# %d]: key %d value %d.\n", i++, pos->key, pos->value);
    }
}

int main(int argc, char *argv[])
{
    int i;
    struct my_pair *pair;

    srand(time(NULL));

    /* define and init head */
    INIT_LIST_HEAD(&head);

    /* init entry itself */
    for (i = 0; i < N; ++i) {
        pair = (struct my_pair *) malloc(sizeof(struct my_pair));
        pair->key = rand();
        pair->value = pair->key + 1;
        /* add each entry into list */
        list_add_tail(&pair->list, &head);
    }

    /* add an extra for deleting later */
    pair = (struct my_pair*) malloc(sizeof(struct my_pair));
    pair->key = 88;
    pair->value = pair->key + 1;
    list_add_tail(&pair->list, &head);

    dump_list(&head);

    struct my_pair *pos, *n;
    int target = 88;
    printf("Del entry key = 88\n");
    list_for_each_entry_safe(pos, n, &head, list) {
        if (pos->key == target) {
            list_del(&pos->list);
            free(pos);
        }
    }

    dump_list(&head);

    return 0;
}
