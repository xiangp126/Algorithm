## Min Stack
### Illustrate
<https://leetcode.com/problems/min-stack/>

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

1. push(x) -- Push element x onto stack.
2. pop() -- Removes the element on top of the stack.
3. top() -- Get the top element.
4. getMin() -- Retrieve the minimum element in the stack.

### Concept
_Basic stack in additional with `getMin()`_

### Code
```c
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        stk.push(x);
        if (minStk.empty() || x <= minStk.top()) {
            minStk.push(x);
        }
    }

    void pop() {
        int topVal = stk.top();
        if (topVal == minStk.top()) {
            minStk.pop();
        }
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }

private:
    // traditional stack
    stack<int> stk;
    // additional stack for implementing 'min stack'
    stack<int> minStk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
```
