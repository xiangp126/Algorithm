## Intersection of Two Linked Lists
### Illustrate
<https://leetcode.com/problems/intersection-of-two-linked-lists/>

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr = NULL;
        int lenA = 0, lenB = 0;
        int lenDiff = 0;

        // get the length of ListNode A
        ptr = headA;
        while (ptr != NULL) {
            ++lenA;
            ptr = ptr->next;
        }
        // get the length of ListNode B
        ptr = headB;
        while (ptr != NULL) {
            ++lenB;
            ptr = ptr->next;
        }

        if (lenA >= lenB) {
            lenDiff = lenA - lenB;
            while (lenDiff) {
                headA = headA->next;
                --lenDiff;
            }

            while (headA != NULL && headB != NULL) {
                if (headA == headB) {
                    return headA;
                }
                headA = headA->next;
                headB = headB->next;
            }
        } else {
            lenDiff = lenB - lenA;
            while (lenDiff) {
                headB = headB->next;
                --lenDiff;
            }

            while (headA != NULL && headB != NULL) {
                if (headA == headB) {
                    return headA;
                }
                headA = headA->next;
                headB = headB->next;
            }
        }

        return NULL;
    }
};
```
