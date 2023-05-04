## Find All Numbers Disappeared in an Array
### Illustrate
<https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array>

Given an array of integers where `1 ≤ a[i] ≤ n` (n = size of array), some elements appear twice and others appear once.

Find all the elements of **[1, n]** inclusive that do not appear in this array.

Could you do it without extra space and in **O(n)** runtime? You may assume the returned list does not count as extra space.

### Example
```
Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
```

### Code
```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        const int N = nums.size();
        vector<bool> bitMap(N + 1, false);
        for (auto num: nums) {
            bitMap[num] = true;
        }

        for (int i = 1; i <= N; ++i) {
            if (!bitMap[i]) {
                ret.push_back(i);
            }
        }
        return ret;
    }
};
```
The below algorithm works by iterating through the input vector "nums" and marking the indices corresponding to the values in the array as negative. Then, it iterates over the vector again and adds the indices of the positive values to the output vector, which are the missing numbers.

The time complexity of this algorithm is O(n), where n is the size of the input vector, since we are iterating over the vector twice. However, the space complexity is O(1), since we are modifying the input vector in place and only using a constant amount of additional space to store the output vector.

```c++
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        for (auto num : nums) {
            int index = abs(num) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};
```

This algorithm is also known as the "negation trick". It works by using the input array itself as a bit vector to mark which numbers have been seen. Since we only need to mark whether a number has been seen or not, we can use the sign of the element in the array to mark whether we have seen that number or not. By marking the corresponding index as negative, we can indicate that we have seen that number.

After iterating through the array and marking the corresponding indices, we iterate through the array again and look for indices with positive values. These indices represent the numbers that were not present in the input array. We add these numbers to the output vector and return it.

This algorithm is efficient in terms of space complexity, as it only requires O(1) additional space. However, it modifies the input array, which may not be desirable in all cases.