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

void randomArray(int *nums, int N) {
    srand(unsigned(time(0)));
    int dir = -1;
    for (int i = 0; i < N; ++i) {
        dir = rand() % 2 ? 1 : -1;
        nums[i] = dir * (rand() % 100);
    }
}

void randomArray(vector<int> &nums) {
    srand(unsigned(time(0)));
    int dir = -1;
    int N = nums.size();
    for (int i = 0; i < N; ++i) {
        dir = rand() % 2 ? 1 : -1;
        nums[i] = dir * (rand() % 100);
    }
}

void repeatSymbol(char ch, int rpt)
{
    for (int i = 0; i < rpt; ++i) {
        cout << ch;
    }
}
