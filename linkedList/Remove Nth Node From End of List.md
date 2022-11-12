## Remove Nth Node From End of List
### Illustrate
<https://leetcode.com/problems/remove-nth-node-from-end-of-list/>

### Code
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;
        ListNode *fastPtr = head;
        ListNode *slowPtr = head;
        ListNode *pNode = NULL;
        // move fastPtr forward by n steps
        while (n--) {
            if (!fastPtr) return NULL;
            fastPtr = fastPtr->next;
        }
        // move fastPtr to the last node, and at the same time, move slowPtr
        while (fastPtr && fastPtr->next) {
            fastPtr = fastPtr->next;
            slowPtr = slowPtr->next;
        }

        // if fastPtr == NULL, it means that the node that
        // slowPtr currently points to is the one that needs to be freed
        if (!fastPtr) {
            head = slowPtr->next;
            delete slowPtr;
        } else {
            pNode = slowPtr->next;
            slowPtr->next = pNode->next;
            delete pNode;
        }
        return head;
    }
};
```
