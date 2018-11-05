## Maximum Depth of N-ary Tree
### Illustrate
<https://leetcode.com/problems/maximum-depth-of-n-ary-tree/>

Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

For example, given a **3-ary** tree:

<div align=left><img src=./res/3-ary.png width=60%></img></div>

We should return its max depth, which is 3.

Note:

* The depth of the tree is at most `1000`.
* The total number of nodes is at most `5000`.

### Code - _Queue_

_similar thought as `Binary Tree Level Order Traversal`_

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
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int loop = 0;
        queue<Node *> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                Node *ptr = que.front();
                que.pop();
                // push each child into que
                for (int j = 0; j < ptr->children.size(); ++j) {
                    if (ptr->children[j] != NULL) {
                        que.push(ptr->children[j]);
                    }
                }
            }
            ++loop;
        }
        return loop;
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
    int maxDepth(Node* root) {
        if (root == NULL) {
            return 0;
        }
        int mDepth = 0;
        for (int i = 0; i < root->children.size(); ++i) {
            mDepth = max(mDepth, maxDepth(root->children[i]));
        }
        return mDepth + 1;
    }
};
```