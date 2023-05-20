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

### Code - _Recursive with C++_

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return calc(root) >= 0;
    }

    int calc(TreeNode *root) {
        if (!root) {
            return 0;
        }

        // Calculate the depth of the left and right subtrees
        int leftDepth = calc(root->left);
        int rightDepth = calc(root->right);

        // If either subtree is imbalanced or the absolute difference
        // between the depths is greater than 1, return -1
        if (leftDepth < 0 || rightDepth < 0 || abs(leftDepth - rightDepth) > 1) {
            return -1;
        }

        // Return the maximum depth of the left and right subtrees plus 1
        return max(leftDepth, rightDepth) + 1;
    }
};
```

### Code - _Recursive with Java_

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        return calcHeight(root) >= 0;
    }
    
    int calcHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }
        
        int leftHeight = calcHeight(root.left);
        int rightHeight = calcHeight(root.right);
        if (leftHeight < 0 || rightHeight < 0
            || Math.abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return Math.max(leftHeight, rightHeight) + 1;
    }
}
```
