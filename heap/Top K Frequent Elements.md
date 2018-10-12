## Top K Frequent Elements
### Illustrate
<https://leetcode.com/problems/top-k-frequent-elements>

Given a non-empty array of integers, return the **k** most frequent elements.

Note:

- You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
- Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

### Example
```c
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Input: nums = [1], k = 1
Output: [1]
```

### Code
```c
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        priority_queue<pair<int, int> > que;
        // <integer, frequency>
        unordered_map<int, int> hashMap;
        for (auto num : nums) {
            ++hashMap[num];
        }
        
        for (auto &pair : hashMap) {
            que.push(make_pair(pair.second, pair.first));
        }
        
        // printPQ(que);
        while (k--) {
            ret.push_back(que.top().second);
            que.pop();
        }
        return ret;
    }
    
    void printPQ(priority_queue<pair<int, int> > &que) {
        while (!que.empty()) {
            auto pair = que.top();
            que.pop();
            cout << "(";
            cout << pair.first << ", " << pair.second;
            cout << ")";
        }
        cout << endl;
    }
};
```