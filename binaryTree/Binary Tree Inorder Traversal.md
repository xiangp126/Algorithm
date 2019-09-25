## Binary Tree Inorder Traversal
### Illustrate
<https://leetcode.com/problems/binary-tree-inorder-traversal/>

### Example
```c
Input: [1,2,3,4,5,6,7]

Output: [4,2,5,1,6,3,7]
```

### Code - _Iterative Using Stack Solution One_

- sign between two criteria within the `while` is `||`
- `stk.top()` only gets the top elem of the stack, but not del it
- `stk.pop()` only dels the top elem of the stack, but not return its value

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }
        stack<TreeNode *> stk;
        TreeNode *node = root;

        while (node || !stk.empty()) {
            if (node) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                // traverse 'node'
                ret.push_back(node->val);

                node = node->right;
            }
        }
        return ret;
    }
};
```

### Demo for Stack Solution One
#### Step1
![](./res/inorder1.jpg)

#### Step2

![](./res/inorder2.jpg)

#### Step3
![](./res/inorder3.jpg)

### Code - _Recursive the Simplest_
_according to definition of `InOrder Traversal`_

UK [trəˈvərs(ə)l]  USA [trəˈvərs(ə)l]

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
