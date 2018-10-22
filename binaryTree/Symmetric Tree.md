## Symmetric Tree
### Illustrate
<https://leetcode.com/problems/symmetric-tree>

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

### Example
```c
binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
```

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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return mySymmetric(root->left, root->right);
    }
    
    bool mySymmetric(TreeNode *p, TreeNode *q) {
        if (p == NULL || q == NULL) {
            if (p == q) {
                return true;
            } else {
                return false;
            }
        }
        if (p->val == q->val) {
            return mySymmetric(p->left, q->right) &&
                   mySymmetric(p->right, q->left);
        } else {
            return false;
        }   
    }
};
```

_or_

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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return mySymmetric(root->left, root->right);
    }
    
    bool mySymmetric(TreeNode *p, TreeNode *q) {
        // return condition
        if (p == NULL || q == NULL) {
            if (p == q) {
                return true;
            } else {
                return false;
            }
        }
        // judge and dfs
        return p->val == q->val &&
               mySymmetric(p->left, q->right) &&
               mySymmetric(p->right, q->left);
    }
};
```