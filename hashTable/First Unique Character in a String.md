## First Unique Character in a String
### Illustrate
<https://leetcode.com/problems/first-unique-character-in-a-string/>

### Code - HashMap
```c++
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> uMap;
        for (auto ch : s) {
            ++uMap[ch];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (uMap[s[i]] <= 1) {
                return i;
            }
        }
        return -1;
    }
};
```

### Code - Int Map
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int uMap[256];
        memset(uMap, 0, 256 * sizeof(int));
        for (auto ch: s) {
            ++uMap[ch];
        }
        for (int i = 0; i < s.size(); ++i) {
            if (uMap[s[i]] <= 1) {
                return i;
            }
        }
        return -1;
    }
};
```