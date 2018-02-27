#include "mybasic.h"
#include "mysort.h"

void bucketSort(vector<int> &nums) {
    int maxNum = 0;
    int minNum = 0;
    int i, N = nums.size();
    // loop to find out the maximum and minimum
    for (i = 0; i < N; ++i) {
        maxNum = std::max(maxNum, nums[i]);
        minNum = std::min(minNum, nums[i]);
    }
    int plusOn = minNum < 0 ? abs(minNum) : 0;
    int bucketLen = maxNum + plusOn + 1;
    int buckets[bucketLen];
    // bug point: memset size
    memset(buckets, 0, bucketLen * sizeof(int));
    for (i = 0; i < N; ++i) {
        ++buckets[nums[i] + plusOn];
    }

    int k = 0, rptCnt = 0;
    for (i = 0; i < bucketLen; ++i) {
        if (buckets[i] == 0) {
            continue;
        }
        for (rptCnt = 0; rptCnt < buckets[i]; ++rptCnt) {
            nums[k++] = i - plusOn;
            // if (k >= N) {
            //     cout << "k = " << k << endl;
            // }
        }
    }
}
