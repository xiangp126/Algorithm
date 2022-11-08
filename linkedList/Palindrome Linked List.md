## Palindrome Linked List
### Illustrate
<https://leetcode.com/problems/palindrome-linked-list/>

Given the head of a singly linked list, return true if it is a
palindrome or false otherwise.

Follow up: Could you do it in `O(n)` time and `O(1)` space?

### Intuition
1. find the middle node and split the original linked list into two parts: the front part and the rear part.
2. reverse the rear part of the LinkedList.
3. check the nodes of the two sub-linked lists.
4. reverse the rear part of the LinkedList back.

### Code
O(n) time and O(1) space

```cpp
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
    bool isPalindrome(ListNode* head) {
        if (!head) return false;
        int size = 0;

        // the front part begins
        ListNode *frontNode = head;
        ListNode *midNode = head;
        // the rear part begins
        ListNode *rearNode = NULL;
        // keep rearNode to reverse the rear part of the linkedlist back.
        ListNode *rearNodeKeeper = NULL;

        // check whether the size of the linkedlist is odd or even.
        while (frontNode != NULL) {
            ++size;
            frontNode = frontNode->next;
        }
        frontNode = head;
        midNode = middle_node(head);

        // if the size of the linkedlist is odd
        if (size & 0x1) {
            rearNode = reverse_linkedlist(midNode->next);
        } else {
            rearNode = reverse_linkedlist(midNode);
        }
        rearNodeKeeper = rearNode;

        while (frontNode != midNode) {
            if (frontNode->val != rearNode->val) {
                // Don't miss it: Reverse the rear part of the linkedlist back.
                reverse_linkedlist(rearNodeKeeper);
                return false;
            }
            frontNode = frontNode->next;
            rearNode = rearNode->next;
        }
        // Reverse the rear part of the linkedlist back.
        reverse_linkedlist(rearNodeKeeper);
        return true;
    }

    ListNode *middle_node(ListNode *head) {
        if (!head) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverse_linkedlist(ListNode *head) {
        ListNode dummy(-1, NULL);
        ListNode *ptr = &dummy;
        ListNode *pTmp = head;
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

--
### Code
O(n) time and O(n) space

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
    bool isPalindrome(ListNode* head) {
        if (!head) return false;
        vector<int> array;
        ListNode *pNode = head;
        while (pNode != NULL) {
            array.push_back(pNode->val);
            pNode = pNode->next;
        }

        int front = 0;
        int rear = array.size() - 1;
        while (front < rear) {
            if (array[front] != array[rear]) {
                return false;
            }
            ++front;
            --rear;
        }
        return true;
    }
};
```
