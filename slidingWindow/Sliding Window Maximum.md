## Sliding Window Maximum
### Illustrate
<https://leetcode.com/problems/sliding-window-maximum/>

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

**Example**:

```
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

- reference

<https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/><br>
<https://github.com/Mohammed-Shoaib/Coding-Problems/blob/master/LeetCode/Solutions/LC0239.cpp?ts=4><br>
[面试官，你再问我滑动窗口问题试试？我有解题模板，不怕！](https://www.cxyxiaowu.com/672.html)

### Code
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (!nums.size() || k <= 0) return ret;
        // Do not initial the container with a fixed size.
        deque<int> Qi;
        for (int i = 0; i < nums.size(); ++i) {
            /**
             * Remove all elements smaller than the currently
             * being added element (remove useless elements).
             **/
            while (!Qi.empty() && nums[Qi.back()] < nums[i]) {
                Qi.pop_back();
            }

            // Add current element at the rear of Qi
            Qi.push_back(i);

            // Remove the elements which is out of this window
            if (Qi.front() <= i - k) {
                Qi.pop_front();
            }

            if (i >= k - 1) {
                ret.push_back(nums[Qi.front()]);
            }
        }
        return ret;
    }
};
```
