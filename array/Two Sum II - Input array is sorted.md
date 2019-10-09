## Two Sum II - Input array is sorted
### Illustrate
<https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/>

Given an array of integers that is already **sorted in ascending order**, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are **not zero-based**.
You may assume that each input would have exactly one solution and you may not use the same element twice.

###Example
```c
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
```

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