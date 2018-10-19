## Pow(x, n)
### Illustrate
<https://leetcode.com/problems/powx-n>

Implement _pow(x, n)_, which calculates `x` raised to the power `n` (x<sup>n</sup>).

Note:

* -100.0 < x < 100.0
* n is a 32-bit signed integer, within the range [−2<sup>31</sup>, 2<sup>31</sup> − 1]

### Example
```c
Input: 2.00000, 10
Output: 1024.00000

Input: 2.10000, 3
Output: 9.26100

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
```

### Code
```c
class Solution {
public:
    double myPow(double x, int n) {
        // x should not be Zero
        if (n < 0) {
            return 1.0 / Pow(x, -n);
        }
        return Pow(x, n);
    }
    
    // calculate Power of positive number
    double Pow(double x, int n) {        
        if (n == 0)  {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        // type of val should be double
        double cache = Pow(x, n / 2);
        // judge if n was odd or even
        if (n & 0x1) {
            return cache * cache * x;
        } else {
            return cache * cache;
        }
    }
};
```