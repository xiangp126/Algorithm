#include "sort.h"
#include "common.h"

void radixSort(vector<int> &nums) {
    // int N = nums.size();
    int minNum = 0, maxNum = 0;
    for (auto val: nums) {
        minNum = std::min(minNum, val);
        maxNum = std::max(maxNum, val);
    }
    int addOn = minNum < 0 ? abs(minNum) : 0;

    // all items added to be positive
    for (auto &val : nums) {
        val += addOn;
    }

    // find out max digits
    int maxDigits = 0;
    maxNum += addOn;
    while (maxNum) {
        ++maxDigits;
        maxNum /= 10;
    }
#if 0
    cout << "maxDigits = " << maxDigits << endl;
#endif
    vector<vector<int> > buckets(10, vector<int>());
    int divisor = 1;
    int bktIndex = 0;
    int k = 0;
    while (maxDigits--) {
        for (auto val : nums) {
            bktIndex = (val / divisor) % 10;
            buckets[bktIndex].push_back(val);
        }

        k = 0;
        for (int i = 0; i < 10; ++i) {
            for (auto val : buckets[i]) {
                nums[k++] = val;
            }
            // bug point: how to empty a vector?
            buckets[i].clear();
        }

        divisor *= 10;
    }

    for (auto &val : nums) {
        val -= addOn;
    }
}
