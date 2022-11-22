## Minimum Window Substring
### Illustrate
<https://leetcode.com/problems/minimum-window-substring/>

Given two strings s and t of lengths m and n respectively, return the minimum window
substring
 of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

### Hint
1. Use two pointers to create a window of letters in s, which would have all the characters from t.
2. Expand the right pointer until all the characters of t are covered.
3. Once all the characters are covered, move the left pointer and ensure that all the characters are still covered to minimize the subarray size.
4. Continue expanding the right and left pointers until you reach the end of s.

[Good Tutorial on YouTube](https://www.youtube.com/watch?v=U1q16AFcjKs)<br>
[The Comment from kingsizebeast](https://leetcode.com/problems/minimum-window-substring/solutions/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems/)

### string::substr
```cpp
basic_string substr( size_type pos = 0, size_type count = npos ) const;
```

##### Parameters
1. pos	-	position of the first character to include
2. count	-	length of the substring

#### Return value
String containing the substring `[pos, pos+count)` or `[pos, size())`.

### Code
```c++
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        unordered_map<char, int> uMap;
        // Statistic for count of char in t.
        for (auto ch : t) {
            ++uMap[ch];
        }

        // counter represents the number of chars of t to be found in s.
        size_t counter = t.size();
        // Two pointers to expand or shrink the window.
        size_t left = 0, right = 0;
        // Record the start point of the candidate minimum window substring.
        size_t minStart = 0;
        size_t minLen = INT_MAX;
        // temporary length.
        size_t tmpLen = 0;

        /*
         * Input: s = "ADOBECODEBANC", t = "ABC"
         * Output: "BANC"
         * Explanation: The minimum window substring "BANC"
         * includes 'A', 'B', and 'C' from  string t.
         */
        // move forward to expand the window.
        while (right < s.size()) {
            if (uMap.find(s[right]) != uMap.end()) {
                if (uMap[s[right]] > 0) {
                    --counter;
                }
                --uMap[s[right]];
            }
            ++right;

            // Check whether we found a valid window.
            // If not, continue the loop.
            if (counter > 0) {
                continue;
            };

            // Found a valid window and check if we could shrink the window.
            while (counter == 0) {
                if (uMap.find(s[left]) != uMap.end()) {
                    ++uMap[s[left]];
                    if (uMap[s[left]] > 0) {
                        ++counter;
                    }
                }
                ++left;
            }

            tmpLen = right - left + 1;
            if (tmpLen < minLen) {
                minLen = tmpLen;
                minStart = left - 1;
            }
        }
        // basic_string substr( size_type pos = 0, size_type count = npos ) const;
        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};
```
