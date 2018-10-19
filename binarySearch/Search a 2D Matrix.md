## Search a 2D Matrix
### Illustrate
<https://leetcode.com/problems/search-a-2d-matrix/submissions>

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.

### Example
```c
Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
```

### Code
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