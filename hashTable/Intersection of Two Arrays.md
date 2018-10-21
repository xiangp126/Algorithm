## Intersection of Two Arrays
### Illustrate
<https://leetcode.com/problems/intersection-of-two-arrays>

Given two arrays, write a function to compute their intersection.

Note:

* Each element in the result must be unique.
* The result can be in any order.

### Example
```c
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
```

### Code - _HashSet_
```c
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashSet;
        unordered_set<int> outSet;
        vector<int> ret;
        // initial hashSet
        for (auto num : nums1) {
            hashSet.insert(num);
        }
        // traverse nums2
        for (auto num : nums2) {
            auto iter = hashSet.find(num);
            if (iter != hashSet.end()) {
                outSet.insert(*iter);
            }
        }
        // pour outSet into vector
        auto iter = outSet.begin();
        while (iter != outSet.end()) {
            ret.push_back(*iter);
            ++iter;
        }
        return ret;
    }
};
```

### Code - _HashSet / Simplify_
```c
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashSet(nums1.begin(), nums1.end());
        unordered_set<int> outSet;
        for (auto num : nums2) {
            auto iter = hashSet.find(num);
            if (iter != hashSet.end()) {
                outSet.insert(*iter);
            }
        }
        return vector<int>(outSet.begin(), outSet.end());
    }
};
```

### Code - _Sort && Binary Search_
```c
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        unordered_set<int> hashSet;
        const int N = nums1.size();
        int left = 0;
        int right = N - 1;
        int mid = 0;
        // traverse through nums2
        for (auto num : nums2) {
            while (left <= right) {
                mid = left + (right - left) / 2;
                if (nums1[mid] < num) {
                    left = mid + 1;
                } else {
                    if (nums1[mid] > num) {
                        right = mid - 1;
                    } else {
                        hashSet.insert(num);
                        break;
                    }
                }
            }
            left = 0;
            right = N - 1;
        }
        return vector<int>(hashSet.begin(), hashSet.end());
    }
};
```