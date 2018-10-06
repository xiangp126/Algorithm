## Remove Element
<https://leetcode.com/problems/remove-element/>

### core concept

two iterators

### code
```c
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int k = 0;
        const int N = nums.size();
        while (k < N) {
            if (nums[k] != val) {
                nums[i++] = nums[k];
            }
            ++k;
        }
        return i;
    }
};
```
