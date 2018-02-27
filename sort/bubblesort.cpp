#include "mybasic.h"
#include "mysort.h"

void bubbleSort(vector<int> &nums) {
    int N = nums.size();
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] < nums[j]) {
                swap(nums[i], nums[j]);
            }
        }
    }
}
