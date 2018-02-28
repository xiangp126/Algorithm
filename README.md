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
./bin/sortdemo
||=>> Select Sort Algorithm @
[1]: Bubble Sort       [2]: Insert Sort       [3]: Quick  Sort
[4]: Quick  Sort(Op)   [5]: Shell  Sort       [6]: Heap   Sort
[7]: Merge  Sort       [8]: Bucket Sort       [9]: Radix  Sort
[10]:Library Fun       [*]: Quit Selection
Original Array:
-79 -27 61 84 22 -77 -87 -19 39 2 80 -26 89 72 74 -43 86 -54 -96 -89
Input Here: 3
After Sorted:
-96 -89 -87 -79 -77 -54 -43 -27 -26 -19 2 22 39 61 72 74 80 84 86 89
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
