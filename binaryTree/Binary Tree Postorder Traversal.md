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
_According to definition of PostOrder Traversal_

**PostOrder** `left -> right -> root`, reverse as `root->right->left`

**PreOrder**&nbsp;&nbsp;&nbsp;`root -> left -> right`

---
take advantage of **preorderTraversal**

> traverse `root` firstly, then push `right` node into stack, then the left node<br>
reverse `result vector` at last

`root -> right -> left`

_reverse it yields_

`left -> right -> root`

### Iteratively - _Stack_

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

### Recursive
_According to definition of PostOrder Traversal_

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
