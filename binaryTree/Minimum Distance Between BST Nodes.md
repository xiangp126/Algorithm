## Minimum Distance Between BST Nodes
### Illustrate
<https://leetcode.com/problems/minimum-distance-between-bst-nodes/>

just the same as

[Minimum Absolute Difference in BST.md](./Minimum Absolute Difference in BST.md)

Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

```
Example :

Input: root = [4,2,6,1,3,null,null]
Output: 1
Explanation:
Note that root is a TreeNode object, not an array.

The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

          4
        /   \
      2      6
     / \    
    1   3  

while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.
```
Note:

- The size of the BST will be between 2 and 100.
- The BST is always valid, each node's value is an integer, and each node's value is different.

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