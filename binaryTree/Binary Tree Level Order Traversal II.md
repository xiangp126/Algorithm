## Binary Tree Level Order Traversal II
### Illustrate
<https://leetcode.com/problems/binary-tree-level-order-traversal-ii>

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

### Example
```c
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) {
            return ret;
        }

        TreeNode *node = root;
        queue<TreeNode *> que;
        que.push(node);

        int qSize = 0;
        vector<int> path;

        while (!que.empty()) {
            qSize = que.size();
            path.clear();
            for (int i = 0; i < qSize; ++i) {
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
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
```

### Code - _using dfs_

_reverse `ret` at last as `Binary Tree Level Order Traversal`_

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ret;
        dfs(root, ret, 0);
        reverse(ret.begin(), ret.end());
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
