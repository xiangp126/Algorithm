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

### Contents
- [Concept - Compare Pair](#comparepair)
- [Code - Deep](#deep)
- [Code - Simplify](#simplify)

<a id=comparepair></a>
### Concept - _Compare Pair_
- implement `operator<` for this type `pair`

```c
bool operator<(const pair<int, int> &node1, const pair<int, int> &node2) {
    return node1.first < node2.first;
}
```
- implement class `Compare`, overload its call function `operator()`

> Template

```c
template <class T, class Container = vector<T>,
class Compare = less<typename Container::value_type> > class priority_queue;
```

```c
struct MyCompare {
    inline bool operator()(const pair<int, int> &node1, 
                           const pair<int, int> &node2) {
        return node1.first < node2.first;
    }  
};
```

**pair can be compared directly**, for there is global `operator<` function for its type

> compare their `first` element at first

```c
template<class _Ty1, class _Ty2>
inline bool operator<(const pair<_Ty1, _Ty2>& _Left,
                      const pair<_Ty1, _Ty2>& _Right) {
    // test if _Left < _Right for pairs
    return (_Left.first < _Right.first ||
                !(_Right.first < _Left.first) && _Left.second < _Right.second);
}
```

<a id=simplify></a>
### Code - Simplify
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

<a id=deep></a>
### Code - Deep

_Self-define class `Compare`, implementing its call function_

```c
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        // <integer, frequency>
        unordered_map<int, int> hashMap;
        for (auto num : nums) {
            ++hashMap[num];
        }
         
        // self-define class Compare
        struct MyCompare {
            inline bool operator()(const pair<int, int> &node1, 
                            const pair<int, int> &node2) {
                return node1.first < node2.first;
            }  
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, MyCompare> que;
        for (auto &pair : hashMap) {
            // pair(frequency, integer)
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

