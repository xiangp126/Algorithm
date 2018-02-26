#include "mybasic.h"

void printArray(vector<int> &nums) {
    for (auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}
