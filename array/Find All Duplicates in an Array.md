## Find All Duplicates in an Array
### Illustrate
<https://leetcode.com/problems/find-all-duplicates-in-an-array>

Given an array of integers, **1 ≤ a[i] ≤ n (n = size of array)**, some elements appear twice and others appear once.

Find all the elements that appear **twice** in this array.

Could you do it without extra space and in O(n) runtime?

### Example
```c
[4,3,2,7,8,2,3,1]

[2,3]
```

_Hint: we have the upper limit of the array_

### Code - _Basic using Bit Map with C++_

```c++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        const int N = nums.size();
        // C compile error: "Variable-sized object may not be initialized"
        bool bitMap[N + 1];
        memset(bitMap, false, (N + 1) * sizeof(bool));
        // or you can use
        // vector<bool> bitMap(N + 1, false);
        for (auto num : nums) {
            if (bitMap[num]) {
                ret.push_back(num);
            } else {
                bitMap[num] = true;
            }
        }
        return ret;
    }
};
```

### Code - _In-Place Sulotion with C++_
_in place, without extra space and in O(n) runtime_

**_preferred_**

```c++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        const int N = nums.size();
        for (int i = 0; i < N; ++i) {
            int realVal = abs(nums[i]);
            if (nums[realVal - 1] > 0) {
                nums[realVal - 1] = -nums[realVal - 1];
            } else {
                ret.push_back(realVal);
            }
        }
        return ret;
    }
};
```

_or_

```c++
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        const int N = nums.size();
        // mod should be chosen greater than N
        const int mod = N + 1;
        for (int i = 0; i < N; ++i) {
            int realVal = (nums[i] + mod) % mod;
            if (nums[realVal - 1] > 0) {
                nums[realVal - 1] -= mod;
            } else {
                ret.push_back(realVal);
            }
        }
        return ret;
    }
};
```

### Code - _In-Place Sulotion with Java_

```java
class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ret = new ArrayList<>();
        int realVal = 0;
        for (int i = 0; i < nums.length; ++i) {
            realVal = Math.abs(nums[i]);
            if (nums[realVal - 1] < 0) {
                ret.add(realVal);
            } else {
                nums[realVal - 1] = -nums[realVal - 1];
            }
        }
        return ret;
    }
}
```
