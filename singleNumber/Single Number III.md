## Single Number III
### Illustrate
<https://leetcode.com/problems/single-number-iii/description/>
<http://www.ruanyifeng.com/blog/2009/08/twos_complement.html>

```
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
```

### Core Concept
> Number stored in computer was it's `complement code`, which was itself for positive ones.<br>
> `Complement code` was for right plus between positive number and negative one

数字 | 原码 | 反码 | 补码
--- | --- | --- | ---
10 | 0000 1010 | 0000 1010 | 000 1010
-10 | 1000 1010 | 1111 0101 | 1111 0110

&radic;

```
10 + (-10) =
        0000 1010
(+)     1111 0110
    -------------
        0000 0000
```

> num &= -num

Get the least significant bit that was set

```
24 & (-24)
        0001 1000
(+)     1110 1000
    -------------
        0000 1000 (8D)      
```

> Derivation Formula

```bash
a ^ b = c
a ^ c = a ^ (a ^ b) = (a ^ a) ^ b = 0 ^ b = b
```
### Code
```c
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ret(2, 0);
        int tsum = 0;
        for (int num : nums) {
            tsum ^= num;
        }
        // tsum = a ^ b, assume a, b is wanted
        
        // get the least significant bit that was set
        // assume k = 0x0000 0010
        int k = tsum & -tsum;
        for (int num : nums) {
            if (num & k) {
                ret[0] ^= num;
            }
        }
        ret[1] = ret[0] ^ tsum;
        return ret;
    }
};
```