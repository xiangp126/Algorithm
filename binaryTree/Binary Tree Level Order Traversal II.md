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

### Code - _Queue_

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
        if (root == NULL) {
            return ret;
        }
        vector<int> path;
        queue<TreeNode *> que;
        TreeNode *ptr = NULL;
        // push root into queue
        que.push(root);
        while (!que.empty()) {
            /*
             * Notice:
             * 1. que.size() must be reserved before loop,
             *    for que.size() may vary when push/pop
             * 2. get an empty path when every loop into while
             */
            path.erase(path.begin(), path.end());
            int size = que.size();
            // loop size times, one level
            for (int i = 0; i < size; ++i) {
                ptr = que.front();
                que.pop();
                path.push_back(ptr->val);
                if (ptr->left != NULL) {
                    que.push(ptr->left);
                }
                if (ptr->right != NULL) {
                    que.push(ptr->right);
                }
            }
            ret.push_back(path);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```

### Code - _Recursive_

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