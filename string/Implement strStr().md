## Find the Index of the First Occurrence in a String
### Illustrate
<https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/>
<https://leetcode.com/problems/implement-strstr>

Return the index of the first occurrence of needle in haystack, or **-1** if needle is not part of haystack.

### example
```c
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
```
### Code
```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLen = haystack.length();
        int nLen = needle.length();
        if (!hLen || !nLen) {
            return -1;
        }

        vector<int> nextArray(nLen, -1);
        getNextArray(needle, nextArray);

        int i = 0;  // Pointer for haystack
        int j = 0;  // Pointer for needle
        while (i < hLen && j < nLen) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;  // Move both pointers to the next character
                ++j;
            } else {
                j = nextArray[j];  // Mismatch, move j using the nextArray
            }
        }

        // Check if the full needle is found in the haystack
        if (j == nLen) {
            return i - nLen;  // Return the starting index of the found needle
        } else {
            return -1;  // Needle not found
        }
    }

    void getNextArray(string needle, vector<int> &nextArray) {
        int length = needle.length();
        if (!length) {
            return;
        };

        int j = 0;   // Pointer for the current character in the needle
        int k = -1;  // Pointer for the previous character's longest prefix suffix value
        nextArray[0] = -1;  // The first value is always -1 as there is no proper prefix

        while (j < length - 1) {
            if (k == -1 || needle[j] == needle[k]) {
                ++j;  // Move to the next character in the needle
                ++k;  // Increment the longest prefix suffix value
                nextArray[j] = k;  // Store the current longest prefix suffix value
            } else {
                k = nextArray[k];  // Update k to backtrack and find a shorter prefix suffix
            }
        }
    }
};
```
