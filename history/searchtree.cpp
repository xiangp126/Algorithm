#include <iostream>
#include <stdlib.h>

using namespace std;

#define Error(str)       fprintf(stderr, "%s\n", str)
#define FatalError(str)  fprintf(stderr, "%s\n", str); exit(1)

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

struct TreeNode {
    int val;
    Position left;
    Position right;
};

int getVal(Position pNode) {
    if (!pNode) {
        return -1;
    }
    return pNode->val;
}

void printVal(Position pNode) {
    int ret = getVal(pNode);
    if (ret == -1) {
        cout << "Not found!" << endl;
    } else {
        cout << "Found Node: " << ret << endl;
    }
    return;
}

Position find(int nKey, SearchTree pTree) {
    if (!pTree) {
        return NULL;
    }
    if (nKey < pTree->val) {
        return find(nKey, pTree->left);
    } else if (nKey > pTree->val) {
        return find(nKey, pTree->right);
    } else {
        return pTree;
    }
}

Position findMax(SearchTree pTree) {
    if (!pTree) {
        return NULL;
    }
    while (pTree->right) {
        pTree = pTree->right;
    }
    return pTree;
}

Position findMin(SearchTree pTree) {
    if (!pTree) {
        return NULL;
    }
    while (pTree->left) {
        pTree = pTree->left;
    }
    return pTree;
}

// return ptr to new inserted TreeNode
SearchTree insert(int nKey, SearchTree pTree) {
    if (pTree == NULL) {
        pTree = new struct TreeNode[1];
        if (!pTree) {
            cout << "new error for pTree" << endl;
            exit(1);
        } else {
            pTree->val = nKey;
            pTree->left = NULL;
            pTree->right = NULL;
        }
    } else {
        if (nKey < pTree->val) {
            pTree->left = insert(nKey, pTree->left);
        } else {
            if (nKey > pTree->val) {
                pTree->right = insert(nKey, pTree->right);
            }
        }
    }
    return pTree;
}

void printNums(int *nums, int N) {
    int i = 0;
    for (i = 0; i < N; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void printTree(SearchTree pTree) {
    if (!pTree) {
        return;
    }
    printTree(pTree->left);
    cout << pTree->val << " ";
    printTree(pTree->right);
}

void preOrder(SearchTree pTree) {
    if (pTree) {
        cout << pTree->val << " ";
        preOrder(pTree->left);
        preOrder(pTree->right);
    }
}

SearchTree buildBST(int *nums, int N) {
    Position tree = insert(nums[0], NULL);
    for (int i = 1; i < N; ++i) {
        insert(nums[i], tree);
    }
    return tree;
}

/*! \brief
 *
 *  delete one Node of BST
 *
 * \param nKey key to delete
 * \param pTree BST to handle
 * \return BST that delete the Node
 */
SearchTree del(int nKey, SearchTree pTree) {
    Position tmpCell = NULL;
    if (pTree == NULL) {
        Error("Element not found");
        return pTree;
    }
    if (nKey < pTree->val) {
        pTree->left = del(nKey, pTree->left);
    } else {
        if (nKey > pTree->val) {
            pTree->right = del(nKey, pTree->right);
        }
        // found Node to delete
        else {
            // has both child
            if (pTree->left && pTree->right) {
                tmpCell = findMin(pTree->right);
                pTree->val = tmpCell->val;
                pTree->right = del(tmpCell->val, pTree->right);
                // one or zero child
            } else {
                tmpCell = pTree;
                if (pTree->left != NULL) {
                    pTree = pTree->left;
                } else {
                    if (pTree->right != NULL) {
                        pTree = pTree->right;
                    }
                }
                delete tmpCell;
            }
        }
    }
    return pTree;
}

int main(int argc, char *argv[])
{
    // binary search tree
    SearchTree bsTree = NULL;

    int N = 5;
    int nums[] = {6, 3, 2, 4, 7};
    printNums(nums, N);

    // build up the BST
    bsTree = buildBST(nums, N);
    printTree(bsTree);
    cout << endl;
    cout << "Min = " << findMin(bsTree)->val << endl;
    cout << "Max = " << findMax(bsTree)->val << endl;

    printVal(find(3, bsTree));
    printVal(find(7, bsTree));
    printVal(find(8, bsTree));

    cout << "insert 5" << endl;
    insert(5, bsTree);
    cout << "insert 9" << endl;
    insert(9, bsTree);
    cout << "insert 1" << endl;
    insert(1, bsTree);
    printTree(bsTree);
    cout << endl;

    cout << "delete 3" << endl;
    del(3, bsTree);
    cout << "delete 7" << endl;
    del(7, bsTree);
    cout << "delete 11" << endl;
    del(11, bsTree);
    printTree(bsTree);
    cout << endl;
#if 0
    cout << "pre order:" << endl;
    preOrder(bsTree);
#endif

    return 0;
}
