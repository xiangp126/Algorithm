#include "sort.h"
#include "common.h"

static void
mergeTwoSortedArray(vector<int> &, vector<int> &, int, int);
static void
mSort(vector<int> &, vector<int> &, int, int);

void mergeSort(vector<int> &nums) {
    int N = nums.size();
    vector<int> mergeArray(N, 0);
    mSort(mergeArray, nums, 0, N - 1);
}

static void
mSort(vector<int> &mergeArray, vector<int> &nums, int left,
            int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    // [left, right] => [left, mid], [mid + 1, right]
    mSort(mergeArray, nums, left, mid);
    mSort(mergeArray, nums, mid + 1, right);
    // mid can be figured out from left/right
    mergeTwoSortedArray(mergeArray, nums, left, right);
}

static void
mergeTwoSortedArray(vector<int> &mergeArray, vector<int> &nums,
            int left, int right) {
    int mid = (left + right) / 2;
    int ia = left;
    int ib = mid + 1;
    int ic = left;
    while (ia <= mid && ib <= right) {
        mergeArray[ic++] = nums[ia] <= nums[ib] ? nums[ia++] : nums[ib++];
    }
    while (ia <= mid) {
        mergeArray[ic++] = nums[ia++];
    }
    while (ib <= right) {
        mergeArray[ic++] = nums[ib++];
    }
    // copy sorted array back
    ic = left;
    while (ic <= right) {
        nums[ic] = mergeArray[ic];
        ++ic;
    }
}
