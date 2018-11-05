## Sum Root to Leaf Numbers
### Illustrate
<https://leetcode.com/problems/sum-root-to-leaf-numbers/>

Given a binary tree containing digits from `0-9` only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path `1->2->3` which represents the number `123`.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

### Example
```c
Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
```

### Code
```c

```


### Code - _Solution 2_

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
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(root, path, ret);
        int sum = 0, sub = 0;
        for (int i = 0; i < ret.size(); ++i) {
            sub = 0;
            // build each value
            for (int j = 0; j < ret[i].size(); ++j) {
                sub = sub * 10 + ret[i][j];
            }
            // sum each value up
            sum += sub;
        }
        return sum;
    }
    void dfs(TreeNode *root, vector<int> &path, vector<vector<int>> &ret) {
        if (root == NULL) {
            return;
        }
        path.push_back(root->val);

        // reach leaf
        if (root->left == NULL && root->right == NULL) {
            ret.push_back(path);
        }

        dfs(root->left,  path, ret);
        dfs(root->right, path, ret);

        path.pop_back();
    }
};
```
