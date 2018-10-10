## Majority Element
### Illustrate
<https://leetcode.com/problems/majority-element/></br>
<http://www.cnblogs.com/grandyang/p/4233501.html>

```c
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
```

### Example
```c
Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
```

### Code - _Sort_
```c
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
```

### Code - _Moore Voting_
```c
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // maintain a candidate and counter
        int pivot = 0;
        int cnt = 0;
        for (auto val : nums) {
            if (cnt == 0) {
                // set candidate
                pivot = val;
                cnt = 1;
            } else {
                // update candidate
                if (val == pivot) {
                    ++cnt;
                } else {
                    --cnt;
                }
            }
        }
        return pivot;
    }
};
```
