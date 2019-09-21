#include <iostream>
#include <vector>

using namespace std;
void showVec(vector<int> &);
void swap(int &, int &);

void bubbleSort(vector<int> &);

void insertSort(vector<int> &);

void shellSort(vector<int> &);

void heapSort(vector<int> &);
void percolateDown(vector<int> &, int, int);

void mergeSort(vector<int> &);
void mSort(vector<int> &, vector<int> &, int, int);
void mergeTwoSortedArray(vector<int> &, vector<int> &, int, int);

void quickSort(vector<int> &);
void qSort(vector<int> &, int, int);
int partition(vector<int> &, int, int);

void quickSortOptimized(vector<int> &);
void qSortOptimized(vector<int> &, int, int);
pair<int, int> partitionOptimized(vector<int> &, int, int);

void countSort(vector<int> &nums);

void radixSort(vector<int> &nums);

int main(int argc, char *argv[])
{
    // array to be tested
    vector<int> nums = {6, 8, 15, 17, -6, 4, 99, 9, 5, 8,
        33, 45, 22, 11, -2, 19, 14};
    showVec(nums);

    // bubbleSort(nums);
    // insertSort(nums);
    // shellSort(nums);
    // heapSort(nums);
    // mergeSort(nums);
    // quickSort(nums);
    // quickSortOptimized(nums);
    // countSort(nums);
    radixSort(nums);

    showVec(nums);

    return 0;
}

void radixSort(vector<int> &nums) {
    const int N = nums.size();
    vector<vector<int> > buckets(10, vector<int>());

    int minVal = nums[0];
    int maxVal = nums[0];
    for (auto val : nums) {
        minVal = std::min(minVal, val);
        maxVal = std::max(maxVal, val);
    }

    int addOn = minVal < 0 ? -minVal : 0;

    int val = 0, k = 0;
    int divisor = 1;

    for (auto &val : nums) {
        val += addOn;
    }

    int maxDigits = 0;
    maxVal += addOn;
    while (maxVal) {
        maxVal /= 10;
        ++maxDigits;
    }

    while (maxDigits--) {
        for (auto val : nums) {
            buckets[(val / divisor) % 10].push_back(val);
        }

        k = 0;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < buckets[i].size(); ++j) {
                nums[k++] = buckets[i][j];
            }

            buckets[i].clear();
        }
        divisor *= 10;
    }

    for (auto &val : nums) {
        val -= addOn;
    }
}

void countSort(vector<int> &nums) {
    const int N = nums.size();
    int small = nums[0];
    int large = nums[0];
    for (auto val : nums) {
        if (val < small) {
            small = val;
        }
        if (val > large) {
            large = val;
        }
    }

    int inc = 0;
    if (small < 0) {
        inc = -small;
    }

    vector<int> buckets(large - small + 1, 0);
    for (auto val : nums) {
        ++buckets[val + inc];
    }

    int j = 0;
    int k = 0;
    int val = 0;
    for (int i = 0; i < large - small + 1; ++i) {
        val = buckets[i];
        if (val) {
            while (val--) {
                nums[j++] = i - inc;
            }
        }
    }

    if (j != N) {
        cout << "j(" << j << ") !=" << "k(" << k << ")" << endl;
    }
}

void quickSortOptimized(vector<int> &nums) {
    const int N = nums.size();
    qSortOptimized(nums, 0, N - 1);
}

void qSortOptimized(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    pair<int, int> indexPair = partitionOptimized(nums, left, right);
    qSortOptimized(nums, left, indexPair.first - 1);
    qSortOptimized(nums, indexPair.second + 1, right);
}

pair<int, int> partitionOptimized(vector<int> &nums, int left, int right) {
    int pivot = nums[right];
    int i = left;
    int k = i;
    int rear = right - 1;

    while (i <= rear) {
        if (nums[i] < pivot) {
            swap(nums[i++], nums[k++]);
        } else {
            if (nums[i] == pivot) {
                swap(nums[i], nums[rear--]);
                continue;
            } else {
                ++i;
            }
        }
    }
    int dupCnt = right - rear;
    int cnt = 0;
    while (cnt < dupCnt) {
        swap(nums[k + cnt], nums[rear + 1 + cnt]);
        ++cnt;
    }
    return pair<int, int>(k, k + dupCnt - 1);
}

