## Single Number
<https://leetcode.com/problems/single-number/description/>

```
Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,1]
Output: 1
Example 2:

Input: [4,1,2,1,2]
Output: 4
```
### Core Concept

```bash
a ^ a = 0
a ^ 0 = a
a ^ b = b ^ a
```

### Code
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
