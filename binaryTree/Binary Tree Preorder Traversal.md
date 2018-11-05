## Binary Tree Preorder Traversal
### Illustrate
<https://leetcode.com/problems/binary-tree-preorder-traversal/>

### Example:
```c
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
```

### Code - _Stack in Contrast to Queue_

_in contrast to `Binary Tree Level Order Traversal`, using `stack` instead_

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
        if (root == NULL) {
            return ret;
        }
        stack<TreeNode *> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode *ptr = stk.top();
            // traverse data
            ret.push_back(ptr->val);
            stk.pop();

            // first put right child into stack
            if (ptr->right != NULL) {
                stk.push(ptr->right);
            }
            if (ptr->left != NULL) {
                stk.push(ptr->left);
            }
        }
        return ret;
    }
};
```

### Code - _Recursive_
_according to definition of `PreOrder Traversal`_

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

### Code - _Stack Solution 2_

_now deprecated_

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
        // "|| ptr" only useful for first loop when stk was empty
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