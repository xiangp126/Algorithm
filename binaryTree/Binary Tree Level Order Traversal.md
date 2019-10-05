## Binary Tree Level Order Traversal
### Illustrate
<https://leetcode.com/problems/binary-tree-level-order-traversal>

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

### Example
```c
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
```

### Code - _using Queue_

Bug Notice:

- `que.size()` must be reserved before the loop, cos `que.size()` may vary when after `push/pop`
- set `path` empty before next loop

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) {
            return ret;
        }

        TreeNode *node = root;
        queue<TreeNode *> que;
        que.push(node);

        vector<int> path;
        int qSize = 0;
        int i = 0;

        while (!que.empty()) {
            qSize = que.size();
            path.clear();
            for (i = 0; i < qSize; ++i) {
                node = que.front();
                que.pop();
                path.push_back(node->val);

                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            ret.push_back(path);
        }
        return ret;
    }
};
```

### Code - _using dfs(Depth-First Search)_

_Time O(N)_

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        dfs(root, ret, 0);
        return ret;
    }
    // level start from 0
    void dfs(TreeNode *root, vector<vector<int> > &ret, int level) {
        if (root == NULL) {
            return;
        }
        // ret originally was empty
        if (ret.size() <= level) {
            ret.push_back(vector<int>());
        }
        ret[level].push_back(root->val);
        dfs(root->left, ret, level + 1);
        dfs(root->right, ret, level + 1);
    }
};
```
