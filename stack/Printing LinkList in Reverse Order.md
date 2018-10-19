## 从尾到头打印链表
### Illustrate
<https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking>

输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

### Code
```c
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret;
        stack<ListNode *> stk;
        ListNode *ptr = NULL;
        while (head != NULL) {
            stk.push(head);
            head = head->next;
        }
        while (!stk.empty()) {
            ptr = stk.top();
            ret.push_back(ptr->val);
            stk.pop();
        }
        return ret;
    }
};
```