## Minimum Depth of Binary Tree
### Illustrate
<https://leetcode.com/problems/minimum-depth-of-binary-tree/>

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

### Example
```c
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.

Given binary tree [1, 2]
    1
   /
  2
return its minimum depth = 2
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
    int minDepth(TreeNode* root) {
        int loop = 0;
        if (root == NULL) {
            return 0;
        }
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
                // found one leaf and return immediately
                if (ptr->left == NULL && ptr->right == NULL) {
                    return loop + 1;
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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL) {
            return minDepth(root->right) + 1;
        } else {
            if (root->right == NULL) {
                return minDepth(root->left) + 1;
            } else {
                // main branch
                int leftDepth = minDepth(root->left);
                int rightDepth = minDepth(root->right);
                return min(leftDepth, rightDepth) + 1;
            }
        }
    }
};
```