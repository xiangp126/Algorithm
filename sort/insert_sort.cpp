#include "sort.h"

void insertSort(vector<int> &nums) {
    int N = nums.size();
    int i, j;
    // just as fix 'step' to 1 of shellSort
    for (i = 1; i < N; ++i) {
        int sentinel = nums[i];
        for (j = i; j >= 1; --j) {
            if (sentinel < nums[j - 1]) {
                nums[j] = nums[j - 1];
                continue;
            } else {
                break;
            }
        }
        nums[j] = sentinel;
    }
}
