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

int main(int argc, char *argv[])
{
    // array to be tested
    vector<int> nums = {6, 8, 15, 17, 4, 99, 9, 5, 8,
        33, 45, 22, 11, 19, 14};
    showVec(nums);

    // bubbleSort(nums);
    // insertSort(nums);
    // shellSort(nums);
    // heapSort(nums);
    mergeSort(nums);

    showVec(nums);

    return 0;
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
