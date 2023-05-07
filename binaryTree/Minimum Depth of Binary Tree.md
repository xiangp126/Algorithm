## Minimum Depth of Binary Tree
### Illustrate
<https://leetcode.com/problems/minimum-depth-of-binary-tree/>

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

### Example
```c
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.

Given binary tree [1, 2]
    1
   /
  2
return its minimum depth = 2
```

### Code - _using Queue with C++_

- similar thought as `Binary Tree Level Order Traversal`
- one line change from `Maximum Depth of Binary Tree`

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode *> que;
        TreeNode *pNode = NULL;
        int depth = 0;
        que.push(root);

        while (!que.empty()) {
            int qSize = que.size();
            // Dump all the nodes in the same level
            for (int i = 0; i < qSize; ++i) {
                pNode = que.front();
                que.pop();

                /* Find one leaf, and we reach the point of min depth.
                 * Return immediately.
                 */
                if (pNode->left == NULL && pNode->right == NULL) {
                    return depth + 1;
                }

                if (pNode->left) {
                    que.push(pNode->left);
                }
                if (pNode->right) {
                    que.push(pNode->right);
                }
            }
            ++depth;
        }
        return depth;
    }
};
```

### Code - _using Queue with Java_

- similar thought as `Binary Tree Level Order Traversal`
- one line change with `Maximum Depth of Binary Tree`

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
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        Queue<TreeNode> que = new LinkedList<>();
        TreeNode node = root;
        que.add(node);

        int depth = 0;
        int qSize = 0;
        int i = 0;

        while (!que.isEmpty()) {
            qSize = que.size();

            for (i = 0; i < qSize; ++i) {
                node = que.remove();

                // find one leaf
                if ((node.left == null) && (node.right == null)) {
                    return depth + 1;
                }

                if (node.left != null) {
                    que.add(node.left);
                }
                if (node.right != null) {
                    que.add(node.right);
                }
            }
            ++depth;
        }
        return depth;
    }
}
```

### Code - _Recursive with C++_

3 Cases:

- only has `left` child, then calc the **right** depth
- only has `right` child, then calc the **left** depth
- both has `left` and `right` child, then calc the **minimum** depth

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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftDepth  = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        /*
         * The original solution computes the minimum depth of the
         * left and right subtrees and returns the minimum of these
         * two values plus one. However, this solution does not consider
         * the case where one of the subtrees is empty (i.e., NULL),
         * which can lead to incorrect results.
         */ 
        if (root->left == NULL) {
            return rightDepth + 1;
        } 
        if (root->right == NULL) {
            return leftDepth + 1;
        }
        
        return min(leftDepth, rightDepth) + 1;
    }
};
```

or

```cpp


```

### Code - _Recursive with Java_

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
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int leftHeight = minDepth(root.left);
        int rightHeight = minDepth(root.right);

        if (root.left == null) {
            return leftHeight + 1;
        } else {
            if (root.right == null) {
                return leftHeight + 1;
            } else {
                return Math.min(leftHeight, rightHeight) + 1;
            }
        }
    }
}
```
