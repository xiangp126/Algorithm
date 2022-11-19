## Longest Substring Without Repeating Characters
### Illustrate
<https://leetcode.com/problems/remove-duplicates-from-sorted-array>

Given a string s, find the length of the longest substring without repeating characters.

### Code
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> windows;
        unsigned long maxLen = 0;
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            // Check whether we need to shrink the window
            if (windows.count(s[right])) {
                while (windows.count(s[right])) {
                    windows.erase(windows.find(s[left]));
                    ++left;
                }
            }

            // expand the window
            windows.insert(s[right]);
            ++right;
            maxLen = max(maxLen, windows.size());
        }
        return maxLen;
    }
};
```
