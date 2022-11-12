## Middle of the Linked List
### Illustrate
<https://leetcode.com/problems/middle-of-the-linked-list/>

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
    ListNode* middleNode(ListNode* head) {
        if (!head) return NULL;
        ListNode *fastPtr = head;
        ListNode *slowPtr = head;
        while (fastPtr && fastPtr->next) {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        return slowPtr;
    }
};
```
