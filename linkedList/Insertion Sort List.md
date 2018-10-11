## Insertion Sort List
### Illustrate
<https://leetcode.com/problems/insertion-sort-list/>

Algorithm of Insertion Sort:

1. Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
3. It repeats until no input elements remain.


### Example
```c
Input: 4->2->1->3
Output: 1->2->3->4

Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *newHead = new ListNode(INT_MIN);
        while(head) {
            ListNode *cur = head;
            ListNode *p = newHead;
            head = head->next;
            while(p->next && p->next->val<=cur->val)
                p = p->next;
            cur->next = p->next;
            p->next = cur;
        }

        head = newHead->next;
        delete newHead;
        return head;
    }
};
```
