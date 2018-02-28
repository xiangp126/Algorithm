#include <iostream>
#include <algorithm>
#include "mybasic.h"
#include "mysort.h"

using namespace std;

void usage();
void repeatSymbol(char, int);

int main(int argc, char *argv[])
{
    // vector<int> nums {13, 2, 7, 11, -8, 4, 9, 12, 6, 11, -4, 88, 11,
    //     44, -5, 12, 6, 12, 22, 74, 11};
    const int N = 20;
    vector<int> nums(N, 0);
    int selected;

    while (1) {
        usage();

        randomArray(nums);
        repeatSymbol('-', 26);
        cout << " Original Array ";
        repeatSymbol('-', 26);
        cout << endl;
        printArray(nums);
        cout << "Input Here: ";

        // 19 80 35 87 -67 71 28 -34 -61 16 72 -76 -59 26 -33 -71 -9 88 -97 55
        cin >> selected;
        repeatSymbol('-', 26);
        switch (selected) {
            case 1:
                cout << " Bubble Sort ";
                bubbleSort(nums);
                break;
            case 2:
                cout << " Insert Sort ";
                insertSort(nums);
                break;
            case 3:
                cout << " Quick Sort ";
                quickSort(nums);
                break;
            case 4:
                cout << " Quick Sort Optimized ";
                quickSortOptimized(nums);
                break;
            case 5:
                cout << " Shell Sort ";
                shellSort(nums);
                break;
            case 6:
                cout << " Heap Sort ";
                heapSort(nums);
                break;
            case 7:
                cout << " Merge Sort ";
                mergeSort(nums);
                break;
            case 8:
                cout << " Bucket Sort ";
                bucketSort(nums);
                break;
            case 9:
                cout << " Radix Sort ";
                bucketSort(nums);
                radixSort(nums);
                break;
            case 10:
                cout << " Library Sort ";
                std::sort(nums.begin(), nums.end());
                break;
            default:
                return 0;
        }
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

void repeatSymbol(char ch, int rpt)
{
    for (int i = 0; i < rpt; ++i) {
        cout << ch;
    }
}
