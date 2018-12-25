#include <stdio.h>
#include <stdlib.h>
#include "list.h"

const int N = 3;
struct my_obj {
    int to;
    int from;
    list_head_t list;
};

void dump_entry(struct my_obj *obj) {
    printf("from %d to %d.\n", obj->from, obj->to);
}

int main(int argc, char *argv[])
{
    int i;
    list_head_t head;
    INIT_LIST_HEAD(&head);

    struct my_obj *myObj = (struct my_obj *)malloc(sizeof(struct my_obj) * N);
    free((void *)myObj);
    /* init entry itself */
    for (int i = 0; i < N; ++i) {
        myObj[i].from = i;
        myObj[i].to = myObj[i].from + 1;
    }

    /* add each entry into list */
    for (int i = 0; i < N; ++i) {
        list_add_tail(&myObj[i].list, &head);
    }

    printf("Demo for list_for_each_entry\n");
    struct my_obj *pos;
    list_for_each_entry(pos, &head, list) {
        dump_entry(pos);
    }

    printf("\nDel second element\n");
    i = 1;
    list_del(&myObj[i].list);
    list_for_each_entry(pos, &head, list) {
        dump_entry(pos);
    }

    dump_entry(&myObj[i]);

    return 0;
}
