## Full Permutation of String
- NowCoder - **May Have Duplicates**

### Illustrate
<https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking>

Input a string, print **all** its permutations in **alphabet order**

Note:

The input string only contains upper and lower cases of characters and the whole length may not longer than 9(may has character duplicates).

### Example
```c
Input: abc
Output: abc,acb,bac,bca,cab,cba

Input: aaa
Output: aaa
```

### Code

> if not know removing duplicates, try Input `aaa`

_use `set` to remove duplicates and sort the remainings_
<div align=left><img src="./res/permu_set.jpg" width=650></div>

```c
class Solution {
public:
    vector<string> Permutation(string str) {
        set<string> bottle;
        if (str.size() == 0) {
            return vector<string>();
        }
        // start = 0
        dfs(str, 0, bottle);
        return vector<string>(bottle.begin(), bottle.end());
    }

    /*
     * dfs
     * @str: input string
     * @start: start index of str
     * @bottle: the set to store targeted string
     * @return void
     */
    void dfs(string str, int start, set<string> &bottle) {
        if (start == str.size()) {
            bottle.insert(str);
            return;
        }
        // handle main
        for (int i = start; i < str.size(); ++i) {
            swap(str[start], str[i]);
            dfs(str, start + 1, bottle);
            // swap back for next new swap
            swap(str[start], str[i]);
        }
    }
};
```

---

- LeetCode - **Have No Duplicates**

<https://leetcode.com/problems/permutations/>

Given a collection of **distinct** integers, return all possible permutations.

### Example
```c
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

### Code
```c++
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        dfs(nums, 0, ret);
        return ret;
    }

    void dfs(vector<int> nums, int start, vector<vector<int> > &ret) {
        if (start == nums.size()) {
            ret.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            swap(nums[i], nums[start]);
            dfs(nums, start + 1, ret);
            swap(nums[i], nums[start]);
        }
    }
};
```
