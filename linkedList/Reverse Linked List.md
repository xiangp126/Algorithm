## Reverse Linked List
### Illustrate
<https://leetcode.com/problems/reverse-linked-list/>

    Reverse a singly linked list.

### Example
```c
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
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
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(-1);
        ListNode *ptr = &dummy;
        ListNode *curr = head;
        ListNode *pTmp = NULL;
        while (curr != NULL) {
            // reserve curr->next
            pTmp = curr->next;
            curr->next = ptr->next;
            ptr->next  = curr;
            curr = pTmp;
        }
        return dummy.next;
    }
};
```
