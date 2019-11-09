## N-ary Tree Postorder Traversal
### Illustrate
<https://leetcode.com/problems/n-ary-tree-postorder-traversal/>

Given an n-ary tree, return the postorder traversal of its nodes' values.

For example, given a **3-ary** tree:

<div align=left><img src=./res/3-ary.png width=60%></img></div>

Return its postorder traversal as:

```c
[5,6,3,2,4,1]
```

### Code - _using Stack with C++_

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

### Code - _using Stack with Java_

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
    public List<Integer> postorder(Node root) {
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
            for (Node child : node.children) {
                if (child != null) {
                    stk.push(child);
                }
            }
        }
        Collections.reverse(ret);
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
