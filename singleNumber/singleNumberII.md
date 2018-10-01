## Single Number II
<https://leetcode.com/problems/single-number-ii/>

### core concept

> assume `22` is wanted, and `35` is three times repeated<br>
> we calculate each bit of the `wanted number`, 32 bit total of type `int`

```bash
   7654 3210   th
0x 0010 0011   (35)
+  0010 0011   (35)
+  0010 0011   (35)
+  0001 0110   (22)
-------------
   0031 0143
% 3
-------------
   0001 0110   yields 22
          
(1 + 1 + 1) % 3 = 0       
```

### code
```c
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int bitOfInt = sizeof(int) * 8;
        int bits[bitOfInt];
        int ret = 0, temp = 0;
        for (int i = 0; i < bitOfInt; ++i) {
            for (auto num : nums) {
                temp += (num >> i) & 0x1;
            }
            // thus temp was sum of the i th bit of each num
            bits[i] = temp % 3;
            temp = 0;
        }
        // make ret with each bit
        for (int i = 0; i < bitOfInt; ++i) {
            ret |= (bits[i] << i);
        }
        return ret;
    }
};
```
