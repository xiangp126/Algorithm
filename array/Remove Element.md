## Remove Element
### Illustrate
<https://leetcode.com/problems/remove-element/>

Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

###Example
```c
Given nums = [0,1,2,2,3,0,4,2], val = 2,

Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.

Note that the order of those five elements can be arbitrary.

It doesn't matter what values are set beyond the returned length.
```

### Code - _Two Iterators_
```c
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int k = 0;
        const int N = nums.size();
        while (i < N) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
            ++i;
        }
        return k;
    }
};
```