## Maximum Subarray
### Illustrate
<https://leetcode.com/problems/maximum-subarray>

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

### Example
```c
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```
### Code
```c
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 0) {
            return -1;
        }
        // handle main body
        int sub = nums[0];
        int maxSub = sub;
        for (int i = 1; i < N; ++i) {
            if (sub > 0) {
                sub += nums[i];
            } else {
                // add from a new start
                sub = nums[i];
            }
            maxSub = max(maxSub, sub);
        }
        return maxSub;
    }
};
```

_or_

```c
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 0) {
            return -1;
        }
        // handle main body
        int sub = nums[0];
        int maxSub = sub;
        for (int i = 1; i < N; ++i) {
            sub = (sub > 0) ? sub + nums[i] : nums[i];
            maxSub = max(maxSub, sub);
        }
        return maxSub;
    }
};
```