## Contains Duplicate II
### Illustrate
<https://leetcode.com/problems/contains-duplicate-ii/>

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

### Code - unordered_map
```c++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> uMap;
        for (int i = 0; i < nums.size(); ++i) {
            uMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (uMap.find(nums[i]) != uMap.end()
                && uMap[nums[i]] != i) {
                if (abs(i - uMap[nums[i]]) <= k) {
                    return true;
                } else {
                    // update this index to pass the last case
                    // nums = [0,1,2,3,4,0,0,7,8,9,10,11,12,0]
                    // K = 1. The output should be true.
                    uMap[nums[i]] = i;
                }
            }
        }
        return false;
    }
};
```
