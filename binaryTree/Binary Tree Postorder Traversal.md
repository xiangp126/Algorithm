## Binary Tree Postorder Traversal
### Illustrate
<https://leetcode.com/problems/binary-tree-postorder-traversal/>

### Example
```c
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]
```

### Concept
_according to the definition of `PostOrder Traversal`_

**PostOrder** `left -> right -> root`, reverse as `root->right->left`

**PreOrder**&nbsp;&nbsp;&nbsp;`root -> left -> right`

---
take advantage of **Preorder Traversal**

> traverse `root` firstly, then push `right` node into stack, then the left node<br>
reverse `result vector` at last

`root -> right -> left`

_reverse it yields_

`left -> right -> root`

### Code - _using Stack Solution Solution One with C++_
C++

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }
        stack<TreeNode *> stk;
        TreeNode *node = root;

        while (node || !stk.empty()) {
            if (node) {
                // traverse 'node'
                ret.push_back(node->val);

                stk.push(node);
                node = node->right;
            } else {
                node = stk.top();
                stk.pop();

                node = node->left;
            }
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
```

### Code - _using Stack Solution Two with C++_

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) {
            return ret;
        }
        stack<TreeNode *> stk;
        TreeNode *node = root;
        stk.push(node);

        while (!stk.empty()) {
            node = stk.top();
            stk.pop();

            // traverse 'node'
            ret.push_back(node->val);

            if (node->left) {
                stk.push(node->left);
            }
            if (node->right) {
                stk.push(node->right);
            }
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
```

### Code - _using Stack Solution Solution One with Java_
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
    public List<Integer> postorderTraversal(TreeNode root) {
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
                node = node.right;
            } else {
                node = stk.pop();
                node = node.left;
            }
        }
        Collections.reverse(ret);
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
    public List<Integer> postorderTraversal(TreeNode root) {
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
            
            if (node.left != null) {
                stk.push(node.left);
            }
            if (node.right != null) {
                stk.push(node.right);
            }
        }
        
        Collections.reverse(ret);
        return ret;
    }
}
```

### Code - _Recursive the Simplest_
_according to definition of `PostOrder Traversal`_

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        postOrder(root, ret);
        return ret;
    }

    void postOrder(TreeNode *root, vector<int> &ret) {
        if (root == NULL) {
            return;
        }
        postOrder(root->left, ret);
        postOrder(root->right, ret);
        ret.push_back(root->val);
    }
};
```
