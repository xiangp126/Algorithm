### Write a Variadic Function in C
To write a variadic function in C, you need to use the `<stdarg.h>` header and the macros provided by it. Here's a step-by-step guide on how to write a variadic function:

### Expnlanation
--

1. Include the `<stdarg.h>` header at the top of your C file:

```c
#include <stdarg.h>
```

2. Declare the variadic function prototype, specifying the non-variadic arguments before the ellipsis (`...`). For example, if you want to write a variadic function that calculates the sum of a variable number of integers, the prototype would look like this:

```c
int sum(int count, ...);
```

3. Define the variadic function using the function prototype. Inside the function, declare a `va_list` object to hold the variable arguments:

```c
int sum(int count, ...) {
    va_list args;
    // Rest of the function code
}
```

4. Use the `va_start` macro to initialize the `va_list` object with the variable arguments. It takes two arguments: the `va_list` object and the last named argument before the ellipsis. In our example, the last named argument is `count`:

```c
va_start(args, count);
```

5. Access the variable arguments using the `va_arg` macro inside a loop. The `va_arg` macro takes two arguments: the `va_list` object and the type of the argument you want to retrieve. In our example, we'll retrieve `int` arguments:

```c
for (int i = 0; i < count; i++) {
    int num = va_arg(args, int);
    // Process the argument (e.g., calculate the sum)
}
```

6. After you have finished accessing the variable arguments, use the `va_end` macro to clean up the `va_list` object:

```c
va_end(args);
```

7. Finally, return the result or perform any desired operations in your variadic function.

Here's a complete example of a variadic function that calculates the sum of a variable number of integers:

```c
#include <stdarg.h>

int sum(int count, ...) {
    int total = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        total += num;
    }
    va_end(args);
    return total;
}
```

You can use similar steps to write other variadic functions that perform different operations on variable arguments.

## Test

Here's an example that includes the `main` function along with the variadic function for calculating the sum of a variable number of integers:

```c
#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) {
    int total = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        total += num;
    }
    va_end(args);
    return total;
}

int main() {
    int result = sum(3, 1, 2, 3);
    printf("Sum: %d\n", result);

    result = sum(5, 10, 20, 30, 40, 50);
    printf("Sum: %d\n", result);

    result = sum(2, 100, 200);
    printf("Sum: %d\n", result);

    return 0;
}
```

In the `main` function, we call the `sum` function with different numbers of arguments and print the sum. You can modify the arguments passed to the `sum` function to test different cases.
