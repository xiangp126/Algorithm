## Search Insert Position
### Illustrate
<https://leetcode.com/problems/search-insert-position/>

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

### Example
```c
Input: [1,3,5,6], 5
Output: 2

Input: [1,3,5,6], 2
Output: 1

Input: [1,3,5,6], 7
Output: 4

Input: [1,3,5,6], 0
Output: 0
```


### Code
```c
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        const int N = nums.size();
        int left = 0;
        int right = N - 1;
        int mid = 0;
        // in case all elements was smaller than target
        // so initialize lastMid to N
        int lastMid = N;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                if (nums[mid] > target) {
                    right = mid - 1;
                    // only record lastMid on greater side
                    lastMid = mid;
                } else {
                    return mid;
                }
            }
        }
        return lastMid;
    }
};
```