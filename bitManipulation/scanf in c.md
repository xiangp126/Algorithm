### scanf in c
[Synopsis of scanf in c](https://cplusplus.com/reference/cstdio/scanf/)

```c
char s[100];
scanf("%[^\n]%*c", &s);
```

The code you provided is using the `scanf` function to read a string input from the user. Let's break down what each part of the code does:

1. `char s[100];`: This declares a character array `s` with a size of 100, which will be used to store the input string.

2. `scanf("%[^\n]%*c", &s);`: This is the `scanf` function used to read the input string. Here's what each part of the format specifier means:
   - `%[^\n]`: This tells `scanf` to read a string until it encounters a newline character (`\n`). The `[^\n]` part is a character set that excludes the newline character, allowing the function to read a full line of input.
   - `%*c`: This is a specifier that tells `scanf` to read and discard a single character, in this case, the newline character. The asterisk (`*`) before the `c` indicates that the character should be discarded without storing it in any variable.

3. `&s`: The `&` operator is used to get the address of the variable `s`, which is the location where the input string will be stored.

Overall, this code snippet allows the user to input a string of up to 99 characters (leaving space for the null-terminating character) and stores it in the `s` array. The `scanf` function will read the input until a newline character is encountered, and then discard the newline character.

Note: It's important to ensure that the input string does not exceed the size of the character array to prevent buffer overflow.
