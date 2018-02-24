# Summarize Sort Algorithms:

## O(N^2)
    bubbleSort
    insertSort
## O(Nlog(N))
    quickSort - simplest
    quickSort - optimized
    shellSort
    heapSort
    bucketSort
## Linear
    mergeSort
    radixSort

# Usage
    Only support C++11
    > make && ./main
    g++ -o mysort.o -Wall -std=c++11 -g3 -c sortgallery.cpp
    g++ -o main mysort.o

## Example
``` bash
    > ./sortgallery
    ----------------------- Original Array -----------------------
        -5     87    -13    -85      4     67     33    -65     45
       -48    -53    -51    -40     88    -40
    
    ||=>> Select Sort Algorithm @
    [1]: Bubble Sort       [2]: Insert Sort       [3]: Quick  Sort
    [4]: Quick  Sort(Op)   [5]: Shell  Sort       [6]: Heap   Sort
    [7]: Merge  Sort       [8]: Bucket Sort       [9]: Radix  Sort
    [10]:Library Fun       [*]: Quit Selection
    Input Here: 1
    ----------------------- Original Array -----------------------
        -5     87    -13    -85      4     67     33    -65     45
       -48    -53    -51    -40     88    -40
    ------------------------ Bubble Sort ------------------------
       -85    -65    -53    -51    -48    -40    -40    -13     -5
         4     33     45     67     87     88
    ------------------------ Bubble Sort ------------------------
    Time Elapsed: 0 ms. 22 us.  & Restore Array Done.
    
    ||=>> Select Sort Algorithm @
    [1]: Bubble Sort       [2]: Insert Sort       [3]: Quick  Sort
    [4]: Quick  Sort(Op)   [5]: Shell  Sort       [6]: Heap   Sort
    [7]: Merge  Sort       [8]: Bucket Sort       [9]: Radix  Sort
    [10]:Library Fun       [*]: Quit Selection
    Input Here: 3
    ----------------------- Original Array -----------------------
       -95    -86    -72     52     -9     83     10     16     58
         2    -87    -42    -50     47    -65
    ------------------------ Quick  Sort ------------------------
       -95    -87    -86    -72    -65    -50    -42     -9      2
        10     16     47     52     58     83
    ------------------------ Quick  Sort ------------------------
    Time Elapsed: 0 ms. 31 us.  & Restore Array Done.
    
    ||=>> Select Sort Algorithm @
    [1]: Bubble Sort       [2]: Insert Sort       [3]: Quick  Sort
    [4]: Quick  Sort(Op)   [5]: Shell  Sort       [6]: Heap   Sort
    [7]: Merge  Sort       [8]: Bucket Sort       [9]: Radix  Sort
    [10]:Library Fun       [*]: Quit Selection
    Input Here: 4
    ----------------------- Original Array -----------------------
       -48     99    -45    -84    -65    -71    -38     61    -78
       -48    -89    -38      9     78    -82
    ------------------------ Opti  Quick ------------------------
       -89    -84    -82    -78    -71    -65    -48    -48    -45
       -38    -38      9     61     78     99
    ------------------------ Opti  Quick ------------------------
    Time Elapsed: 0 ms. 23 us.  & Restore Array Done.
    
    ||=>> Select Sort Algorithm @
    [1]: Bubble Sort       [2]: Insert Sort       [3]: Quick  Sort
    [4]: Quick  Sort(Op)   [5]: Shell  Sort       [6]: Heap   Sort
    [7]: Merge  Sort       [8]: Bucket Sort       [9]: Radix  Sort
    [10]:Library Fun       [*]: Quit Selection
    Input Here: q
    > 

    ```

