#include "common.h"
#include "sort.h"

void makeHeap(vector<int> &);
void heapAdjust(vector<int> &, int, int);

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
    // inset right position
    nums[i] = sentinel;
}
