## Binary Tree Zigzag Level Order Traversal
### Illustrate
<https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/>

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

### Example
```c
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
```

### Code - _Queue_

_there is no `push_front` for vector, so use **`vector::insert`** instead_

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == NULL) {
            return ret;
        }
        queue<TreeNode *> que;
        que.push(root);
        int loop = 1;
        while (!que.empty()) {
            vector<int> path;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *ptr = que.front();
                if (loop & 0x1) {
                    path.push_back(ptr->val);
                } else {
                    // push from front
                    path.insert(path.begin(), ptr->val);
                }
                que.pop();
                if (ptr->left != NULL) {
                    que.push(ptr->left);
                }
                if (ptr->right != NULL) {
                    que.push(ptr->right);
                }
            }
            ret.push_back(path);
            ++loop;
        }
        return ret;
    }
};
```

### Code - _Recursive_

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
        if (level & 0x1) {
            // push from front
            ret[level].insert(ret[level].begin(), root->val);
        } else {
            ret[level].push_back(root->val);
        }
        dfs(root->left, ret, level + 1);
        dfs(root->right, ret, level + 1);
    }
};
```
