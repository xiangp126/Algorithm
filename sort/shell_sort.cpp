#include "sort.h"

void shellSort(vector<int> &nums) {
    int N = nums.size();
    int i, j;
    int step = N / 2.2;
    // step decrease to 1
    for (; step > 0; step /= 2) {
        for (i = step; i < N; ++i) {
            int sentinel = nums[i];
            for (j = i; j >= step; j -= step) {
                if (sentinel < nums[j - step]) {
                    nums[j] = nums[j - step];
                    continue;
                } else {
                    break;
                }
            }
            nums[j] = sentinel;
        }
    }
}
