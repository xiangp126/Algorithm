## Maximum Depth of Binary Tree
### Illustrate
<https://leetcode.com/problems/maximum-depth-of-binary-tree/>

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

### Example
```c
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.
```

### Code - _using Queue with C++_

- learn to calculate the depth of a tree
- similar idea as `Binary Tree Level Order Traversal`

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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode *> que;
        TreeNode *node = root;
        que.push(node);

        int maxDepth = 0;
        int qSize = 0;
        int i = 0;

        while (!que.empty()) {
            qSize = que.size();

            for (i = 0; i < qSize; ++i) {
                node = que.front();
                que.pop();

                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
            ++maxDepth;
        }
        return maxDepth;
    }
};
```

### Code - _using Queue with Java_
[Java Queue Tutorial](https://docs.oracle.com/javase/7/docs/api/java/util/Queue.html)

- remove

E remove()
Retrieves and removes the head of this queue. This method differs from poll only in that it throws an exception if this queue is empty.

Returns:
the head of this queue

Throws:
NoSuchElementException - if this queue is empty

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
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }

        Queue<TreeNode> que = new LinkedList<>();
        int qSize = 0;
        int depth = 0;

        TreeNode node = root;
        que.add(node);
        int i = 0;

        while (!que.isEmpty()) {
            qSize = que.size();
            for (i = 0; i < qSize; ++i) {
                node = que.element();
                que.remove();
                // or just one line
                // node = que.remove();

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

### Code - _Recursive_
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight  = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
};
```