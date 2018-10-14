## Climbing Stairs
### Illustrate
<https://leetcode.com/problems/climbing-stairs>

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

### Code
```c
class Solution {
public:
    int climbStairs(int n) {
        int ways[n + 1];
        // note this
        ways[0] = 1;
        ways[1] = 1;
        for (int i = 2; i <= n; ++i) {
            ways[i] = ways[i - 1] + ways[i - 2];
        }
        return ways[n];
    }
};
```