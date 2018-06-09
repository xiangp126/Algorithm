#include "conhash.h"

void md5_digest(const uchar *str, uchar *digest) {
    md5_state_t md5state;

    md5_init(&md5state);
    /* strlen(const char *) */
    md5_append(&md5state, str, strlen((const char *)str));
    md5_finish(&md5state, digest);
}
