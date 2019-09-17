#include "common.h"
#include "sort.h"

void makeHeap(vector<int> &);
void heapAdjust(vector<int> &, int, int);

void heapSort(vector<int> &nums) {
    const int N = nums.size();
    // make Max-Heap, index starts from 0
    for (int i = N / 2; i >= 0; --i) {
        heapAdjust(nums, i, N - 1);
    }

    // main sort routine
    for (int i = N - 1; i > 0; --i) {
        swap(nums[0], nums[i]);
        heapAdjust(nums, 0, i - 1);
    }
}

/*
 * heapAdjust: adjust Heap, originally Percolate Down Routine
 *             construct Max-Peak Heap here
 * @nums:  input array
 * @left:  start index of the array
 * @right: end index of the array, included
 * @return void
 */
void heapAdjust(vector<int> &nums, int left, int right) {
    int i = left, child;
    int sentinel = nums[i];
    while (i <= right && 2 * i + 1 <= right) {
        child = 2 * i + 1;
        // find out the bigger child
        if (child + 1 <= right && nums[child + 1] > nums[child]) {
            ++child;
        }
        if (nums[child] > sentinel) {
            // move bigger child to parent's position
            nums[i] = nums[child];
            // for next loop
            i = child;
        } else {
            break;
        }
    }
    // insert into the right position
    nums[i] = sentinel;
}
