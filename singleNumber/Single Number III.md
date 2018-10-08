## Single Number III
<https://leetcode.com/problems/single-number-iii/description/>
<http://www.ruanyifeng.com/blog/2009/08/twos_complement.html>
> Number stored in computer was it's `complement code`, which was itself for positive ones.<br>
> `Complement code` was for right plus between positive number and negative one


### basic illustrate
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

### num &= -num
Get the least significant bit that was set

```
24 & (-24)
        0001 1000
(+)     1110 1000
    -------------
        0000 1000 (8D)      
```

### derivation formula
```bash
a ^ b = c
a ^ c = a ^ (a ^ b) = (a ^ a) ^ b = 0 ^ b = b
```
### code
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