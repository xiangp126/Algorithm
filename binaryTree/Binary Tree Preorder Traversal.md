## Binary Tree Preorder Traversal
### Illustrate
<https://leetcode.com/problems/binary-tree-preorder-traversal/>

### Example:
```c
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]
```

### Code - _using Stack Solution One with C++_

it's only one-line change from `inorderTraversal`, very easy

- sign between two criteria within the `while` is `||`
- `stk.top()` only gets the top elem of the stack, but not del it
- `stk.pop()` only dels the top elem of the stack, but not return its value

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }

        stack<TreeNode *> stk;
        TreeNode *node = root;

        while (node || !stk.empty()) {
            if (node) {
                // traverse this 'node'.
                ret.push_back(node->val);

                stk.push(node);
                node = node->left;
            } else {
                // pop top of the element of the stack.
                node = stk.top();
                stk.pop();

                node = node->right;
            }
        }
        return ret;
    }
};
```

### Code - _using Stack Solution Two with C++ -- easiest thinking_

_in contrast to [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/), using `stack` instead of `Queue`_

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }

        stack<TreeNode *> stk;
        TreeNode *node = root;
        stk.push(root);

        while (!stk.empty()) {
            // traverse 'node'
            node = stk.top();
            ret.push_back(node->val);
            stk.pop();

            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }
        return ret;
    }
};
```

### Code - _using Stack Solution One with Java_

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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ret = new ArrayList<>();
        if (root == null) {
            return ret;
        }
        Stack<TreeNode> stk = new Stack<>();
        TreeNode node = root;
        while ((node != null) || !stk.isEmpty()) {
            if (node != null) {
                ret.add(node.val);
                stk.push(node);
                node = node.left;
            } else {
                node = stk.pop();
                node = node.right;
            }
        }
        return ret;
    }
}
```

### Code - _using Stack Solution Two with Java_

_in contrast to [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/), using `stack` instead of `Queue`_

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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ret = new ArrayList<>();
        if (root == null) {
            return ret;
        }
        Stack<TreeNode> stk = new Stack<>();
        TreeNode node = root;
        stk.push(node);

        while (!stk.isEmpty()) {
            node = stk.pop();
            ret.add(node.val);

            if (node.right != null) {
                stk.push(node.right);
            }
            if (node.left != null) {
                stk.push(node.left);
            }
        }
        return ret;
    }
}
```

### Code - _Recursive the Simplest_
_according to the definition of `PreOrder Traversal`_ [trəˈvərs(ə)l]

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preOrder(root, ret);
        return ret;
    }

    void preOrder(TreeNode *root, vector<int> &ret) {
        if (root == NULL) {
            return;
        }
        ret.push_back(root->val);
        preOrder(root->left, ret);
        preOrder(root->right, ret);
    }
};
```
