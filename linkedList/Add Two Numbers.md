## Add Two Numbers
### Illustrate
<https://leetcode.com/problems/add-two-numbers/>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(-1);
        ListNode *newList = &dummy;
        int val1 = 0;
        int val2 = 0;
        int sum = 0;
        int carry = 0;
        while (l1 || l2) {
            val1 = l1 ? l1->val : 0;
            val2 = l2 ? l2->val : 0;
            sum = val1 + val2 + carry;
            carry = sum / 10;
            newList->next = new ListNode(sum % 10);
            // for next loop
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
            newList = newList->next;
        }
        // process the last carry
        if (carry) {
            newList->next = new ListNode(carry);
        }
        return dummy.next;
    }
};
```
