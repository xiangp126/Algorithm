#include "sort.h"
#include "common.h"

void radixSort(vector<int> &nums) {
    // int N = nums.size();
    int minNum = 0, maxNum = 0;
    for (auto val: nums) {
        minNum = std::min(minNum, val);
        maxNum = std::max(maxNum, val);
    }
    int plusOn = minNum < 0 ? abs(minNum) : 0;

    // all items added to positive
    for (auto &val : nums) {
        val += plusOn;
    }
    // find loop count
    int maxNumPlus = maxNum + plusOn;
    int loopCnt = 0;
    while (maxNumPlus) {
        ++loopCnt;
        maxNumPlus /= 10;
    }
#if 0
    cout << "loopCnt = " << loopCnt << endl;
#endif
    vector<int> buckets[10];
    int divisor = 1;
    int bktIndex = 0;
    for (int i = 0; i < loopCnt; ++i) {
        for (auto val : nums) {
            bktIndex = (val / divisor) % 10;
            buckets[bktIndex].push_back(val);
        }
        // bug point: empty a vector
        nums.erase(nums.begin(), nums.end());
        for (int k = 0; k < 10; ++k) {
            for (auto val : buckets[k]) {
                nums.push_back(val);
            }
            buckets[k].erase(buckets[k].begin(), buckets[k].end());
        }
        divisor *= 10;
    }

    for (auto &val : nums) {
        val -= plusOn;
    }
}
