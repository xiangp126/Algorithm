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

### Code - _using Queue_

- there is no `push_front` for `vector`, so use **`vector::insert`** instead
- use `flag` & `0x01` instead of positive/negative `1`

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) {
            return ret;
        }
        queue<TreeNode *> que;
        TreeNode *node = root;
        que.push(node);

        int qSize = 0;
        int flag = 1;
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

            if (flag & 0x01) {
                ret.push_back(path);
            } else {
                std::reverse(path.begin(), path.end());
                ret.push_back(path);
            }
            ++flag;
        }
        return ret;
    }
};
```

### Code - _using dfs(Depth-First Search)_

_Time complexity O(N)_

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
