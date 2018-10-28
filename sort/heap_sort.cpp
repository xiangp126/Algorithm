#include "common.h"
#include "sort.h"

void makeHeap(vector<int> &);
void heapAdjust(vector<int> &, int, int);

void heapSort(vector<int> &nums) {
    const int N = nums.size();
    if (N <= 1) {
        return;
    }
    // make Max-Heap, index starts from 0
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

/*
 * heapAdjust: adjust Heap, originally percolate down routine
 *             construct Max-Peak Heap here
 * @nums:  input array
 * @left:  start index of the array
 * @right: end index of the array, included
 * @return void
 */
void heapAdjust(vector<int> &nums, int left, int right) {
    // element count <= 1
    if (left >= right) {
        return;
    }
    int i = left;
    int child = 2 * i + 1;
    int sentinel = nums[i];
    // main loop
    while (i < right && child <= right) {
        // find out the bigger child
        if (child + 1 <= right && nums[child + 1] > nums[child]) {
            ++child;
        }
        // move bigger child to parent's position
        if (nums[child] > sentinel) {
            nums[i] = nums[child];
        } else {
            break;
        }
        // for next loop
        i = child;
        child = 2 * i + 1;
    }
    // insert into right position
    nums[i] = sentinel;
}
