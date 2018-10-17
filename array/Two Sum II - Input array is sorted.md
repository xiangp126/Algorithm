## Two Sum II - Input array is sorted
### Illustrate
<https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/>

### Code
```c
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {        
        const int N = numbers.size();
        int left = 0;
        int right = N - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum < target) {
                ++left;
            } else {
                if (sum > target) {
                    --right;
                }
                else {
                    return vector<int> {left + 1, right + 1};
                }
            }
        }
        return vector<int> {}; 
    }
};
```