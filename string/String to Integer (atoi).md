## String to Integer (atoi)
### Illustrate
<https://leetcode.com/problems/string-to-integer-atoi/description>

Note:

- Only the space character ' ' is considered as whitespace character.
- Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT\_MAX (231 − 1) or INT\_MIN (−231) is returned.

### Example
```c
Input: "42"
Output: 42

Input: "   -42"
Output: -42
```

### Concept
```c
79  /* Minimum and maximum values a `signed int' can hold.  */
80  #  define INT_MIN	(-INT_MAX - 1)
81  #  define INT_MAX	2147483647
```
**INT\_MAX** (2<sup>31</sup> − 1) or **INT\_MIN** (−2<sup>31</sup>)

### Code
```c
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
        // handle maybe sign symbol, default is '+'
        if (str[i] == '+') {
            ++i;
        } else {
            if (str[i] == '-') {
                sign = -1;
                ++i;
            }
        }
        // handle main body
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
