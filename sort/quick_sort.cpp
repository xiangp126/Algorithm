#include "common.h"
#include "sort.h"

// Function declarations
static void qSort(vector<int> &, int, int);
static int partition(vector<int> &, int, int);

// Wrapper function for Quick Sort
void quickSort(vector<int> &nums) {
    qSort(nums, 0, nums.size() - 1);
}

// Recursive function to implement Quick Sort
void qSort(vector<int> &nums, int left, int right) {
    // Base case: If the array has more than one element
    if (left < right) {
        // Partition the array and get the pivot index
        int pivot = partition(nums, left, right);

        // Recursively sort the subarrays
        qSort(nums, left, pivot - 1);   // Sort elements to the left of the pivot
        qSort(nums, pivot + 1, right);  // Sort elements to the right of the pivot
    }
}

// Partition function to rearrange the elements
int partition(vector<int> &nums, int left, int right) {
    // Choose the pivot element as the last element
    int pivot = nums[right];
    int i = left;   // Index for iterating through the array
    int k = left;   // Index of the smaller element

    // Iterate through the array
    while (i < right) {
        // If the current element is less than the pivot, swap it with the smaller element
        if (nums[i] < pivot) {
            swap(nums[i], nums[k]);
            k++;
        }
        i++;
    }

    // Swap the pivot element with the final position of the smaller elements
    swap(nums[k], nums[right]);

    // Return the final position of the pivot element
    return k;
}
