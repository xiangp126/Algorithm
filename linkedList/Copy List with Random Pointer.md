## Copy List with Random Pointer
### Illustrate
<https://leetcode.com/problems/copy-list-with-random-pointer/>

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

### Code - _HashMap_
```c
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode dummy(-1);
        RandomListNode *list = &dummy;
        RandomListNode *curr = head;
        unordered_map<RandomListNode *, RandomListNode *> uMap;
        while (curr != NULL) {
            RandomListNode *pTmp = new RandomListNode(curr->label);
            list->next = pTmp;
            uMap[curr] = pTmp;
            // loop next
            curr = curr->next;
            list = list->next;
        }
        // list = NULL;
        // prepare for next loop
        curr = head;
        list = dummy.next;
        while (curr != NULL) {

            if (curr->random != NULL) {
                list->random = uMap[curr->random];
            }
            // loop next
            curr = curr->next;
            list = list->next;
        }
        return dummy.next;
    }
};
```

### Tips
_another solution for handling `curr->random == NULL`_

```c
uMap[NULL] = NULL;
```
