## Maximum Depth of Binary Tree
### Illustrate
<https://leetcode.com/problems/maximum-depth-of-binary-tree/>

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

### Example
```c
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
```

### Code - _Queue_

_similar thought as `Binary Tree Level Order Traversal`_

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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int loop = 0;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *ptr = que.front();
                que.pop();
                if (ptr->left) {
                    que.push(ptr->left);
                }
                if (ptr->right) {
                    que.push(ptr->right);
                }
            }
            ++loop;
        }
        return loop;
    }
};
```

### Code - _Recursive_
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight  = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
};
```