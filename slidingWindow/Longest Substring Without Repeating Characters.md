## Longest Substring Without Repeating Characters
### Illustrate
<https://leetcode.com/problems/remove-duplicates-from-sorted-array>

Given a string s, find the length of the longest substring without repeating characters.

Refer [leetcode必备算法：聊聊滑动窗口](https://cloud.tencent.com/developer/article/1901001)

### Synopsis of erase function of unordered_set
```cpp
    iterator  erase(iterator position);
    iterator  erase(const_iterator position);
    size_type erase(const key_type& k);
```
### Code
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> windows;
        size_t maxLen = 0;
        size_t left = 0;
        size_t right = 0;
        while (right < s.size()) {
            // Check whether we need to shrink the window
            if (windows.count(s[right])) {
                while (windows.count(s[right])) {
                    // windows.erase(windows.find(s[left]));
                    windows.erase(s[left]);
                    ++left;
                }
            }

            // expand the window
            windows.insert(s[right]);
            ++right;
            // update maxLen
            maxLen = max(maxLen, windows.size());
        }
        return maxLen;
    }
};
```

### Why we use Set
Set provides an easy way to lookup.