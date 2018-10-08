## Network Delay Time
<https://leetcode.com/problems/network-delay-time/>

<https://blog.csdn.net/Jack_CJZ/article/details/78883157>

### Input
```
[[2,1,1],[2,3,1],[3,4,1]]
4
2
```

### Code
```c
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<int> > graph(N + 1, vector<int>(N + 1, 60001));
        vector<int> cost(N + 1);
        vector<bool> visited(N + 1, false); 

        for (int i = 0; i < times.size(); ++i) {
            graph[times[i][0]][times[i][1]] = times[i][2];
        }
        for (int i = 1; i <= N; ++i) {
            cost[i] = graph[K][i];
        }
        cost[K] = 0;
        visited[K] = true;

        for (int i = 1; i <= N; ++i) {
            int minNode = findMinNode(cost, visited);
            if (minNode == 0) { break; }
            for (int j = 1; j <= N; ++j) {
                if (!visited[j] && cost[j] > cost[minNode] + graph[minNode][j]) {
                    cost[j] = cost[minNode] + graph[minNode][j];
                }
            }
            visited[minNode] = true;
        }

        return calSum(cost);
    }

    int findMinNode(vector<int>& cost, vector<bool>& visited) {
        int minIndex = 0, minV = 60001;
        for (int i = 1; i < cost.size(); ++i) {
            if (!visited[i] && minV > cost[i]) { 
                minIndex = i; 
                minV = cost[i];
            }
        }
        return minIndex;
    }

    int calSum(vector<int>& cost) {
        int sum = 0;
        for (int i = 1; i < cost.size(); ++i) {
            if (cost[i] == 60001) {
                return -1;
            }
            if (sum < cost[i]) {
                sum = cost[i];
            }
        }
        return sum;
    }
};
```
