## Sort List
### Illustrate
<https://leetcode.com/problems/sort-list/>

    Sort a linked list in O(n log n) time using constant space complexity.

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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *fastPtr = head->next;
        ListNode *slowPtr = head;
        while (fastPtr != NULL && fastPtr->next != NULL) {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        // create two sub-list
        fastPtr = slowPtr->next;
        slowPtr->next = NULL;
        // [head, fastPtr => NULL] and [slowPtr->next, NULL]
        ListNode *left  = sortList(head);
        ListNode *right = sortList(fastPtr);
        return mergeTwoLinkedList(left, right);
    }

    ListNode *mergeTwoLinkedList(ListNode *list1, ListNode *list2) {
        ListNode dummy(-1);
        ListNode *ptr = &dummy;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = (list1 == NULL) ? list2 : list1;
        return dummy.next;
    }
};
```

### Take Care
when Input was `[4, 2]`, divide two array in `sortList` will loop

```c
ListNode *fastPtr = head;
ListNode *slowPtr = head;
```
so I change it to

```c
ListNode *fastPtr = head->next;
ListNode *slowPtr = head;
```