void quickSort(vector<int> &nums) {
    const int N = nums.size();
    qSort(nums, 0, N - 1);
}

void qSort(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }

    int k = partition(nums, left, right);
    qSort(nums, left, k - 1);
    qSort(nums, k + 1, right);
}

int partition(vector<int> &nums, int left, int right) {
    int i = left;
    int k = i;
    int pivot = nums[right];
    while (i <= right - 1) {
        if (nums[i] <= pivot) {
            swap(nums[i++], nums[k++]);
        } else {
            ++i;
        }
    }
    swap(nums[k], nums[right]);
    return k;
}

void mergeSort(vector<int> &nums) {
    const int N = nums.size();
    vector<int> cell(N, 0);
    mSort(nums, cell, 0, N - 1);
}

void mSort(vector<int> &nums, vector<int> &cell, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mSort(nums, cell, left, mid);
    mSort(nums, cell, mid + 1, right);
    mergeTwoSortedArray(nums, cell, left, right);
}

void mergeTwoSortedArray(vector<int> &nums, vector<int> &cell, int left, int right) {
    int mid = left + (right - left) / 2;
    int ia = left;
    int ib = mid + 1;
    int ic = ia;

    while (ia <= mid && ib <= right) {
        cell[ic++] = nums[ia] <= nums[ib] ? nums[ia++] : nums[ib++];
    }

    while (ia <= mid) {
        cell[ic++] = nums[ia++];
    }
    while (ib <= right) {
        cell[ic++] = nums[ib++];
    }

    for (ic = left; ic <= right; ++ic) {
        nums[ic] = cell[ic];
    }
}

void heapSort(vector<int> &nums) {
    const int N = nums.size();
    for (int i = N / 2; i >= 0; --i) {
        percolateDown(nums, i, N - 1);
    }

    for (int i = N - 1; i > 0; --i) {
        swap(nums[0], nums[i]);
        percolateDown(nums, 0, i - 1);
    }
}

void percolateDown(vector<int> &nums, int start, int end) {
    int i = start, child;
    int sentinel = nums[i];
    while (i <= end && 2 * i + 1 <= end) {
        child = 2 * i + 1;
        if (child + 1 <= end && nums[child + 1] > nums[child]) {
            ++child;
        }
        if (nums[child] > sentinel) {
            nums[i] = nums[child];
            i = child;
        } else {
            break;
        }
    }
    nums[i] = sentinel;
}

void shellSort(vector<int> &nums) {
    const int N = nums.size();
    int sentinel, j;

    int step = N / 2.2;
    for (; step >= 1; step = step / 2) {
        for (int i = step; i < N; ++i) {
            sentinel = nums[i];
            for (j = i; j >= step; j = j - step) {
                if (sentinel < nums[j - step]) {
                    nums[j] = nums[j - step];
                } else {
                    break;
                }
            }
            nums[j] = sentinel;
        }
    }
}

void insertSort(vector<int> &nums) {
    const int N = nums.size();
    int sentinel, j;

    // fix 'step' to 1 of shellSort
    for (int i = 1; i < N; ++i) {
        sentinel = nums[i];
        for (j = i; j >= 0; --j) {
            if (sentinel < nums[j - 1]) {
                nums[j] = nums[j - 1];
            } else {
                break;
            }
        }
        nums[j] = sentinel;
    }
}

void bubbleSort(vector<int> &nums) {
    const int N = nums.size();
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (nums[j] < nums[i]) {
                swap(nums[i], nums[j]);
            }
        }
    }
}

void swap(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void showVec(vector<int> &nums) {
    for (auto num : nums){
        cout << num << " ";
    }
    cout << endl;
}
