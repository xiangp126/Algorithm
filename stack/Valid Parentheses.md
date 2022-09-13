## Valid Parentheses
### Illustrate
<https://leetcode.com/problems/valid-parentheses/>

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

### Example
```c
Input: "()"
Output: true

Input: "()[]{}"
Output: true

Input: "(]"
Output: false

Input: "([)]"
Output: false

Input: "{[]}"
Output: true
```

### Concept
**_std::string::find_**

Searches the string for the first occurrence of the sequence specified by its arguments.

When pos is specified, the search only includes characters at or after position pos, ignoring any possible occurrences that include characters before pos.

Notice that unlike member `find_first_of`, whenever more than one character is being searched for, it is not enough that just one of these characters match, but the entire sequence must match.

```c
str.find("a") != string.npos
```

### Code - Solution 1
- push the corresponding close bracket into the stack

```cpp
class Solution {
public:
    bool isValid(string s) {
        string openBrackets = "([{";
        string closeBrackets = ")]}";

        stack<char> stk;

        for(auto ch : s) {
            // 'ch' is an open bracket, then push the corresponding
            // close bracket into the stack
            if (openBrackets.find(ch) != string::npos) {
                stk.push(closeBrackets[openBrackets.find(ch)]);
            } else {
                // 'ch' is a close bracket, then compare it with the top element
                // in the stack
                if (!stk.empty() && ch == stk.top()) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
```

### Code - Solution 2
```cpp
class Solution {
public:
    bool isValid(string s) {
        string openBrackets("([{");
        string closeBrackets(")]}");
        stack<char> stk;
        for (auto ch : s) {
            if (stk.empty() || openBrackets.find(ch) != string::npos) {
                stk.push(ch);
            } else {
                if (stk.top() != openBrackets[closeBrackets.find(ch)]) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
```