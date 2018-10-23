## Merge Two Sorted Lists
### Illustrate
<https://leetcode.com/problems/merge-two-sorted-lists>

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

### Example

```c
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
```

### Code

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *ptr = &dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = (l1 != NULL) ? l1 : l2;
        return dummy.next;
    }
};
```