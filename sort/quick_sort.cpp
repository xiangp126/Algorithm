#include "common.h"
#include "sort.h"

static void qSort(vector<int> &, int, int);
static int partition(vector<int> &, int, int);

void quickSort(vector<int> &nums) {
    int N = nums.size();
    int left = 0;
    int right = N - 1;
    qSort(nums, left, right);
}

void qSort(vector<int> &nums, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(nums, left, right);
        qSort(nums, left, pivotIndex - 1);
        qSort(nums, pivotIndex + 1, right);
    }
}

int partition(vector<int> &nums, int left, int right) {
    // qsort ensure left < right @here
    int sentinel = nums[right];
    int i = left, k = i;
    while (k < right) {
        if (nums[k] <= sentinel) {
            swap(nums[i++], nums[k++]);
        } else {
            ++k;
        }
    }
    swap(nums[i], nums[right]);
    return i;
}
