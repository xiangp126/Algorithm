#ifndef MYSORT_H_
#define MYSORT_H_

#include <iostream>
#include <vector>
#include <string.h>
#include <stdbool.h>

using std::vector;

void bubbleSort(vector<int> &);
void insertSort(vector<int> &);
void shellSort(vector<int> &);
void quickSort(vector<int> &);
void quickSortOptimized(vector<int> &);
void heapSort(vector<int> &);
void bucketSort(vector<int> &);
void radixSort(vector<int> &);
void mergeSort(vector<int> &);

#endif /* ifndef MYSORT_H_ */
