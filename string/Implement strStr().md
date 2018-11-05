## Implement strStr()
### Illustrate
<https://leetcode.com/problems/implement-strstr>

Return the index of the first occurrence of needle in haystack, or **-1** if needle is not part of haystack.

### example
```c
Input: haystack = "hello", needle = "ll"
Output: 2

Input: haystack = "aaaaa", needle = "bba"
Output: -1
```
### Code
```c
class Solution {
public:
    int strStr(string haystack, string needle) {
        int lenHaystack = haystack.size();
        int lenNeedle = needle.size();
        if (lenHaystack == 0 || lenNeedle == 0) {
            if (lenNeedle == 0) {
                return 0;
            }
            return -1;
        }
        // get Next array
        int next[lenNeedle];
        getNext(needle, next);
        int i = 0;
        int j = 0;
        // main loop
        //while (i < haystack.size() && j < needle.size()) {
        while (i < lenHaystack && j < lenNeedle) {
            cout << "i = " << i << endl;
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
                cout << "jump to j = " << j << endl;
            }
        }
        return (j == needle.size()) ? i - needle.size() : -1;
    }

    void getNext(string &str, int *next) {
        const int N = str.size();
        next[0] = -1;
        int k = -1;
        int i = 0;
        while (i < N - 1) {
            if (k == -1 || str[i] == str[k]) {
                next[++i] = ++k;
            } else {
                k = next[k];
            }
        }
    }
};
```

### Confusion
_change like this will no loop at all, why ?_

use `haystack.size()` directly, not `lenHaystack `

```c
while (i < haystack.size() && j < needle.size()) {
//while (i < lenHaystack && j < lenNeedle) {
```
