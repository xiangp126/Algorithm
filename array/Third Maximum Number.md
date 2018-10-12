## Third Maximum Number
### Illustrate
<https://leetcode.com/problems/third-maximum-number/>

### Code
```c
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int k = 0;
        const int N = nums.size();
        if (N == 0)
            return 0;
        // main loop
        while (k < N) {
            if (nums[k] != nums[i]) {
                nums[++i] = nums[k];
            }
            ++k;
        }
        // cout << "New Length = " << i + 1 << endl;
        return i + 1;
    }
};
```