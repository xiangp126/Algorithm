## Maximal Square
### Illustrate
<https://leetcode.com/problems/maximal-square/>

```
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
```

### Code
```c
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int M = matrix.size();
        if (M == 0) {
            return 0;
        }
        const int N = matrix[0].size();
        /*
         * dp: Edge Length of max square whose lower right cornor is (i, j)
         */
        vector<vector<int> > dp(M, vector<int>(N, 0));
        int maxEdge = 0;
        // fill in the first column
        for (int i = 0; i < M; ++i) {
            // dp[i][0] = matrix[i][0] - '0';
            if (matrix[i][0] - '0') {
                dp[i][0] = 1;
                maxEdge = 1;
            }
        }
        // fill in the first row
        for (int j = 0; j < N; ++j) {
            // dp[0][j] = matrix[0][j] - '0';
            if (matrix[0][j] - '0') {
                dp[0][j] = 1;
                maxEdge = 1;
            }
        }
        // handle body
        for (int i = 1; i < M; ++i) {
            for (int j = 1; j < N; ++j) {
                // Element was '1'
                if (matrix[i][j] - '0') {
                    // find out the max Edge Length of square around (i, j)
                    int minVal = min(min(dp[i - 1][j - 1], dp[i - 1][j]),
                                     dp[i][j - 1]);
                    dp[i][j] = minVal + 1;
                    maxEdge = max(maxEdge, dp[i][j]);
                } else {
                    // Element was '0'
                    // below can be commented out for dp was initialized 0
                    dp[i][j] = 0;
                }
            }
        }
        // return it's area
        return maxEdge * maxEdge;
    }
};
```
