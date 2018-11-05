## N-ary Tree Level Order Traversal
### Illustrate
<https://leetcode.com/problems/n-ary-tree-level-order-traversal/>

Given an n-ary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example, given a **3-ary** tree:

<div align=left><img src=./res/3-ary.png width=75%></img></div>

We should return its level order traversal:

```c
[
     [1],
     [3,2,4],
     [5,6]
]
```

Note:

* The depth of the tree is at most `1000`.
* The total number of nodes is at most `5000`.

### Code - _Queue_

```c
/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if (root == NULL) {
            return ret;
        }
        queue<Node *> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> path;
            for (int i = 0; i < size; ++i) {
                Node *ptr = que.front();
                path.push_back(ptr->val);
                que.pop();
                for (int j = 0; j < ptr->children.size(); ++j) {
                    if (ptr->children[j] != NULL) {
                        que.push(ptr->children[j]);
                    }
                }
            }
            ret.push_back(path);
        }
        return ret;
    }
};
```