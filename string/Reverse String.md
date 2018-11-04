## Reverse String
### Illustrate
<https://leetcode.com/problems/reverse-string>

### Code
```c
class Solution {
public:
    string reverseString(string s) {
        const int N = s.size();
        int left = 0;
        int right = N - 1;
        while (left < right) {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
        return s;
    }
};
```