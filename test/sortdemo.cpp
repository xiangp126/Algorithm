#include <iostream>
#include "mybasic.h"
#include "mysort.h"

int main(int argc, char *argv[])
{
    // vector<int> nums {13, 2, 7, 11, -8, 4, 7, 12, 6};
    vector<int> nums {13, 2, 7, 11, -8, 4, 9, 12, 6, 11, -4, 88, 11,
        44, -5, 12, 6, 12, 22, 74, 11};
    const int N = nums.size();
    cout << "Original Array: " << endl;
    printArray(nums);

    int select = 9;
    switch (select) {
        case 1:
            bubbleSort(nums);
            break;
        case 2:
            insertSort(nums);
            break;
        case 3:
            shellSort(nums);
            break;
        case 4:
            quickSort(nums);
            break;
        case 5:
            quickSortOptimized(nums);
        case 6:
            heapSort(nums);
        case 7:
            bucketSort(nums);
        case 8:
            radixSort(nums);
        case 9:
            mergeSort(nums);
        default:
            break;
    }

    cout << "After Sorted: " << endl;
    printArray(nums);

    return 0;
}
