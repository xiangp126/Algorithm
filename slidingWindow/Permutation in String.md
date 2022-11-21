## Permutation in String
### Illustrate
<https://leetcode.com/problems/permutation-in-string/description/>

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

### Code
```c++
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (!s1.size() || !s2.size() || s1.size() > s2.size()) {
            return false;
        }
        unordered_map<char, int> uMap;
        for (auto ch : s1) {
            ++uMap[ch];
        }

        size_t left = 0, right = 0;
        // counter represents the number of chars of s1 to be found in s2.
        size_t counter = s1.size();
        size_t winSize = counter;
        while (right < s2.size()) {
            if (uMap.find(s2[right]) != uMap.end()) {
                if (uMap[s2[right]] > 0) {
                    --counter;
                }
                --uMap[s2[right]];
            }
            ++right;

            // Check the size of the window.
            if (right == left + winSize) {
                if (counter == 0) {
                    return true;
                }
                if (uMap.find(s2[left]) != uMap.end()) {
                    ++uMap[s2[left]];
                    if (uMap[s2[left]] > 0) {
                        ++counter;
                    }
                }
                ++left;
            }
        }
        return false;
    }
};
```
