## Binary Tree Inorder Traversal
### Illustrate
<https://leetcode.com/problems/binary-tree-inorder-traversal/>

### Input
```c
[1,null,2,3]

   1
    \
     2
    /
   3
```

### Output
```c
[1,3,2]
```

### Iteratively - Stack
_According to definition of InOrder Traversal_

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> stk;
        TreeNode *ptr = root;
        while (!stk.empty() || ptr) {
            if (ptr != NULL) {
                stk.push(ptr);
                ptr = ptr->left;
            } else {
                // stk.top() only get top of stack, not pop it
                ptr = stk.top();
                stk.pop();
                ret.push_back(ptr->val);
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inOrder(root, ret);
        return ret;
    }

    void inOrder(TreeNode *root, vector<int> &ret) {
        if (root == NULL) {
            return;
        }
        inOrder(root->left, ret);
        ret.push_back(root->val);
        inOrder(root->right, ret);
    }
};
```
