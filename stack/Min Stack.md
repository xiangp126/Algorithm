## Min Stack
### Illustrate
<https://leetcode.com/problems/min-stack/>

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

1. push(x) -- Push element x onto stack.
2. pop() -- Removes the element on top of the stack.
3. top() -- Get the top element.
4. getMin() -- Retrieve the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

### Code
```cpp
class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        stk.push(val);
        if (minStk.empty() || (val <= minStk.top())) {
            minStk.push(val);
        }
    }

    void pop() {
        if (!stk.empty()) {
            int val = stk.top();
            stk.pop();

            if (!minStk.empty() && (val == minStk.top())) {
                minStk.pop();
            }
        }
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }

private:
    stack<int> stk;
    stack<int> minStk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

This is the implementation of a stack data structure that also supports constant time retrieval of the minimum element in the stack, called `MinStack`. The stack itself is implemented using a `stack<int>` object, while the minimum element is maintained using an additional `stack<int>` called `minStk`.

The `push()` function simply pushes the given element onto the stack and, if `minStk` is empty or the new element is less than or equal to the current minimum, pushes the new element onto `minStk`.

The `pop()` function removes the top element from the stack, and if that element is equal to the top of `minStk`, also removes the top element from `minStk`.

The `top()` function returns the top element of the stack, and the `getMin()` function returns the top element of `minStk`, which is the current minimum element in the stack.

This implementation has a time complexity of O(1) for all operations, including `push()`, `pop()`, `top()`, and `getMin()`. The space complexity is O(n), where n is the number of elements stored in the stack.
