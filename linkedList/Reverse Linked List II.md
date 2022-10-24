## Reverse Linked List II
### Illustrate
<https://leetcode.com/problems/reverse-linked-list-ii/>

    Reverse a linked list from position m to n. Do it in one-pass.
    
    Note: 1 ≤ m ≤ n ≤ length of list.

### Example
```c
Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
```

### Code
```c++
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *pre = &dummy;
        ListNode *curr = head;
        int k = m;
        while(--k) {
            pre  = curr;
            curr = curr->next;
        }
        int times = n - m;
        while(times-- ) {
            ListNode *pTmp = curr;
            curr = curr->next;
            pTmp->next = curr->next;
            curr->next = pre->next;
            pre->next  = curr;
            curr = pTmp;
        }
        return dummy.next;
    }
};
```
