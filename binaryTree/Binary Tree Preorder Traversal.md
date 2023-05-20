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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }

        stack<TreeNode*> stk;
        TreeNode* pNode = root;

        while (pNode || !stk.empty()) {
            if (pNode) {
                // Process the current node
                ret.push_back(pNode->val);

                // Push the current node to the stack and move to its left subtree
                stk.push(pNode);
                pNode = pNode->left;
            } else {
                // Pop a node from the stack and move to its right subtree
                pNode = stk.top();
                stk.pop();

                pNode = pNode->right;
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }

        stack<TreeNode *> stk;
        TreeNode *pNode = root;
        stk.push(pNode);

        while (!stk.empty()) {
            pNode = stk.top();
            stk.pop();

            // Process the current node (add value to the result vector)
            ret.push_back(pNode->val);

            // Push the right child first, as it will be processed after left child
            if (pNode->right) {
                stk.push(pNode->right);
            }

            // Push the left child
            if (pNode->left) {
                stk.push(pNode->left);
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
