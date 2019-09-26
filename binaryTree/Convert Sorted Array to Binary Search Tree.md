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

### Testcase
`height balanced BST` is not unique, so my solution is also passed.

```c
Your Input: [-10,-3,0,5,9]
Output: [0,-10,5,null,-3,null,9]
Expected: [0,-3,9,-10,null,5]
```

### Code
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums, 0, nums.size() - 1);
    }

    /*
     * convert: build BST recursively
     * @nums: the ascended sorted array
     * @left: index range [left, right]
     * @right: right included
     * @return the root pointer of the (sub)tree
     */
    TreeNode* convert(vector<int> &nums, int left, int right) {
        if(left > right) {
            return NULL;
        }
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left  = convert(nums, left, mid - 1);
        root->right = convert(nums, mid + 1, right);
        return root;
    }
};
```