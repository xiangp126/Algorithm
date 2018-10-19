## Sqrt(x)
### Illustrate
<https://leetcode.com/problems/sqrtx/description/>

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

### Example
```c
Input: 4
Output: 2

Input: 8
Output: 2

Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
```

### Concept
1. `int` plus overflow when calculate `mid`
2. `int` divide overflow when comparing


### Code

_care for overflow_

```c
class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        int mid = 0;
        while (left <= right) {
            // care for overflow
            mid = left + (right - left) / 2;
            // mid * mid directly may overflow
            if (mid < x / mid) {
                left = mid + 1;
            } else {
                if (mid > x / mid) {
                    right = mid - 1;
                } else {
                    return mid;
                }
            }
        }
        return right;
    }
};
```