## N-ary Tree Postorder Traversal
### Illustrate
<https://leetcode.com/problems/n-ary-tree-postorder-traversal/>

Given an n-ary tree, return the postorder traversal of its nodes' values.

For example, given a **3-ary** tree:

<div align=left><img src=./res/3-ary.png width=75%></img></div>

Return its postorder traversal as:

```c
[5,6,3,2,4,1]
```

### Code - _Stack_

_refer to `N-ary Tree Preorder Traversal`_

```c
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ret;
        if (root == NULL) {
            return ret;
        }
        stack<Node *> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node *ptr = stk.top();
            // traverse data
            ret.push_back(ptr->val);
            stk.pop();

            for (int i = 0; i < ptr->children.size(); ++i) {
                if (ptr->children[i] != NULL) {
                    stk.push(ptr->children[i]);
                }
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
```

### Code - _Recursive_
```c
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ret;
        postOrder(root, ret);
        return ret;
    }

    void postOrder(Node *root, vector<int> &ret) {
        if (root == NULL) {
            return;
        }
        for (int i = 0; i < root->children.size(); ++i) {
            postOrder(root->children[i], ret);
        }
        ret.push_back(root->val);
    }
};
```
