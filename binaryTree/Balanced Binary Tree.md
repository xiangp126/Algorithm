## Balanced Binary Tree
### Illustrate
<https://leetcode.com/problems/balanced-binary-tree>

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

### Example
```c
Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
```

### Code - _Recursive_

_refer the routine calculating `Maximum Tree Depth`_

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
    bool isBalanced(TreeNode* root) {
        return calcDepth(root) >= 0;
    }

    /*
     * calcDepth: calculate Tree Depth and meanwhile judge if it's balanced
     * @root: input tree
     * @return Tree Depth under normal condition
     * @return -1 if not balanced (sub)tree
     */
    int calcDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int leftDepth  = calcDepth(root->left);
        int rightDepth = calcDepth(root->right);
        if (leftDepth < 0 || rightDepth < 0
                          || abs(leftDepth - rightDepth) > 1) {
            return -1;
        } else {
            return max(leftDepth, rightDepth) + 1;
        }
    }
};
```