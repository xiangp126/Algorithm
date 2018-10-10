## Binary Tree Postorder Traversal
### Illustrate
<https://leetcode.com/problems/binary-tree-postorder-traversal/>

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
[4,1,3,2]
```

### Concept
_According to definition of InOrder Traversal_

`PostOrder` left -> right -> root

`PreOrder`&nbsp;&nbsp;&nbsp;root -> left -> right

---
take advantage of **preorderTraversal**

> first push `right` node into stack, meanwhile insert val into `ret` from head not tail<br>
or you could inverse `ret` in the end

_root -> right -> left_

reverse it yields

_left -> right -> root_

### Iteratively - Stack


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
                // insert value from the head, not tail
                ret.insert(ret.begin(), ptr->val);
                stk.push(ptr);
                // first push right node
                ptr = ptr->right;
            } else {
                // stk.top() only get top of stack, not pop it
                ptr = stk.top();
                stk.pop();
                // last handle left node
                ptr = ptr->left;
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
