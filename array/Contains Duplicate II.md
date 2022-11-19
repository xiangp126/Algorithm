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
            if (uMap.find(nums[i]) != uMap.end()
                && (abs(uMap[nums[i]] - i) <= k)) {
                return true;
            }
            // Record or update the value
            uMap[nums[i]] = i;
        }
        return false;
    }
};
```
