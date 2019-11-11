## Sum of Left Leaves
### Illustrate
<https://leetcode.com/problems/sum-of-left-leaves/>

Find the sum of all left leaves in a given binary tree.

```
Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        sumLeaves(root, false, sum);
        return sum;
    }
    
    void sumLeaves(TreeNode *root, bool isLeft, int &sum) {
        if (root == NULL) {
            return;
        }
        
        // find left leaf
        if (root->left == NULL && root->right == NULL && isLeft) {
            sum += root->val;
        }
        
        sumLeaves(root->left, true, sum);
        sumLeaves(root->right, false, sum);
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
    public int sumOfLeftLeaves(TreeNode root) {
        sum = 0;
        sumLeaves(root, false);
        return sum;
    }

    public void sumLeaves(TreeNode root, boolean isLeft) {
        if (root == null) {
            return;
        }
        
        // find left leaf
        if ((root.left == null) && (root.right == null) && isLeft) {
            sum += root.val;
        }
        
        sumLeaves(root.left, true);
        sumLeaves(root.right, false);
    }

    private int sum;
}
```