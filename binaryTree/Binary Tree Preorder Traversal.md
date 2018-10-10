## Binary Tree Preorder Traversal
### Illustrate
<https://leetcode.com/problems/binary-tree-preorder-traversal/>

### Input
```c
[2,1,3,null,4]

   2
 /   \
1     3
 \ 
  4 
```

### Output
```c
[2,1,4,3]
```

### Iteratively - Stack
_According to definition of PreOrder Traversal_

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> stk;
        TreeNode *ptr = root;
        while (!stk.empty() || ptr) {
            if (ptr != NULL) {
                // only one-line change with inorderTraversal
                ret.push_back(ptr->val);
                stk.push(ptr);
                ptr = ptr->left;
            } else {
                // stk.top() only get top of stack, not pop it
                ptr = stk.top();
                stk.pop();
                ptr = ptr->right;
            }
        }
        return ret;
    }
};
```

### Recursive
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preOrder(root, ret);
        return ret;
    }

    void preOrder(TreeNode *root, vector<int> &ret) {
        if (root == NULL) {
            return;
        }
        ret.push_back(root->val);
        preOrder(root->left, ret);
        preOrder(root->right, ret);
    }
};
```