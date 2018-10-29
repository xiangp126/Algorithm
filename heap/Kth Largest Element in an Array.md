## Kth Largest Element in an Array
### Illustrate
<https://leetcode.com/problems/kth-largest-element-in-an-array>

Find the **kth** largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

### Example
```c
Input: [3,2,1,5,6,4] and k = 2
Output: 5

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Input: [3,1,2,4] and k = 2
Output: 3
```

### Contents
- Quck Sort Associate
    - [Code - quick sort with self-designed sort](#quicksortbasic)
    - [Code - quick select with self-designed sort](#quickselect)
- Heap Sort Associate
    - [Code - `STL` heap](#stlheap)
    - [Code - heap sort with self-designed heap](#heapsort)
    - [Code - heap select with self-designed heap](#heapselect)

<a id=quicksortbasic></a>
### Code - _Quick Sort (Basic)_
_full sort from Largest to Smallest_

```c
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums);
        return nums[k - 1];
    }

    void quickSort(vector<int> &nums) {
        return qSort(nums, 0, nums.size() - 1);
    }

    void qSort(vector<int> &nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int pIndex = partition(nums, left, right);
        qSort(nums, left, pIndex - 1);
        qSort(nums, pIndex + 1, right);
    }
    /*
     * partition: partition array range [left, right] into three parts
     *      [left, k - 1], k, [k + 1, right]
     * @nums:  input array
     * @left:  start index of array
     * @right: end index of array
     * @return final position of the pivot element
     */
    int partition(vector<int> &nums, int left, int right) {
        // choose last element as pivot
        int pivot = nums[right];
        int i = left;
        int k = i;
        while (i < right) {
            if (nums[i] >= pivot) {
                swap(nums[k++], nums[i]);
            }
            ++i;
        }
        swap(nums[k], nums[right]);
        return k;
    }
};
```

<a id=quickselect></a>
### Code - _Quick Select_
_from Largest to Smallest_

```c
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickSelect(nums, k - 1);
        return nums[k - 1];
    }

    void quickSelect(vector<int> &nums, int k) {
        return qSelect(nums, 0, nums.size() - 1, k);
    }

    void qSelect(vector<int> &nums, int left, int right, int k) {
        if (left >= right) {
            return;
        }
        int pIndex = partition(nums, left, right);
        if (pIndex == k) {
            return;
        } else {
            if (pIndex > k) {
                qSelect(nums, left, pIndex - 1, k);
            } else {
                qSelect(nums, pIndex + 1, right, k);
            }
        }
    }
    /*
     * partition: partition array range [left, right] into three parts
     *      [left, k - 1], k, [k + 1, right]
     * @nums:  input array
     * @left:  start index of array
     * @right: end index of array
     * @return final position of the pivot element
     */
    int partition(vector<int> &nums, int left, int right) {
        // choose last element as pivot
        int pivot = nums[right];
        int i = left;
        int k = i;
        while (i < right) {
            if (nums[i] >= pivot) {
                swap(nums[k++], nums[i]);
            }
            ++i;
        }
        swap(nums[k], nums[right]);
        return k;
    }
};
```

<a id=stlheap></a>
### Code - _STL Heap_
```c
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // make Max-Heap
        priority_queue<int, vector<int>, less<int> > que;
        for (auto val : nums) {
            que.push(val);
        }
        // loop (k - 1) times
        while (--k) {
            que.pop();
        }
        return que.top();
    }
};
```

<a id=heapsort></a>
### Code - _Heap Sort_
_full sort from Largest to Smallest_

```c
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        heapSort(nums);
        return nums[k - 1];
    }

    void heapSort(vector<int> &nums) {
        // make Heap
        const int N = nums.size();
        // index starts from 0
        for (int i = (N - 1) / 2; i >= 0; --i) {
            heapAdjust(nums, i, N - 1);
        }
        // sort main body
        for (int i = N - 1; i > 0; --i) {
            swap(nums[0], nums[i]);
            // Heap length minus 1
            heapAdjust(nums, 0, i - 1);
        }
    }

    /*
     * heapAdjust: adjust Heap, originally percolate down routine
     *             construct Min-Peak Heap here
     * @nums:  input array
     * @start: start index of the array
     * @end:   end index of the array, included
     * @return void
     */
    void heapAdjust(vector<int> &nums, int start, int end) {
        int i = start;
        int child = 2 * i + 1;
        int sentinel = nums[i];
        // main loop, judge can be changed to only
        // while (child <= end) {}
        while (i < end && child <= end) {
            // find out smallest child
            if (child + 1 <= end && nums[child + 1] < nums[child]) {
                ++child;
            }
            // move smaller child to root
            if (nums[child] < sentinel) {
                nums[i] = nums[child];
            } else {
                break;
            }
            // for next loop
            i = child;
            child = 2 * i + 1;
        }
        // inset into right position
        nums[i] = sentinel;
    }
};
```

<a id=heapselect></a>
### Code - _Heap Select_
_from smallest to Largest_

```c
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return heapSort(nums, k);
    }

    int heapSort(vector<int> &nums, int k) {
        // make Heap
        const int N = nums.size();
        // index starts from 0
        for (int i = (N - 1) / 2; i >= 0; --i) {
            heapAdjust(nums, i, N - 1);
        }
        // sort main body
        for (int i = N - 1; i >= N - k; --i) {
            swap(nums[0], nums[i]);
            // Heap length minus 1
            heapAdjust(nums, 0, i - 1);
        }
        return nums[N - k];
    }

    /*
     * heapAdjust: adjust Heap, originally percolate down routine
     *             construct Max-Peak Heap here
     * @nums:  input array
     * @start: start index of the array
     * @end:   end index of the array, included
     * @return void
     */
    void heapAdjust(vector<int> &nums, int start, int end) {
        int i = start;
        int child = 2 * i + 1;
        int sentinel = nums[i];
        // main loop
        while (i < end && child <= end) {
            // find out smallest child
            if (child + 1 <= end && nums[child + 1] > nums[child]) {
                ++child;
            }
            // move smaller child to root
            if (nums[child] > sentinel) {
                nums[i] = nums[child];
            } else {
                break;
            }
            // for next loop
            i = child;
            child = 2 * i + 1;
        }
        // inset into right position
        nums[i] = sentinel;
    }
};
```
