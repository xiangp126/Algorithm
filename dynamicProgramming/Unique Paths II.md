## Unique Paths II
### Illustrate
<https://leetcode.com/problems/unique-paths-ii/>

### Input
```c
[[1,0,0,0,0,0],[0,1,0,1,0,0]]

m = 2, n = 2
```

### Output
```c
0
```

### Code
```c
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Input ensure m && n
        const int m = obstacleGrid.size();
        const int n = obstacleGrid[0].size();
        
        /* 
         * ensure all elements of paths was initialized to 0
         * sizeof(paths) = m * n * sizeof(int)
         */ 
        int paths[m][n] = {0};
        // cout << "sizeof(paths) = " << sizeof(paths) << endl;
        memset(paths, 0, sizeof(paths));
        
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0]) {
                break;
            }
            paths[i][0] = 1;
        }
        for (int j = 0; j < n; ++j) {
            if (obstacleGrid[0][j]) {
                break;
            }
            paths[0][j] = 1;
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j]) {
                    paths[i][j] = 0;
                } else {
                    paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
                }
            }
        }
        return paths[m - 1][n - 1];
    }
};
```