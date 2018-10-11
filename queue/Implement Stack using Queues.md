## Implement Stack using Queues
### Illustrate
<https://leetcode.com/problems/implement-stack-using-queues/>

Implement the following operations of a stack using queues.

- push(x) -- Push element x onto stack.
- pop() -- Removes the element on top of the stack.
- top() -- Get the top element.
- empty() -- Return whether the stack is empty.

Notes:

- You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
- Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
- You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

### _std::queue_
- back
- empty
- front
- pop
- push
- size

### Example
```c
MyStack stack = new MyStack();

stack.push(1);
stack.push(2);
stack.top();   // returns 2
stack.pop();   // returns 2
stack.empty(); // returns false
```

### Code
```c
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        if (!que1.empty()) {
            que1.push(x);
        } else {
            que2.push(x);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = 0;
        if (!que1.empty()) {
            while (que1.size() > 1) {
                que2.push(que1.front());
                que1.pop();
            }
            val = que1.front();
            que1.pop();
        } else {
            while (que2.size() > 1) {
                que1.push(que2.front());
                que2.pop();
            }
            val = que2.front();
            que2.pop();
        }
        return val;
    }

    /** Get the top element. */
    int top() {
        int val = 0;
        if (!que1.empty()) {
            while (que1.size() > 1) {
                que2.push(que1.front());
                que1.pop();
            }
            val = que1.front();
            que2.push(val);
            que1.pop();
        } else {
            while (que2.size() > 1) {
                que1.push(que2.front());
                que2.pop();
            }
            val = que2.front();
            que1.push(val);
            que2.pop();
        }
        return val;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que1.empty() && que2.empty();
    }

private:
    // two queues were equal, used for pouring back and forth
    queue<int> que1;
    queue<int> que2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
```
