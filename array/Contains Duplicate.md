## Contains Duplicate
### Illustrate
<https://leetcode.com/problems/contains-duplicate/>

### Code - unordered_set
```c++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uSet;
        for (auto num: nums) {
            if (uSet.find(num) != uSet.end()) {
                return true;
            }
            uSet.insert(num);
        }
        return false;
    }
};
```

or simply

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uSet(nums.begin(), nums.end());
        return nums.size() > uSet.size();
    }
};
```
