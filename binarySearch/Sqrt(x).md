## Sqrt(x)
### Illustrate
<https://leetcode.com/problems/sqrtx/description/>

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

### Example
```c
Input: 4
Output: 2

Input: 8
Output: 2

Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
```


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