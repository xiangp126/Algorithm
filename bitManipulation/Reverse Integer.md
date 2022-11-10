## Reverse Integer
### Illustrate
<https://leetcode.com/problems/reverse-integer/>

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
