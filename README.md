## Algorithm
- source algorithm will generate dynamic library, can be used for outer usage.

- can be directly compiled on MAC and Linux

- key kind of algorithm
    - sort
    - kmp

## Quick Start
```bash
# gcc need support C++11
make
source env.sh
ldd bin/sortdemo
        linux-vdso.so.1 =>  (0x00007fffe4fc2000)
        libmybasic.so => ./lib/libmybasic.so (0x00007fae138aa000)      <== mylib
        libmysort.so => ./lib/libmysort.so (0x00007fae136a0000)        <== mylib
        libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007fae1331e000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007fae13108000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fae12d3e000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007fae12a35000)
        /lib64/ld-linux-x86-64.so.2 (0x00007fae13aad000)
```

## Summarize Sort
    basic sort No. 9+, according to description in book & website, implement as it.

- Linear
    - bucketSort
    - radixSort
- O(Nlog(N))
    - quickSort
    - quickSortOptimized
    - shellSort
    - heapSort
    - mergeSort
- O(N^2)
    - bubbleSort
    - insertSort

### Example
``` bash
source env.sh (not needed for MAC)
./bin/sortdemo
||=>> Select Sort Algorithm @
[1]: Bubble Sort       [2]: Insert Sort       [3]: Quick  Sort
[4]: Quick  Sort(Op)   [5]: Shell  Sort       [6]: Heap   Sort
[7]: Merge  Sort       [8]: Bucket Sort       [9]: Radix  Sort
[10]:Library Fun       [*]: Quit Selection
-------------------------- Original Array --------------------------
49 -85 -98 -78 -44 30 -48 66 63 89 6 -58 66 83 91 76 -7 -72 88 -23
Input Here: 3
-------------------------- Quick Sort --------------------------
-98 -85 -78 -72 -58 -48 -44 -23 -7 6 30 49 63 66 66 76 83 88 89 91

||=>> Select Sort Algorithm @
[1]: Bubble Sort       [2]: Insert Sort       [3]: Quick  Sort
[4]: Quick  Sort(Op)   [5]: Shell  Sort       [6]: Heap   Sort
[7]: Merge  Sort       [8]: Bucket Sort       [9]: Radix  Sort
[10]:Library Fun       [*]: Quit Selection
-------------------------- Original Array --------------------------
11 -91 40 -37 -84 31 44 -62 -11 -67 -33 -34 60 -81 77 40 -7 82 13 17
Input Here: 5
-------------------------- Shell Sort --------------------------
-91 -84 -81 -67 -62 -37 -34 -33 -11 -7 11 13 17 31 40 40 44 60 77 82
```

## Summarize Kmp
    K.M.P Algorithm was very useful in context of sub string search.
    - kmp
    - kmpOptimized

### Figures about Next array
    You May Know Well about the Next Array From Below Two Figures.

![next1](http://img1.tuicool.com/2E36nuQ.png!web)

![next2](http://img1.tuicool.com/qYN3u2v.png!web)

### Example

```bash
source env.sh (not needed for MAC)
./bin/kmpdemo
basic kmp:
str = BBCABCDABABCDABCDABDET
pattern = BCDABDE
-1 0 0 0 0 1 0
Index = 14

optimized kmp:
str = BBCABCDABABCDABCDABDET
pattern = BCDABDE
-1 0 0 0 1 1 0
Index = 14
```

## Reference
[Illustration of NEXT](http://www.tuicool.com/articles/yayeIbe)
