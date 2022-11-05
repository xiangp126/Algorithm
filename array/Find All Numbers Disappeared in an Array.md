## Find All Numbers Disappeared in an Array
### Illustrate
<https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array>

Given an array of integers where `1 ≤ a[i] ≤ n` (n = size of array), some elements appear twice and others appear once.

Find all the elements of **[1, n]** inclusive that do not appear in this array.

Could you do it without extra space and in **O(n)** runtime? You may assume the returned list does not count as extra space.

### Example
```
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
```

### Code
```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        const int N = nums.size();
        vector<bool> bitMap(N + 1, false);
        for (auto num: nums) {
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

or use `Array` instead of `Vector` for `bitMap`
