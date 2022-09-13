## Contains Duplicate
### Illustrate
<https://leetcode.com/problems/contains-duplicate/>

### Code - Optimized
```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ret;
        for (auto num: nums) {
            if (ret.find(num) != ret.end()) {
                return true;
            } else {
                ret.insert(num);
            }
        }
        return false;
    }
};
```

### Code
```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ret(nums.begin(), nums.end());
        return ret.size() < nums.size();
    }
};
```