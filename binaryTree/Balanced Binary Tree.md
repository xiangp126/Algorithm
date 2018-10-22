## Balanced Binary Tree
### Illustrate
<https://leetcode.com/problems/balanced-binary-tree>

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    bool isBalanced(TreeNode* root) {
        return depth(root) >= 0;
    }
    
    // @return -1 if not balanced Tree
    // @return Teee Depth under normal situation
    int depth(TreeNode *root) {
        // return situation
        if (root == NULL) {
            return 0;
        }
        int leftHeight  = depth(root->left);
        int rightHeight = depth(root->right);
        // judge
        if (leftHeight == -1 || rightHeight == -1
                || abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        // calculate
        return max(leftHeight, rightHeight) + 1;
    }
};
```