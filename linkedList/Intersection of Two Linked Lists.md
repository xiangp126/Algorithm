## Intersection of Two Linked Lists
### Illustrate
<https://leetcode.com/problems/intersection-of-two-linked-lists/>

### Code - Original
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

### Code - Optimized
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
        ListNode *p1 = headA;
        ListNode *p2 = headB;

        int lengthA = 0, lengthB = 0;
        while (p1 != NULL) {
            ++lengthA;
            p1 = p1->next;
        }
        while (p2 != NULL) {
            ++lengthB;
            p2 = p2->next;
        }

        p1 = headA;
        p2 = headB;
        int step = abs(lengthA - lengthB);
        if (lengthA >= lengthB) {
            while (step) {
                p1 = p1->next;
                --step;
            }
        } else {
            while (step) {
                p2 = p2->next;
                --step;
            }
        }
        // either situation will use the same loop here
        while (p1 != NULL && p2 != NULL) {
            if (p1 == p2) {
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        return NULL;
    }
};
```