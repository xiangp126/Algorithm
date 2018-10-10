## Network Delay Time
### Illustrate
<https://leetcode.com/problems/network-delay-time/>

<https://blog.csdn.net/Jack_CJZ/article/details/78883157>

```
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Note:
N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
```

### Input
```c
[[2,1,1],[2,3,1],[3,4,1]]
4
2

[[1,2,1],[2,3,2]]
3
1
```

### Output
```c
2
3
```

### Code
```c
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
#define MAX_VAL 6001
        /*
         * @graph: record the path length from i --> j
         *         dimension N + 1 * N + 1. default MAX_VAL
         * @cost:  record the 'shortest' path length from K --> i
         *         dimemsion N + 1 * 1. default MAX_VAL
         * @visited: mark if Node i was visited, dimemsion N + 1 * 1
         *         default false
         */
        vector<vector<int> > graph(N + 1, vector<int>(N + 1, MAX_VAL));
        vector<int>  cost(N + 1, MAX_VAL);
        vector<bool> visited(N + 1, false);

        /*
         * create graph array，Node index from 1 ... N
         * graph[i][j] of means the path length directly from i --> j
         */
        for (int i = 0; i < times.size(); ++i) {
            graph[times[i][0]][times[i][1]] = times[i][2];
        }

        /*
         * Initialize 'cost' array
         * cost[i]: path length directly from K --> i
         */
        for (int i = 1; i <= N; ++i) {
            cost[i] = graph[K][i];
        }
        cost[K] = 0;
        visited[K] = true;

        for (int i = 1; i <= N; ++i) {
            int midNode = findShortestNode(cost, visited);
            // if no effective shortest path found
            if (midNode == -1) {
                break;
            }
            for (int j = 1; j <= N; ++j) {
                /*
                 * Breadth-First-Search relaxation path
                 * check path length between directly K --> j
                 *                     and indirectly K --> midNode --> j
                 * cost[j]: path length from K --> j
                 * graph[midNode][j]: path length from midNode --> j
                 */
                if (!visited[j] && (cost[midNode] + graph[midNode][j] < cost[j])) {
                    cost[j] = cost[midNode] + graph[midNode][j];
                }
            }
            // mark this Node as visited
            visited[midNode] = true;
        }

        // final handle function
        return handleFunc(cost);
    }

    /*
     * findShortestNode: find the shortest node among 'unvisited node set'
     *                   according to 'cost' array
     * @cost: 'cost' array of path K --> i
     * @visited: set of un-visited node
     * @return -1 if not found
     */
    int findShortestNode(vector<int> &cost, vector<bool> &visited) {
        // the shortest path node, can be 0 for Node index starts from 1
        int sNode = -1;
        int minV  = MAX_VAL;
        for (int i = 1; i < cost.size(); ++i) {
            if (!visited[i] && (cost[i] < minV)) {
                minV = cost[i];
                sNode = i;
            }
        }
        return sNode;
    }

    /* handleFunc: validate and find the maximum Delay Time
     * @cost: 'cost' array of path K --> i
     * @return -1 if no effective value found
     */
    int handleFunc(vector<int> &cost) {
        int maxDelay = 0;
        // index of 'cost'(represents Node) starts from 1
        for (int i = 1; i < cost.size(); ++i) {
            // cout << "cost[" << i << "] = " << cost[i] << endl;
            if (cost[i] == MAX_VAL) {
                return -1;
            }
            if (maxDelay < cost[i]) {
                maxDelay = cost[i];
            }
        }
        return maxDelay;
    }
};
```
