#include "mybasic.h"

void printArray(vector<int> &nums) {
    for (auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

void printArray(int *nums, int N)
{
    for (int i = 0; i < N; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b) {
    std::swap(a, b);
    return;
    // fix bug: if a & b the same address => yields 0
    if (&a != &b) {
        a ^= b;
        b ^= a;
        a ^= b;
    } else {
        std::swap(a, b);
    }
}
