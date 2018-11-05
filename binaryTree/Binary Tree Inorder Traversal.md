## Binary Tree Inorder Traversal
### Illustrate
<https://leetcode.com/problems/binary-tree-inorder-traversal/>

### Example
```c
Input: [1,2,3,4,5,6,7]

Output: [4,2,5,1,6,3,7]
```

### Code - _Stack, in Contrast to Queue_

```c
// fix me
```

### Code - _Recursive_
_according to definition of `InOrder Traversal`_

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

### Demo for Stack Solution 2
#### Step1
![](./res/inorder1.jpg)

#### Step2

![](./res/inorder2.jpg)

#### Step3
![](./res/inorder3.jpg)

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