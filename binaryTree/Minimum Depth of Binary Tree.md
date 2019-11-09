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
- one line change with `Maximum Depth of Binary Tree`

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
        int loop = 0;
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *ptr = que.front();
                que.pop();

                // find one leaf and return immediately
                if (ptr->left == NULL && ptr->right == NULL) {
                    return loop + 1;
                }

                if (ptr->left) {
                    que.push(ptr->left);
                }
                if (ptr->right) {
                    que.push(ptr->right);
                }
            }
            ++loop;
        }
        return loop;
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

        if (root->left == NULL) {
            return rightDepth + 1;
        } else {
            if (root->right == NULL) {
                return leftDepth + 1;
            } else {
                // has both left & right child
                return min(leftDepth, rightDepth) + 1;
            }
        }
    }
};
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
