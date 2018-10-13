## Top K Frequent Words
### Illustrate
<https://leetcode.com/problems/top-k-frequent-words/description/>

Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Note:

- You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
- Input words contain only lowercase letters.

### Example
```c
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
    
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
```

### Code
```c
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ret;
        unordered_map<string, int> hashMap;
        // word => frequency
        for (auto word : words) {
            ++hashMap[word];
        }
        
        /*
         * MyCompare: 
         * self-define Compare class, overload its call function
         * must use struct here, not class. for it was in class 'Solution'
         * pair(frequency, word)
         */
        struct MyCompare {
            inline bool operator()(const pair<int, string> &node1,
                                    const pair<int, string> &node2) {
                if (node1.first == node2.first) {
                    return node1.second.compare(node2.second) > 0;
                }
                return node1.first < node2.first;
            }   
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string> >, MyCompare> que;
        for (auto pair : hashMap) {
            que.push(make_pair(pair.second, pair.first));
        }
        
        while (k--) {
            ret.push_back(que.top().second);
            que.pop();
        }
        return ret;
    }
};
```