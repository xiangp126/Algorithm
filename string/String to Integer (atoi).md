## String to Integer (atoi)
### Illustrate
<https://leetcode.com/problems/string-to-integer-atoi/description>

### Example
```c
Input: "42"
Output: 42

Input: "   -42"
Output: -42
```

### Debug - Overflow
```c
Line 33: Char 28: runtime error: signed integer overflow: 2147483640 + 54 cannot be represented in type 'int' (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:42:28
```

### Intuition
Reference:
[LeetCode07(Reverse Integer)](https://stackoverflow.com/questions/67019468/leetcode07reverse-integer-why-this-code-works-out-right-ouput-in-dev-c-but)

```c
79  /* Minimum and maximum values a `signed int' can hold.  */
80  #  define INT_MIN	(-INT_MAX - 1)
81  #  define INT_MAX	2147483647
```
**INT\_MAX** (2<sup>31</sup> − 1) or **INT\_MIN** (−2<sup>31</sup>)

```c
INT_MAX        = 2147483647
INT_MIN        = -2147483648
# determined by the sign
ret * 10 + (str[i] - '0') <= INT_MAX or (ret * 10 + (str[i] - '0')) >= INT_MIN
=>
ret <= (INT_MAX - (str[i] - '0')) / 10 or ret >= (INT_MIN - (x % 10)) / 10
=>
ret <= INT_MAX / 10 - (str[i] - '0') / 10 = INT_MAX / 10;
or
ret >= INT_MIN / 10 - (x % 10) / 10 = INT_MIN / 10;
```

### Code - AC
```cpp
class Solution {
public:
    int myAtoi(string str) {
        long ret = 0;
        bool isPositive = true;
        int i = 0;
        const int N = str.size();

        while (i < N && (str[i] == ' ')) {
            ++i;
        }
        if (i < N && (str[i] == '-' || str[i] == '+')) {
            if (str[i] == '-') {
                isPositive = false;
            }
            ++i;
        }
        while (i < N) {
            if (str[i] >= '0' && str[i] <= '9') {
                if (isPositive) {
                    if ((ret * 10 + str[i] - '0') > INT_MAX) {
                        return INT_MAX;
                    } else {
                        ret = ret * 10 + str[i] - '0';
                        ++i;
                    }
                } else {
                    if (-1 * (ret * 10 + str[i] - '0') < INT_MIN) {
                        return INT_MIN;
                    } else {
                        ret = ret * 10 + str[i] - '0';
                        ++i;
                    }
                }
            } else {
                break;
            }
        }
        return isPositive ? ret : -ret;
    }
};
```

### Code - Failed for updated cases
```cpp
class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int ret = 0;
        int sign = 1;
        const int N = str.size();

        // skip pre whitespaces
        while ((i < N) && (str[i] == ' ')) {
            ++i;
        }
        // check whether there is a symbol sign
        if ((str[i] == '+') || (str[i] == '-')) {
            if (str[i] == '-') {
                sign = -1;
            }
            ++i;
        }
        // process the main body
        while (i < N) {
            if (str[i] < '0' || str[i] > '9') {
                break;
            }
            /*
             * exception: got value of 'ret' out of range
             * ret * 10 + str[i] - '0' > INT_MAX
             * => ret > (INT_MAX - (str[i] - '0')) / 10
             */
            if (ret > (INT_MAX - (str[i] - '0')) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            ret = ret * 10 + str[i] - '0';
            ++i;
        }
        return sign * ret;
    }
};
```
