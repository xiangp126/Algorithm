## Merge Sorted Array
### Illustrate
<https://leetcode.com/problems/merge-sorted-array>

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

* The number of elements initialized in nums1 and nums2 are m and n respectively.
* You may assume that **nums1 has enough space** (size that is greater or equal to m + n) to hold additional elements from nums2.

### Example

```c
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
```

### Code
```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ia = m - 1;
        int ib = n - 1;
        int ic = m + n - 1;
        while (ia >= 0 && ib >= 0) {
            nums1[ic--] = (nums1[ia] >= nums2[ib]) ? nums1[ia--] : nums2[ib--];
        }

        // copy remaining elements from nums2 to nums1
        // there's no need to move elements if ia >= 0,
        // since nums1 is already sorted.
        #if 0
            while (ia >= 0) {
            nums1[ic--] = nums1[ia--];
        }
        #endif

        while (ib >= 0) {
            nums1[ic--] = nums2[ib--];
        }
    }
};
```