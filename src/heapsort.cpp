#include "mybasic.h"
#include "mysort.h"

void makeHeap(vector<int> &);
void percolateDown(vector<int> &, int, int);

void heapSort(vector<int> &nums) {
    int N = nums.size();
    int rear = N - 1;
    // take use of 'max peak heap'
    makeHeap(nums);
    printArray(nums);
    return;
    for (int i = rear; i >= 1; --i) {
        swap(nums[0], nums[i]);
        percolateDown(nums, 0, i - 1);
    }
}

void makeHeap(vector<int> &nums) {
    // index 0 -> N - 1
    int N = nums.size();
    int rear = N - 1;
    // for (int i = rear / 2; i >= 0; --i) {
        // percolateDown(nums, i, rear);
    // }
    percolateDown(nums, (rear - 1) / 2, rear);
}

// format max peak heap
void percolateDown(vector<int> &nums, int front, int rear) {
    if (front > rear) {
        return;
    }
    int pIndex   = front;
    int sentinel = nums[pIndex];
    int childLIndex = pIndex * 2 + 1;
    int childRIndex = childLIndex + 1;
    int childIndex  = childLIndex;
    while (pIndex < rear && childLIndex <= rear) {
        childLIndex = pIndex * 2 + 1;
        childRIndex = childLIndex + 1;
        if (childRIndex <= rear && nums[childRIndex] > nums[childLIndex]) {
            childIndex = childRIndex;
        } else {
            childIndex = childLIndex;
        }
        if (sentinel < nums[childIndex]) {
            nums[pIndex] = nums[childIndex];
            pIndex = childIndex;
        } else {
            break;
        }
    }
    nums[pIndex] = sentinel;
}
