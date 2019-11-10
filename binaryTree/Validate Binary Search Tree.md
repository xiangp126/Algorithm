## Validate Binary Search Tree
### Illustrate
<https://leetcode.com/problems/validate-binary-search-tree/description>

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

* The left subtree of a node contains only nodes with keys **less than** the node's key.
* The right subtree of a node contains only nodes with keys **greater than** the node's key.
* Both the left and right subtrees must also be binary search trees.

### Example

```c
Input:
    2
   / \
  1   3
Output: true

    5
   / \
  1   4
     / \
    3   6
Output: false
Explanation: The input is: [5,1,4,null,null,3,6]. The root node's value
             is 5 but its right child's value is 4.
```

### Code - _with C++_

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
    bool isValidBST(TreeNode* root) {
        // return checkBST(root, INT_MIN, INT_MAX);
        return checkBST(root, LONG_MIN, LONG_MAX);
    }

     /*
      * checkBST: check value of root, should be greater than min
      *           and less than max
      * @root: denotes the TreeNode
      * @min: left value,  root->val > min
      * @max: right value, root->val < max
      *
      * Notice: both min and max was long, not int as root->val
      */
    bool checkBST(TreeNode *root, long min, long max) {
        if (root == NULL) {
            return true;
        }
        return root->val > min && root->val < max &&
               checkBST(root->left, min, root->val) &&
               checkBST(root->right, root->val, max);
    }
};
```

### Code - _with Java_

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
    public boolean isValidBST(TreeNode root) {
        return myValid(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    public boolean myValid(TreeNode root, long min, long max) {
        if (root == null) {
            return true;
        }
        return root.val > min && root.val < max
                && myValid(root.left, min, root.val)
                && myValid(root.right, root.val, max);
    }
}
```

### Debug
**INT_MAX = 2<sup>31</sup> - 1 = 2147483647**

> because type of `root->val` was `int`<br>
so just use of `INT_MIN` && `INT_MAX` may fail at input `[2147483647]`<br>
so change type of paramater of `checkBST` from `int` to `long` and pass `LONG_MIN`, `LONG_MAX` to it

- Wrong Try

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
    bool isValidBST(TreeNode* root) {
        return checkBST(root, INT_MIN, INT_MAX);
    }
    bool checkBST(TreeNode *root, int min, int max) {
        if (root == NULL) {
            return true;
        }
        return root->val > min && root->val < max &&
               checkBST(root->left, min, root->val) &&
               checkBST(root->right, root->val, max);
    }
};
```

- Failed Situation

```c
Input: [2147483647]
Output: false
Expected: true
```

```c
#define INT_MAX	2147483647
```
