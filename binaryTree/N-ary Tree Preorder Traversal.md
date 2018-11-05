## N-ary Tree Preorder Traversal
### Illustrate
<https://leetcode.com/problems/n-ary-tree-preorder-traversal/>

Given an n-ary tree, return the preorder traversal of its nodes' values.

For example, given a **3-ary** tree:

<div align=left><img src=./res/3-ary.png width=75%></img></div>

Return its preorder traversal as:

```c
[1,3,5,6,2,4]
```

### Code - _Stack_

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
    vector<int> preorder(Node* root) {
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

            for (int i = ptr->children.size() - 1; i >= 0; --i) {
                if (ptr->children[i] != NULL) {
                    stk.push(ptr->children[i]);
                }
            }
        }
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
    vector<int> preorder(Node* root) {
        vector<int> ret;
        preOrder(root, ret);
        return ret;
    }

    void preOrder(Node *root, vector<int> &ret) {
        if (root == NULL) {
            return;
        }
        ret.push_back(root->val);
        for (int i = 0; i < root->children.size(); ++i) {
            preOrder(root->children[i], ret);
        }
    }
};
```
