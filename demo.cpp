#include <iostream>
#include "inc/mybasic.h"
#include "inc/mysort.h"

int main(int argc, char *argv[])
{
    vector<int> nums {13, 2, 7, 11, -8, 4, 9, 12, 6, 11};
    const int N = nums.size();
    cout << "Original Array: " << endl;

    printArray(nums);
    bubbleSort(nums);
    printArray(nums);

    return 0;
}
