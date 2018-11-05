## Convert Sorted List to Binary Search Tree
### Illustrate
<https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/>

Given a singly linked list where elements are sorted in **ascending order**, convert it to a **height balanced** BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

### Example
```c
Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
```

### Code

_convert `list` to `vector` and refer **Convert Sorted Array to Binary Search Tree**_

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }
        return convert(nums, 0, nums.size() - 1);
    }

    /*
     * convert: build BST recursive
     * @nums: the ascended sorted nums
     * @left: index range [left, right]
     * @right: right included
     * @return the tree
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
