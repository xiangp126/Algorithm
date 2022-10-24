## Merge k Sorted Lists
### Illustrate
<https://leetcode.com/problems/merge-k-sorted-lists/description/>

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        return mergeSection(lists, 0, lists.size() - 1);
    }

private:
    ListNode *mergeSection(vector<ListNode *> &lists, int leftIndex, int rightIndex) {
        if (lists.size() == 0) return NULL;
        if (rightIndex <= leftIndex) {
            return lists[leftIndex];
        }

        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
        ListNode *leftSubLinkedList = mergeSection(lists, leftIndex, midIndex);
        ListNode *rightSubLinkedList = mergeSection(lists, midIndex + 1, rightIndex);
        return mergeTwoLists(leftSubLinkedList, rightSubLinkedList);
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *ptr = &dummy;
        while(l1 != NULL && l2 != NULL) {
            if(l1->val <= l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            }
            else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        ptr->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
```