#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

const int N = 3;
struct my_pair {
    int key;
    int value;
    struct list_head list;
};

void dump_entry(struct my_pair *obj) {
    printf("key %d value %d.\n", obj->key, obj->value);
}

int main(int argc, char *argv[])
{
    int i;
    struct my_pair *myPair;

    srand(time(NULL));

    /* define and init head */
    struct list_head head;
    INIT_LIST_HEAD(&head);

    /* init entry itself */
    for (i = 0; i < N; ++i) {
        myPair = (struct my_pair *) malloc(sizeof(struct my_pair));
        myPair->key = i;
        myPair->value = rand();
        /* add each entry into list */
        list_add_tail(&myPair->list, &head);
    }

    printf("Demo for list_for_each_entry\n");
    struct my_pair *pos;
    list_for_each_entry(pos, &head, list) {
        dump_entry(pos);
    }

    struct my_pair *n;
    int target = 1;
    printf("\nDel second element\n");
    list_for_each_entry_safe(pos, n, &head, list) {
        if (pos->key == target) {
            list_del(&pos->list);
            free(pos);
        }
    }

    printf("\nAfter Del\n");
    list_for_each_entry(pos, &head, list) {
        dump_entry(pos);
    }

    return 0;
}
