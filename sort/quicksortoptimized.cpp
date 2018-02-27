#include <utility>
#include "mybasic.h"
#include "mysort.h"

using std::pair;
using std::make_pair;

static void qSort(vector<int> &, int, int);
static pair<int, int> partition(vector<int> &, int, int);

void quickSortOptimized(vector<int> &nums) {
    int N = nums.size();
    qSort(nums, 0, N - 1);
}

void qSort(vector<int> &nums, int left, int right) {
    if (left < right) {
        pair<int, int> pivotIndex = partition(nums, left, right);
        qSort(nums, left, pivotIndex.first - 1);
        qSort(nums, pivotIndex.second + 1, right);
    }
}

pair<int, int> partition(vector<int> &nums, int left, int right) {
    // qSort ensure left < right @here
    int sentinel = nums[right];
    int i = left, k = i;
    int rend = right;
    while (k < right) {
        if (nums[k] < sentinel) {
            swap(nums[i++], nums[k++]);
        } else {
            if (nums[k] == sentinel) {
                // bug point: nums[k], not k++
                swap(nums[k], nums[--right]);
            } else {
                ++k;
            }
        }
    }
    // move 'equal' iterms to 'middle'
    int equalCnt = rend - right + 1;
    int grCnt = right - left;
    int cnt = std::min(equalCnt, grCnt);
    for (int index = 0; index < cnt; ++index) {
        swap(nums[i + index], nums[rend - index]);
    }
    return make_pair( i,  i + equalCnt - 1);
}
