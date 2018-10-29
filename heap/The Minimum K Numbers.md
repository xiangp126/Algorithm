## 最小的K个数
### Illustrate
<https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking>

输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

### Code - _STL Heap_

_using STL `priority_queue` directly, make `Min-Heap`_

```c
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ret;
        const int N = input.size();
        if (k < 0 || k > N) {
            return ret;
        }
        // make Min-Heap using input
        priority_queue<int, vector<int>, greater<int> > que;
        for (auto val : input) {
            que.push(val);
        }
        // get the minimux K numbers
        for (int i = 0; i < k; ++i) {
            ret.push_back(que.top());
            que.pop();
        }

        return ret;
    }
};
```

### Code - _Self Heap_

_self designed heap_

```c
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ret;
        const int N = input.size();
        if (N < 0 || k > N || k < 0) {
            return ret;
        }
        // make Min-Heap
        for (int i = N / 2; i >= 0; --i) {
            heapAdjust(input, i, N - 1);
        }
        for (int i = N - 1; i > N - 1 - k; --i) {
            ret.push_back(input[0]);
            input[0] = input[i];
            heapAdjust(input, 0, i - 1);
        }
        return ret;
    }
    // Min-Heap
    void heapAdjust(vector<int> &nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int i = left;
        int child = 2 * i + 1;
        int sentinel = nums[i];
        // while (i < right && child <= child)
        while (child <= right) {
            if (child + 1 <= right && nums[child + 1] < nums[child]) {
                ++child;
            }
            if (nums[child] < sentinel) {
                nums[i] = nums[child];
            } else {
                break;
            }
            i = child;
            child = 2 * i + 1;
        }
        nums[i] = sentinel;
    }
};
```
