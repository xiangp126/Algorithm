## Find All Numbers Disappeared in an Array
### Illustrate
<https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array>

### Code
```c
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        const int N = nums.size();
        bool bitMap[N + 1] = {false};
        for (auto num : nums) {
            bitMap[num] = true;
        }
        for (int i = 1; i <= N; ++i) {
            if (!bitMap[i]) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
```