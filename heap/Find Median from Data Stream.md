## Find Median from Data Stream
### Illustrate
<https://leetcode.com/problems/find-median-from-data-stream/>

### Code
```c++
class MedianFinder {
private:
    // Max-Heap, the default
    priority_queue<int, vector<int>, less<int>> maxHeap;
    // Min-Heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    /*
     * Bug point: Never compare the result of the minus of two unsigned ints
     * with a positive number.
     *
     * rebalance: Keep the size difference between the two heaps no more than 1.
     */
    void rebalance() {
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else {
            if (minHeap.size() > maxHeap.size() + 1) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }

public:
    MedianFinder() {

    }

    void addNum(int num) {
        if (!maxHeap.empty() && num > maxHeap.top()) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }
        rebalance();
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            if (maxHeap.size() < minHeap.size()) {
                return minHeap.top();
            } else {
                return maxHeap.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

Or use a cast, to cast an unsigned int to a signed int right before comparison.

```cpp
    /*
     * Bug point: Never compare the result of the minus of two unsigned ints
     * with a positive number.
     */
    void rebalance() {
        if ((signed int)(maxHeap.size() - minHeap.size()) > 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else {
            if ((signed int)(minHeap.size() - maxHeap.size()) > 1) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
```

### Debug - Take Care of The `Unsigned` Data

```cpp
#include <iostream>

using namespace std;

int main() {
    uint a = 0;
    uint b = 1;
    if (a - b < 1) {
        cout << "Expected! a - b < 1" << endl;
    } else {
        cout << "Unexpected! a - b > 1" << endl;
        cout << "a - b = " << a - b << endl;
    }
}

# Output
Unexpected! a - b > 1
a - b = 4294967295
```

What we hope is -1 < 1. The calculation result is indeed the complement of -1.

However, let's not forget that this is the subtraction of two unsigned numbers. So the computer thinks that the result is also unsigned.

The complement of -1 becomes the largest unsigned integer. As a result, the final comparison result is completely opposite to what we expected.

```cpp
2^32 - 1 = 11111111111111111111111111111111
```

[Two's Complement](https://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html)
