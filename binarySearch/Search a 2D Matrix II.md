## Search a 2D Matrix II
### Illustrate
<https://leetcode.com/problems/search-a-2d-matrix-ii>

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

* Integers in each row are sorted in ascending from left to right.
* Integers in each column are sorted in ascending from top to bottom.

### Example
```c
Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
```

### Code

_code was exactly same as **Search a 2D Matrix**_

```c
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int M = matrix.size();
        if (M == 0) {
            return false;
        }
        const int N = matrix[0].size();
        int row = 0;
        int col = N - 1;
        while (row >= 0 && row < M && col >= 0 && col < N) {
            if (matrix[row][col] < target) {
                ++row;
            } else {
                if (matrix[row][col] > target) {
                    --col;
                } else {
                    // found it
                    return true;
                }
            }
        }
        // not found
        return false; 
    }
};
```