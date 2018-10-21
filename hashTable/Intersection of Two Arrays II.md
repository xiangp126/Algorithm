## Intersection of Two Arrays II
### Illustrate
<https://leetcode.com/problems/intersection-of-two-arrays-ii>

Given two arrays, write a function to compute their intersection.


* Each element in the result should appear as many times as it shows in both arrays.
* The result can be in any order.

Follow up:

* What if the given array is already sorted? How would you optimize your algorithm?
* What if nums1's size is small compared to nums2's size? Which algorithm is better?
* What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

### Example
```c
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:
```


### Code - _HashMap_
```c
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        // <num, count>
        unordered_map<int, int> hashMap;
        for (auto num : nums1) {
            ++hashMap[num];
        }
        // traverse nums2
        for (auto num : nums2) {
            int cnt = hashMap[num];
            if (cnt > 0) {
                ret.push_back(num);
                --hashMap[num];
            }
        }
        return ret;
    }
};
```