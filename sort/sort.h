#ifndef _SORT_H_
#define _SORT_H_

#include <iostream>
#include <vector>
#include <string.h>
#include <stdbool.h>

using std::vector;

/*! \enum SORTTYPE
 *
 *  sort type enumerator
 */
enum SORTTYPE {
    BUBBLESORT = 1,
    INSERTSORT,
    QUICKSORT,
    QUICKSORTOPTIMIZED,
    SHELLSORT,
    HEAPSORT,
    MERGESORT,
    BUCKETSORT,
    RADIXSORT
};

void bubbleSort(vector<int> &);
void insertSort(vector<int> &);
void shellSort(vector<int> &);
void quickSort(vector<int> &);
void quickSortOptimized(vector<int> &);
void heapSort(vector<int> &);
void countSort(vector<int> &);
void radixSort(vector<int> &);
void mergeSort(vector<int> &);

#endif /* ifndef _SORT_H_ */
