#ifndef TREE_H_
#define TREE_H_

class SearchTree;
class TreeNode;

class TreeNode {
    int key;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val = 0) : key(_val), left(NULL), right(NULL) {}
};

class SearchTree {
    public:
        TreeNode *root;
    public:
        SearchTree() : root(NULL);
        insert(int);
}

#endif /* ifndef TREE_H_ */
