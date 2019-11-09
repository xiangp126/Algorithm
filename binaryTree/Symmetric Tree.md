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

### Code - _using C++_

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

### Code - _using Java_

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        return symmetric(root.left, root.right);
    }

    public boolean symmetric(TreeNode p, TreeNode q) {
        if (p == null && q != null) {
            return false;
        }

        if (p != null && q == null) {
            return false;
        }

        if (p == null && q == null) {
            return true;
        }

        return p.val == q.val
            && symmetric(p.left, q.right)
            && symmetric(p.right, q.left);
    }
}
```
