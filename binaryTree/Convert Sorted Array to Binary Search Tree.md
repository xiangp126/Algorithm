## Convert Sorted Array to Binary Search Tree
### Illustrate
<https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree>

Given an array where elements are sorted in **ascending order**, convert it to a **height balanced** BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

### Example
```c
Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
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