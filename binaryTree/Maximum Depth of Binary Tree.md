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

### Code - _using Queue_

- learn to calculate the depth of a tree
- similar idea as `Binary Tree Level Order Traversal`

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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode *> que;
        TreeNode *node = root;
        que.push(node);

        int maxDepth = 0;
        int qSize = 0;
        int i = 0;

        while (!que.empty()) {
            qSize = que.size();

            for (i = 0; i < qSize; ++i) {
                node = que.front();
                que.pop();

                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            ++maxDepth;
        }
        return maxDepth;
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
