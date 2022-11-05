## Find the Duplicate Number
### Illustrate
<https://leetcode.com/problems/find-the-duplicate-number/description/>

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

### Code - _Basic using Bit Map with C++_

```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const int N = nums.size();
        vector<bool> bitMap(N, false);
        for (auto num: nums) {
            if (bitMap[num]) {
                return num;
            } else {
                bitMap[num] = true;
            }
        }
        return -1;
    }
};
```
