## Find Peak Element
### Illustrate
<https://leetcode.com/problems/find-peak-element>

### Code
```c
// fix me
```

### Code - _Too Simple_
```c
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        const int N = nums.size();
        if (N == 1) {
            return 0;
        } else {
            if (nums[0] > nums[1]) {
                return 0;
            }
        }            
        // main search
        int i = 1;
        for (; i < N - 1; ++i) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                return i;
            }
        }
        // judge result
        if (i == N - 1) {
            return N - 1;
        } else {
            return 0;
        }
    }
};
```
