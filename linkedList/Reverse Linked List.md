## Reverse Linked List
### Illustrate
<https://leetcode.com/problems/reverse-linked-list/>

    Reverse a singly linked list.

### Example
```c
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
```

### Code - Highly Recommended

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
        ListNode dummy(-1, NULL);
        ListNode *ptr = &dummy;
        ListNode *pTmp = NULL;

        while (head != NULL) {
            pTmp = head->next;
            head->next = ptr->next;
            ptr->next = head;

            head = pTmp;
        }

        return dummy.next;
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