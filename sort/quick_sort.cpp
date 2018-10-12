#include "common.h"
#include "sort.h"

static void qSort(vector<int> &, int, int);
static int partition(vector<int> &, int, int);

void quickSort(vector<int> &nums) {
    qSort(nums, 0, nums.size() - 1);
}

void qSort(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivotIndex = partition(nums, left, right);
    qSort(nums, left, pivotIndex - 1);
    qSort(nums, pivotIndex + 1, right);
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
    // qsort ensure left < right @here
    int pivot = nums[right];
    int i = left;
    int k = i;
    while (i < right) {
        if (nums[i] <= pivot) {
            swap(nums[k++], nums[i]);
        }
        ++i;
    }
    swap(nums[k], nums[right]);
    return k;
}
