## Unique Paths
### Illustrate
<https://leetcode.com/problems/unique-paths/>

### Code
```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        // input ensure m && n
        // paths: unique paths reaching (i, j)
        int paths[m][n];
        memset(paths, 0, sizeof(paths));
        
        // fill in the first column
        for (int i = 0; i < m; ++i) {
            paths[i][0] = 1;
        }
        // fill in the first row
        for (int j = 1; j < n; ++j) {
            paths[0][j] = 1;
        }
        
        // handle main body
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
            }
        }
        return paths[m - 1][n - 1];
    }
};
```