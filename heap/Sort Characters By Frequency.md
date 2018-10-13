## Sort Characters By Frequency
### Illustrate
<https://leetcode.com/problems/sort-characters-by-frequency>

Given a string, sort it in decreasing order based on the frequency of characters.

### Example
```c
Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
```

### Code
```c
class Solution {
public:
    string frequencySort(string s) {
        string ret;
        unordered_map<char, int> hashMap;
        // pair(character, frequency)
        for (auto ch : s) {
            ++hashMap[ch];
        }
        
        // pair(frequency, character)
        priority_queue<pair<int, char> > que;
        for (auto pair : hashMap) {
            que.push(make_pair(pair.second, pair.first));
        }
        while (!que.empty()) {
            int freq = que.top().first;
            while (freq--) {
                ret.push_back(que.top().second);    
            }
            que.pop();
        }
        return ret;
    }
};
```