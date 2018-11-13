## List

`/linux/include/linux/list.h`

### Illustrate
_concept of `list` of Linux kernel_




### offsetof

```c
/*
 * offsetof - get the offset value of member in type
 * (type *)0 : cast 0 to 'type' type *
 * ((type *)0)->member : get the value of 'member' of type
 * &((type *)0)->member : get the address of the 'member'
 * note: priority of '->' is higher than get address '&' and type cast '()'
 */
#ifndef offsetof
#define offsetof(type, member) ((size_t) &((type *)0)->member)
#endif
```