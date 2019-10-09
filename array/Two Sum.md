## Two Sum
### Illustrate
<https://leetcode.com/problems/two-sum/>

Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

You may assume that each input would have **exactly one solution**, and you may not use the same element twice.

###Example
```c
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

### Code - _Hash Table_
_Time O(N), Space O(N)_

```c
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            hashMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            int gap = target - nums[i];
            // <key, value> => <nums[j], j>
            auto iter = hashMap.find(gap);
            if (iter != hashMap.end() && iter->second > i) {
                // exactly one solution
                return vector<int> {i, iter->second};
            }
        }
    }
};
```

### Code - _Sort_

_**Notice**, index was disordered after sorting_<br>
_Time O(N), Space O(N)_

```c
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        // copy whole array, sort from small to large
        // Time complexity Nlog(N)
        vector<int> array(nums);
        sort(array.begin(), array.end(), less<int>());

        const int N = array.size();
        int left = 0;
        int right = N - 1;
        while (left < right) {
            int sum = array[left] + array[right];
            if (sum < target) {
                ++left;
            } else {
                if (sum > target) {
                    --right;
                }
                else {
                    // got the exactly one solution
                    break;
                }
            }
        }

        // find out original index for array[left] && array[right]
        for (int i = 0; i < N; ++i) {
            if (nums[i] == array[left]) {
                left = i;
                break;
            }
        }
        for (int i = 0; i < N; ++i) {
            if (nums[i] == array[right] && i != left) {
                right = i;
                break;
            }
        }

        return vector<int> {left, right};
    }
};
```
