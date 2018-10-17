## Path Sum II
### Illustrate
<https://leetcode.com/problems/path-sum-ii/>

### Code
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ret;
        vector<int> path;
        dfs(root, sum, path, ret);
        return ret;
    }
    
    void dfs(TreeNode *root, int gap, vector<int> &path,
                                      vector<vector<int> > &ret) {
        if (root == NULL) {
            return;
        }
        path.push_back(root->val);
        
        // Leaf
        if (root->left == NULL && root->right == NULL) {
            if (root->val == gap) {
                ret.push_back(path);
            }
        }
        
        dfs(root->left,  gap - root->val, path, ret);
        dfs(root->right, gap - root->val, path, ret);
        
        // pop back
        path.pop_back();
    }
};
```