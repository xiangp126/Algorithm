## Binary Tree Postorder Traversal
### Illustrate
<https://leetcode.com/problems/binary-tree-postorder-traversal/>

### Example
```c
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
```

### Concept
_according to definition of `PostOrder Traversal`_

**PostOrder** `left -> right -> root`, reverse as `root->right->left`

**PreOrder**&nbsp;&nbsp;&nbsp;`root -> left -> right`

---
take advantage of **Preorder Traversal**

> traverse `root` firstly, then push `right` node into stack, then the left node<br>
reverse `result vector` at last

`root -> right -> left`

_reverse it yields_

`left -> right -> root`

### Code - _Stack, in Contrast to Queue_

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == NULL) {
            return ret;
        }
        stack<TreeNode *> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *ptr = stk.top();
            // traverse data
            ret.push_back(ptr->val);
            stk.pop();

            // push each child into stack
            if (ptr->left != NULL) {
                stk.push(ptr->left);
            }
            if (ptr->right != NULL) {
                stk.push(ptr->right);
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```

### Code - _Recursive_
_according to definition of `PostOrder Traversal`_

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        postOrder(root, ret);
        return ret;
    }

    void postOrder(TreeNode *root, vector<int> &ret) {
        if (root == NULL) {
            return;
        }
        postOrder(root->left, ret);
        postOrder(root->right, ret);
        ret.push_back(root->val);
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> stk;
        TreeNode *ptr = root;
        while (!stk.empty() || ptr) {
            if (ptr != NULL) {
                ret.push_back(ptr->val);
                stk.push(ptr);
                // push right node
                ptr = ptr->right;
            } else {
                // stk.top() only get top of stack, not pop it
                ptr = stk.top();
                stk.pop();
                // points to left child
                ptr = ptr->left;
            }
        }
        // reverse ret in the end
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```
