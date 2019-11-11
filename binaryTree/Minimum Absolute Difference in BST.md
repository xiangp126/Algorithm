## Minimum Absolute Difference in BST
### Illustrate
<https://leetcode.com/problems/minimum-absolute-difference-in-bst/>

Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

```
Input:

   1
    \
     3
    /
   2

Output:
1
```

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 

Note: There are at least two nodes in this BST.

### Code - _using extra space with C++_

- Inorder traversal gives sorted sequence in BST
- So we have to compare the current node with the previous node

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
    int getMinimumDifference(TreeNode* root) {
        vector<int> nums;
        inOrder(root, nums);
        return helper(nums);
    }
    
    void inOrder(TreeNode *root, vector<int> &nums) {
        if (root == NULL) {
            return;
        }
        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
    }
    
    int helper(vector<int> &nums) {
        int minGap = INT_MAX;
        for (int i = 1; i < nums.size(); ++i) {
            minGap = min(minGap, nums[i] - nums[i - 1]);
        }
        return minGap;
    }
};
```

### Code - _using Stack for InOrder Traversal with C++_

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
    int getMinimumDifference(TreeNode* root) {
        if (!root) {
            return 0;
        }
        stack<TreeNode *> stk;
        TreeNode *node = root;
        TreeNode *preNode = NULL;
        int minDiff = INT_MAX;
        
        while (node || !stk.empty()) {
            if (node != NULL) {
                stk.push(node);
                node = node->left;
            } else {
                node = stk.top();
                stk.pop();
                
                if (preNode != NULL) {
                    minDiff = min(minDiff, node->val - preNode->val);
                }
                        
                preNode = node;
                node = node->right;
            }
        }
        return minDiff;
    }
};
```

### Code - _using Stack for InOrder Traversal with Java_
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
    public int getMinimumDifference(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Stack<TreeNode> stk = new Stack<>();
        int minDiff = Integer.MAX_VALUE;
        TreeNode node = root;
        TreeNode preNode = null;
        
        while ((node != null) || !stk.isEmpty()) {
            if (node != null) {
                stk.push(node);
                node = node.left;
            } else {
                node = stk.pop();
                
                if (preNode != null) {
                    minDiff = Math.min(minDiff, node.val - preNode.val);
                }
                
                preNode = node;
                node = node.right;
            }
        }
        return minDiff;
    }
}
```