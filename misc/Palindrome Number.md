## Palindrome Number
### Illustrate
<https://leetcode.com/problems/palindrome-number/>

Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.

```
Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.
Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


Constraints:

-231 <= x <= 231 - 1
```

Follow up: Could you solve it without converting the integer to a string?

### Code - _with C++_
```c++
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        // 12321
        int divisor = 1;
        int y = x;
        while (y / 10) {
            y /= 10;
            divisor *= 10;
        }

        int left = 0, right = 0;
        while (x) {
            left = x / divisor;
            right = x % 10;
            if (left != right) {
                return false;
            }
            x = x % divisor / 10;
            divisor /= 100;
        }
        return true;
    }
};
```

### Code - _with Python)
```python
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x <= 0:
            return False
        y = x // 10
        # x: 12321 y 1232
        # divisor to count the digits of x
        divisor = 1
        while y:
            y = y // 10
            divisor = divisor * 10

        left = 0
        right = 0
        while x:
            left = x // divisor
            right = x % 10
            if left != right:
                return False
            x = x % divisor // 10
            divisor = divisor // 100
        return True
```
