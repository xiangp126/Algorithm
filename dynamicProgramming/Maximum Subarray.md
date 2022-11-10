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
```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (!nums.size()) return 0;

        int sum = nums[0];
        int maxSub = sum;
        for (int i = 1; i < nums.size(); ++i) {
            if (sum >= 0) {
                sum += nums[i];
            } else {
                // begin a brand new start
                sum = nums[i];
            }
            maxSub = max(maxSub, sum);
        }
        return maxSub;
    }
};
```

_or_

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int N = nums.size();
        if (N <= 0) {
            return -1;
        }
        int sub = nums[0];
        int maxSub = sub;
        for (int i = 1; i < N; ++i) {
            sub = (sub >= 0) ? sub + nums[i] : nums[i];
            maxSub = max(maxSub, sub);
        }
        return maxSub;
    }
};
```
