#include <utility>
#include "common.h"
#include "sort.h"

using std::pair;
using std::make_pair;

// Function declarations
static void qSort(vector<int> &, int, int);
static pair<int, int> partition(vector<int> &, int, int);

// Wrapper function for optimized Quick Sort
void quickSortOptimized(vector<int> &nums) {
    qSort(nums, 0, nums.size() - 1);
}

// Recursive function to implement optimized Quick Sort
void qSort(vector<int> &nums, int left, int right) {
    // Base case: If the array has more than one element
    if (left < right) {
        // Partition the array and get the pivot indices
        auto pivot = partition(nums, left, right);

        // Recursively sort the subarrays
        qSort(nums, left, pivot.first - 1);   // Sort elements to the left of the pivot
        qSort(nums, pivot.second + 1, right); // Sort elements to the right of the pivot
    }
}

// Partition function to rearrange the elements and return pivot indices
pair<int, int> partition(vector<int> &nums, int left, int right) {
    // Base case: If the array has one or fewer elements
    if (left >= right) {
        // Return the indices as a pair (no partitioning needed)
        return make_pair(left, right);
    }

    int pivot = nums[right];  // Choose the pivot element as the last element
    int i = left;             // Index for iterating through the array
    int k = left;             // Index of the smaller element
    int equalCnt = 1;         // Counter for elements equal to the pivot

    // Iterate through the array
    while (i < right) {
        if (nums[i] < pivot) {
            // If the current element is less than the pivot, swap it with the smaller element
            swap(nums[i++], nums[k++]);
        } else {
            if (nums[i] == pivot) {
                // If the current element is equal to the pivot, swap it with an element on the right side
                swap(nums[i], nums[--right]);
                ++equalCnt;
            } else {
                ++i;
            }
        }
    }

    // Move the elements equal to the pivot to their correct positions
    for (int j = 0; j < equalCnt; ++j) {
        swap(nums[k + j], nums[right + j]);
    }

    // Return the pivot indices as a pair
    return make_pair(k, k + equalCnt - 1);
}
