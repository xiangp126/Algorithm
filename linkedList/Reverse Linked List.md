## Reverse Linked List
### Illustrate
<https://leetcode.com/problems/reverse-linked-list/>

    Reverse a singly linked list.

### Example
```c
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
```

### Code - C++ #1 Recommended

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
    ListNode* reverseList(ListNode* head) {
        /*
         * Initial a new NULL list, and insert every node of List head
         * into it using 'head insert' method.
         * /
        ListNode dummy(-1);
        ListNode *ptr = head, *pTmp = NULL;
        while (ptr != NULL) {
            pTmp = ptr->next;
            ptr->next = dummy.next;
            dummy.next = ptr;
            ptr = pTmp;
        }
        return dummy.next;
    }
};
```

### Code - C++ #2
```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return NULL;

        ListNode dummy;
        ListNode *ptr = &dummy;
        ptr->next = head;

        ListNode *pTmp = NULL;
        ListNode *pre = head, *curr = head->next;
        while (curr) {
            pTmp = ptr->next;

            ptr->next = curr;
            pre->next = curr->next;
            curr->next = pTmp;

            curr = pre->next;
        }
        return ptr->next;
    }
};
```

### Code - Java

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode dummy = new ListNode(-1);
        ListNode ptr = head;
        ListNode pTmp = null;
        while (ptr != null) {
            pTmp = ptr.next;
            ptr.next = dummy.next;
            dummy.next = ptr;
            ptr = pTmp;
        }
        return dummy.next;
    }
}
```