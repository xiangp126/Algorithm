## Permutation in String
### Illustrate
<https://leetcode.com/problems/permutation-in-string/description/>

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

### Code - The Same Thoughts as `Minimum Window Substring`
1. move the right pointer forward to find a valid window.
2. move the left pointer forward to shrink the window size down to the maximum required window size, that is, `s1.size()`.
3. check if the window is still valid. If yes, return true. Otherwise, move the right pointer forward to continue this loop.

```cpp
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (!s1.size() || !s2.size()) return false;
        unordered_map<char, int> uMap;
        for (auto ch: s1) {
            ++uMap[ch];
        }

        size_t left = 0, right = 0;
        // counter represents the number of chars of s1 to be found in s2.
        size_t counter = s1.size();
        size_t winSize = s1.size();
        while (right < s2.size()) {
            if (uMap.find(s2[right]) != uMap.end()) {
                if (uMap[s2[right]] > 0) {
                    --counter;
                }
                --uMap[s2[right]];
            }
            ++right;

            if (counter != 0) {
                continue;
            }

            while (left + winSize < right) {
                if (uMap.find(s2[left]) != uMap.end()) {
                    ++uMap[s2[left]];
                    if (uMap[s2[left]] > 0) {
                        ++counter;
                    }
                }
                ++left;
            }

            if (counter == 0) return true;
        }
        return false;
    }
};
```

### Code - Thoughts 2
1. Continue to check the validity of the window with a fixed size.

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

#### Tip
Because the input will always be lowercase letters, we could use
char freq[26] in place of the hashmap.
