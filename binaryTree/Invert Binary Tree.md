## Invert Binary Tree
### Illustrate
<https://leetcode.com/problems/invert-binary-tree/>

Invert a binary tree.

Example:

Input:

```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```
Output:

```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

Trivia:

This problem was inspired by this original tweet by Max Howell:

```
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
```
### Code - _with C++_
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        
        TreeNode *pTmp = root->left;
        root->left = root->right;
        root->right = pTmp;
        
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
```

### Code - _with Java_

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
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        
        TreeNode pTmp = root.left;
        root.left = root.right;
        root.right = pTmp;
        
        invertTree(root.left);
        invertTree(root.right);

        return root;
    }
}
```