## Remove Duplicates from Sorted Array
### Illustrate
<https://leetcode.com/problems/remove-duplicates-from-sorted-array>

Given a sorted array nums, remove the duplicates **in-place** such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by **modifying the input array** in-place with `O(1)` extra memory.

###Example
```c
Given nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.

It doesn't matter what you leave beyond the returned length.
```

or

```c
Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.
```

### Code
```c++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int N = nums.size();
        if (N == 0) {
            return 0;
        }

        int i = 0;
        int k = 0;
        while (i < N) {
            if (nums[i] != nums[k]) {
                nums[++k] = nums[i];
            }
            ++i;
        }
        // cout << "New Length = " << k + 1 << endl;
        return k + 1;
    }
};
```
