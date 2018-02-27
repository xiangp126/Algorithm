#include "mybasic.h"
#include "mysort.h"

void makeHeap(vector<int> &);
void percolateDown(vector<int> &, int, int);

void heapSort(vector<int> &nums) {
    int N = nums.size();
    int rear = N - 1;
    // take use of 'max peak heap'
    makeHeap(nums);
    for (int i = rear; i >= 1; --i) {
        swap(nums[0], nums[i]);
        percolateDown(nums, 0, i - 1);
    }
}

void makeHeap(vector<int> &nums) {
    // index 0 -> N - 1
    int N = nums.size();
    int rear = N - 1;
    for (int i = (rear - 1) / 2; i >= 0; --i) {
        percolateDown(nums, i, rear);
    }
}

// format max peak heap
void percolateDown(vector<int> &nums, int front, int rear) {
    if (front > rear) {
        return;
    }
    int pIndex = front;
    int childIndex = 0, childRIndex = 0;
    // bug point: pIndex * 2 + 1 must effect here
    while (pIndex < rear && pIndex * 2 + 1 <= rear) {
        childIndex  = pIndex * 2 + 1;
        childRIndex = childIndex + 1;
        if (childRIndex <= rear && nums[childIndex] < nums[childRIndex]) {
            ++childIndex;
        }
        if (nums[pIndex] < nums[childIndex]) {
            swap(nums[pIndex], nums[childIndex]);
            pIndex = childIndex;
        } else {
            break;
        }
    }
}
