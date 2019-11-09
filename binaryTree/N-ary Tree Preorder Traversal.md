## N-ary Tree Preorder Traversal
### Illustrate
<https://leetcode.com/problems/n-ary-tree-preorder-traversal/>

Given an n-ary tree, return the preorder traversal of its nodes' values.

For example, given a **3-ary** tree:

<div align=left><img src=./res/3-ary.png width=60%></img></div>

Return its preorder traversal as:

```c
[1,3,5,6,2,4]
```

### Code - _using Stack with C++_

```c++
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

### Code - _using Stack with C++_
```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> ret = new ArrayList<>();
        if (root == null) {
            return ret;
        }
        Stack<Node> stk = new Stack<>();
        Node node = root;
        stk.push(node);
        
        while (!stk.isEmpty()) {
            node = stk.pop();
            ret.add(node.val);
            for (int i = node.children.size() - 1; i >= 0; --i) {
                if (node.children.get(i) != null) {
                    stk.push(node.children.get(i));
                }
            }
        }
        return ret;
    }
}
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