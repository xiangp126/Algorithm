#include <stdio.h>
#include "list.h"

static void print_list_data(void *data);

int main(int argc, char *argv[])
{
    list_t *list = list_init(NULL, print_list_data);
    printf("Hello World!\n");
    return 0;
}

void print_list_data(void *data) {
    int *pVal = (int *)data;
    printf("pVal = %d\n", *pVal);
}
