#include <stdio.h>
#include "list.h"

typedef struct mytest_s {
    int  val;
    char haha;
    int  num;
} mytest_t;

int main(int argc, char *argv[])
{
    mytest_t mytest = {
        .val = 100,
        .haha = 'c',
        .num = 200
    };
    char *pHaha = &mytest.haha;
    mytest_t *pTest = container_of(pHaha, mytest_t, haha);

    printf("pTest->val = %d\n", pTest->val);
    printf("pTest->haha = %c\n", pTest->haha);
    printf("pTest->num = %d\n", pTest->num);

    return 0;
}
