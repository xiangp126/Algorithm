#include "kmp.h"
#include "common.h"

// http://www.cnblogs.com/tangzhengyue/p/4315393.html?utm_source=tuicool&utm_medium=referral

static void getNext(const char *, int *next);

/*! \brief sub string search
 *
 *  kmp sub string search
 *
 * \return -1 if not found sub string
 */
int subStrSearch(const char *str, const char *pattern) {
    int strLen = strlen(str);
    int ptLen = strlen(pattern);
    int next[ptLen];
    memset(next, 0, ptLen * sizeof(int));
    getNext(pattern, next);
    cout << "Next Array: ";
    printArray(next, ptLen);

    int sIndex = 0;
    int pIndex = 0;
    while (pIndex < ptLen && sIndex < strLen) {
        if ((pIndex == -1) || (str[sIndex] == pattern[pIndex])) {
            ++sIndex;
            ++pIndex;
        } else {
            pIndex = next[pIndex];
        }
    }
    return pIndex == ptLen ? sIndex - ptLen : -1;
}

/*! \brief
 *
 *  get next array of string pattern
 *
 * \return next array
 * for next[i] == k, only meet
 * str[0, ..., k - 1] == str[i - k, ..., i - 1]
 */
void getNext(const char *pattern, int *next) {
    int ptLen = strlen(pattern);
    next[0] = -1;
    int i = 0, k = -1;
    // risk of exceeding the range of array next.
    while (i < ptLen - 1) { // <-- Corrected line.
        if ((k == -1) || (pattern[i] == pattern[k])) {
            // cout << "i + 1 = " << i + 1 << endl;
            next[++i] = ++k;
        } else {
            k = next[k];
        }
    }
}
