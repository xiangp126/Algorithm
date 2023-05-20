## Convert Sorted List to Binary Search Tree
### Illustrate
<https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/>

Given a singly linked list where elements are sorted in **ascending order**, convert it to a **height balanced** BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

### Example
```c
Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
```

### Code - _Fast & Slow Pointer_
ideas are simple as that of Array, think how to half divide it and then conquer.

```c++
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        if (!head->next) {
            // Base case: Only one element in the linked list
            return new TreeNode(head->val, nullptr, nullptr);
        }

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *preSlow = slow;

        while (fast && fast->next) {
            fast = fast->next->next;
            preSlow = slow;
            slow = slow->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        preSlow->next = nullptr;

        // Recursively convert the left and right parts of the linked list to BST
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
```

#### Tips
you can also divide the `list` by adding a terminating `NULL` to the left part,

in which case the `tail` of `buildTree` will always be `NULL`.

```c++
ListNode *pre = head;
// TODO
while (fast != tail && fast->next != tail) {
    // add this line
    pre = slow;
    slow = slow->next;
    fast = fast->next->next;
}

pre->next = NULL
```

and here is the complete code of `Tips` version:

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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        if (!head->next) {
            // Base case: Only one element in the linked list
            return new TreeNode(head->val, nullptr, nullptr);
        }

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *preSlow = slow;

        while (fast && fast->next) {
            fast = fast->next->next;
            preSlow = slow;
            slow = slow->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        preSlow->next = nullptr;

        // Recursively convert the left and right parts of the linked list to BST
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
    }
};
```

### Code - _Convert to Array_

_convert `list` to `vector` and refer **Convert Sorted Array to Binary Search Tree**_

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }
        return buildTree(nums, 0, nums.size() - 1);
    }

    /*
     * buildTree: build BST recursive
     * @nums: the ascended sorted array
     * @left: index range [left, right]
     * @right: right included
     * @return the root pointer of the (sub)tree
     */
    TreeNode* buildTree(vector<int> &nums, int left, int right) {
        if(left > right) {
            return NULL;
        }
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left  = buildTree(nums, left, mid - 1);
        root->right = buildTree(nums, mid + 1, right);
        return root;
    }
};
```
