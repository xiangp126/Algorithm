#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int  uint;
typedef unsigned char uchar;
typedef unsigned long ulong;

#define oops(msg) { \
    fprintf(stdout, "%s at:", msg); \
    printf ("%s->%s:%u\n", __FILE__, __FUNCTION__, __LINE__); \
    exit(1);\
}

#endif /* ifndef _CONFIG_H_ */
