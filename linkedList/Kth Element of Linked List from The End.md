## 链表中倒数第k个结点
### Illustrate
<https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking>

输入一个链表，输出该链表中倒数第k个结点。

### Code - _Normal_

* if `k` larger than length of LinkedList, return `NULL`

```c
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL || k < 0) {
            return pListHead;
        }
        int len = 0;
        ListNode *ptr = pListHead;
        while (ptr != NULL) {
            ++len;
            ptr = ptr->next;
        }
        // handle main
        if (k > len) {
            return NULL;
        }
        int m = len - k;
        ptr = pListHead;
        while (m--) {
            ptr = ptr->next;
        }
        return ptr;
    }
};
```

### Code - _Fast and Slow Pointer_

```c
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (pListHead == NULL || k < 0) {
            return pListHead;
        }
        int len = 0;
        ListNode *ptr = pListHead;
        while (ptr != NULL) {
            ++len;
            ptr = ptr->next;
        }
        // handle main
        if (k > len) {
            return NULL;
        }
        ListNode *fast = pListHead;
        ListNode *slow = fast;
        // fast pointer moves k steps ahead
        while (k--) {
            fast = fast->next;
        }
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
```