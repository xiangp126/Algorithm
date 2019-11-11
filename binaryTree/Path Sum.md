## Path Sum
### Illustrate
<https://leetcode.com/problems/path-sum/>

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

```
Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
```

return true, as there exist a root-to-leaf path `5->4->11->2` which sum is 22.

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
    bool hasPathSum(TreeNode* root, int sum) {
        return dfs(root, sum);
    }
            
    bool dfs(TreeNode *root, int gap) {
        if (root == NULL) {
            return false;
        }
        
        if (root->left == NULL && root->right == NULL
            && root->val == gap) {
            return true;
        }
        
        return dfs(root->left, gap - root->val)
            || dfs(root->right, gap - root->val);
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
    public boolean hasPathSum(TreeNode root, int sum) {
        return dfs(root, sum);
    }

    public boolean dfs(TreeNode root, int gap) {
        if (root == null) {
            return false;
        }

        if (root.left == null && root.right == null
                && root.val == gap) {
            return true;
        }

        return dfs(root.left, gap - root.val) ||
                dfs(root.right, gap - root.val);
    }
}
```