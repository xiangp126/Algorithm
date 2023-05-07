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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        queue<TreeNode *> Qi;
        TreeNode *pNode = root;
        int level = 0; // level of the tree
        int qSize = 0; // size of the queue itself
        Qi.push(pNode);
        while (!Qi.empty()) {
            /* 
             * bug point: calculate the size of the queue before the for loop,
             * since Qi.size() may vary during the for looping
             */
            qSize = Qi.size();
            for (int i = 0; i < qSize; ++i) {
                pNode = Qi.front();
                Qi.pop();

                if (pNode->left){
                    Qi.push(pNode->left);
                }
                if (pNode->right) {
                    Qi.push(pNode->right);
                }
            } 
            ++level;
        }
        return level;
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
