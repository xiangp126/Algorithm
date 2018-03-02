#include <iostream>
#include <algorithm>
#include "mybasic.h"
#include "mysort.h"

using namespace std;

const char *sortTypeMsg[] = {
    " Bubble Sort ",
    " Insert Sort ",
    " Quick  Sort ",
    " Quick  Sort Optimized ",
    " Shell  Sort ",
    " Heap   Sort ",
    " Merge  Sort ",
    " Bucket Sort ",
    " Radix  Sort ",
    " Library Fun "
};
void usage();

int main(int argc, char *argv[])
{
    // vector<int> nums {13, 2, 7, 11, -8, 4, 9, 12, 6, 11, -4, 88, 11,
    //     44, -5, 12, 6, 12, 22, 74, 11};
    const int N = 20;
    vector<int> nums(N, 0);
    // default sort type selection is QUICKSORT
    int selected = QUICKSORT;

    while (1) {
        usage();
        randomArray(nums);
        repeatSymbol('-', 26);
        cout << " Original Array ";
        repeatSymbol('-', 26);
        cout << endl;
        printArray(nums);
        cout << "Input Here: ";
        cin >> selected;
        // Ctrl + D stands for EOF, end of file
        // cin.good() checking fix EOF issue for cin
        if (! cin.good()) {
            cout << endl;
            return 0;
        }
        switch (selected) {
            case 1:
                bubbleSort(nums);
                break;
            case 2:
                insertSort(nums);
                break;
            case 3:
                quickSort(nums);
                break;
            case 4:
                quickSortOptimized(nums);
                break;
            case 5:
                shellSort(nums);
                break;
            case 6:
                heapSort(nums);
                break;
            case 7:
                mergeSort(nums);
                break;
            case 8:
                bucketSort(nums);
                break;
            case 9:
                radixSort(nums);
                break;
            case 10:
                std::sort(nums.begin(), nums.end());
                break;
            default:
                return 0;
        }
        repeatSymbol('-', 26);
        cout << sortTypeMsg[selected - 1];
        repeatSymbol('-', 26);
        cout << endl;
        printArray(nums);
        cout << endl;
    }

    return 0;
}

void usage()
{
    cout << "||=>> Select Sort Algorithm @" << endl;
    cout <<
        "[1]: Bubble Sort       "
        "[2]: Insert Sort       "
        "[3]: Quick  Sort     \n"
        "[4]: Quick  Sort(Op)   "
        "[5]: Shell  Sort       "
        "[6]: Heap   Sort     \n"
        "[7]: Merge  Sort       "
        "[8]: Bucket Sort       "
        "[9]: Radix  Sort     \n"
        "[10]:Library Fun       "
        "[*]: Quit Selection  \n";
}
