## Single Number
### Illustrate
<https://leetcode.com/problems/maximal-square/>

```
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
```

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
