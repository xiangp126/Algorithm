## Reverse Integer
### Illustrate
<https://leetcode.com/problems/reverse-integer/>

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

### Debug - Overflow
```c
Line 15: Char 28: runtime error: negation of -2147483648 cannot be represented in type 'int';

cast to an unsigned type to negate this value to itself (solution.cpp)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:24:28
```

### Intuition
Reference:
[LeetCode07(Reverse Integer)](https://stackoverflow.com/questions/67019468/leetcode07reverse-integer-why-this-code-works-out-right-ouput-in-dev-c-but)

```c
INT_MAX        = 2147483647
INT_MIN        = -2147483648

ret * 10 + (x % 10) <= INT_MAX and (ret * 10 + (x % 10) >= INT_MIN
=>
ret <= (INT_MAX - (x % 10)) / 10 and ret >= (INT_MIN - (x % 10)) / 10
=>
ret <= INT_MAX / 10 - (x % 10) / 10 = INT_MAX / 10;
and
ret >= INT_MIN / 10 - (x % 10) / 10 = INT_MIN / 10;
```

### Code - AC
```cpp
class Solution {
public:
    int myAtoi(string s) {
        int ret = 0;
        int i = 0;
        int sign = 1;
        int addOn = 0;
        while (s[i] == ' ') {
            ++i;
        }
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') {
                sign = -1;
            }
            ++i;
        }
        while ((s[i] - '0' >= 0) && (s[i] - '0' <= 9)) {
            // addOn here doesn't carry the sign symbol.
            addOn = s[i] - '0';
            if (sign > 0) {
                if (ret < INT_MAX / 10 ||
                    ((ret == INT_MAX / 10) && (addOn <= INT_MAX % 10))) {
                    ret = ret * 10 + addOn;
                } else {
                    return INT_MAX;
                }
            } else {
                // because addOn here doesn't carry the sign symbol
                if (ret > INT_MIN / 10 ||
                    ((ret == INT_MIN / 10) && (-1 * addOn >= INT_MIN % 10))) {
                    ret = ret * 10 - addOn;
                } else {
                    return INT_MIN;
                }
            }
            ++i;
        }
        return ret;
    }
};
```

### Code - AC - Simplified
```cpp
class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x) {
            if (ret > INT_MAX / 10 || ret < INT_MIN / 10) {
                return 0;
            }
            ret = ret * 10 + (x % 10);
            x /= 10;
        }
        return ret;
    }
};
```

### Code - Failed
```c++
class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        bool isPositive = x < 0 ? false : true;
        x = abs(x);
        while (x) {
            if (isPositive) {
                if (ret < (INT_MAX - (x % 10)) / 10) {
                    ret = ret * 10 + (x % 10);
                } else {
                    return 0;
                }
            } else {
                if (ret < (-INT_MIN - (x % 10)) / 10) {
                    ret = ret * 10 + (x % 10);
                } else {
                    return 0;
                }
            }
            x /= 10;
        }
        return isPositive ? ret : -ret;
    }
};
```
