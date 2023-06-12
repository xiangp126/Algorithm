### Detailed Explanation of Variadic Function

[“栈”顶到底是上面还是下面？高地址还是低地址？](https://zhuanlan.zhihu.com/p/447224382)

Here's an example of how you can implement the `va_list`, `va_start`, `va_arg`, and `va_end` macros in C:

```c
#include <stddef.h>

typedef char* va_list;

#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))
#define va_arg(ap, t) (*(t*)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))
#define va_end(ap) (ap = (va_list)NULL)

int sum(int count, ...) {
    int total = 0;
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }

    va_end(args);
    return total;
}

int main() {
    int result = sum(3, 10, 20, 30);
    printf("Sum: %d\n", result);
    return 0;
}
```

In this example, we define a `va_list` as a pointer to a character (char*). We use the `_INTSIZEOF` macro to calculate the size of each argument passed.

The `va_start` macro initializes the `va_list` argument pointer `ap` by taking the address of the last named parameter `v` and adding the size of `v` rounded up to the nearest multiple of `sizeof(int)`.

The `va_arg` macro is used to retrieve the next argument of type `t` from the `va_list` `ap`. It increments `ap` by the size of `t` and returns the value.

The `va_end` macro is used to clean up and reset the `va_list` `ap` to `NULL`.

The `sum` function demonstrates the usage of these macros to calculate the sum of a variable number of integer arguments.

Note that this is a simplified implementation, and the actual implementation of these macros in standard libraries may vary.
