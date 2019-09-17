#include "common.h"
#include "sort.h"

/*
 * first race for position of nums[0] from range [1...N - 1]
 * then race for position of nums[1] from range [2...N - 1]
 */

void bubbleSort(vector<int> &nums) {
    int N = nums.size();
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (nums[j] < nums[i]) {
                swap(nums[i], nums[j]);
            }
        }
    }
}
