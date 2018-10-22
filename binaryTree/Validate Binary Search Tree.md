## Validate Binary Search Tree
### Illustrate
<https://leetcode.com/problems/validate-binary-search-tree/description>

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

* The left subtree of a node contains only nodes with keys **less than** the node's key.
* The right subtree of a node contains only nodes with keys **greater than** the node's key.
* Both the left and right subtrees must also be binary search trees.

### Example

```c
Input:
    2
   / \
  1   3
Output: true

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
```

### Tip

> use of `INT_MIN` && `INT_MAX` may fail at input `[2147483647]`, so use `LONG_MIN`, `LONG_MAX` instead

### Code

```c
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
    bool isValidBST(TreeNode* root) {
        // return checkBST(root, INT_MIN, INT_MAX);
        return checkBST(root, LONG_MIN, LONG_MAX);
    }

     /*
      * checkBST: check value of root, should be greater than lval
      *           and less than rval
      * @root: denotes the TreeNode
      * @lval: left value,  root->val > lval
      * @rval: right value, root->val < rval
      */
    bool checkBST(TreeNode *root, long lval, long rval) {
        if (root == NULL) {
            return true;
        }
        return root->val > lval && root->val < rval &&
               checkBST(root->left, lval, root->val) &&
               checkBST(root->right, root->val, rval);
    }
};
```
