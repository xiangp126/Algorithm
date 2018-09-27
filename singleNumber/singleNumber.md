## Single Number
<https://leetcode.com/problems/single-number/description/>

### core concept

```bash
a ^ a = 0
a ^ 0 = a
a ^ b = b ^ a
```

### code
```c
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int num : nums) {
            ret ^= num;
        }
        return ret;
    }
};
```
