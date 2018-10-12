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

### Code - _quick sort basic_
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
    
    void qSort(vector<int> &nums, int start, int end) {
        if (start >= end) {
            return;
        }
        int pIndex = partition(nums, start, end);
        qSort(nums, start, pIndex - 1);
        qSort(nums, pIndex + 1, end);
    }
    /*
     * partition: partition array range [start, end] into three parts
     *      [start, k - 1], k, [k + 1, end]
     * @nums: input array
     * @start: start index of array
     * @end: end index of array
     * @return final position of the pivot element
     */
    int partition(vector<int> &nums, int start, int end) {
        int pivot = nums[end];
        int i = start;
        int k = i;
        while (i < end) {
            if (nums[i] >= pivot) {
                swap(nums[k++], nums[i]);
            }
            ++i;
        }
        swap(nums[k], nums[end]);
        return k;
    }
};
```

### Code - _quick select basic_
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
    
    void qSelect(vector<int> &nums, int start, int end, int k) {
        if (start >= end) {
            return;
        }
        int pIndex = partition(nums, start, end);
        if (pIndex == k) {
            return;
        } else {
            if (pIndex > k) {
                qSelect(nums, start, pIndex - 1, k);
            } else {
                qSelect(nums, pIndex + 1, end, k);
            }
        }  
    }
    /*
     * partition: partition array range [start, end] into three parts
     *      [start, k - 1], k, [k + 1, end]
     * @nums: input array
     * @start: start index of array
     * @end: end index of array
     * @return final position of the pivot element
     */
    int partition(vector<int> &nums, int start, int end) {
        int pivot = nums[end];
        int i = start;
        int k = i;
        while (i < end) {
            if (nums[i] >= pivot) {
                swap(nums[k++], nums[i]);
            }
            ++i;
        }
        swap(nums[k], nums[end]);
        return k;
    }
};
```

### Code - _heap sort_
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
            // printArray(nums);
            swap(nums[0], nums[i]);
            // Heap length minus 1
            heapAdjust(nums, 0, i - 1);
        }
    }

    // heap percolate down, minHeap default, range [start, end]
    void heapAdjust(vector<int> &nums, int start, int end) {
        int i = start;
        int child = 2 * i + 1;
        int sentinel = nums[i];
        // main loop
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
    
    void printArray(vector<int> &nums) {
        for (auto num : nums) {
            cout << "[ " << num << " ";
        }
        cout << " ]" << endl;
    }
};
```