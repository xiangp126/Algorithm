## Illustrate
- This projects aims to implement and utilize basic **data structure and algorithm**
- Thoughts come from the _Web_ and _classical books_ like 'Introduction to Algorithms'

## Note
_Need set env variables before execute binary (Mac need not do this)_

```bash
export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
```
_or just_

```bash
source env.sh
```

_Header directory [Inc](./inc) use soft link, making each template itself can be used as standalone_

```bash
# example
ll ./inc

common.h@ -> ../common/common.h
kmp.h@ -> ../kmp/kmp.h
md5.h@ -> ../rbtree/md5.h
rbtree.h@ -> ../rbtree/util_rbtree.h
sort.h@ -> ../sort/sort.h
```

_Each template will generate dynamic library, for shared use_

```bash
# example
ldd lib/libsort.so
        linux-vdso.so.1 =>  (0x00007ffdd0929000)
        libcommon.so => ./lib/libcommon.so (0x00002afbcd8e0000)     <= mylib
        libstdc++.so.6 => /lib64/libstdc++.so.6 (0x00002afbcdae3000)
        libm.so.6 => /lib64/libm.so.6 (0x00002afbcddeb000)
        libgcc_s.so.1 => /lib64/libgcc_s.so.1 (0x00002afbce0ed000)
        libc.so.6 => /lib64/libc.so.6 (0x00002afbce303000)
        /lib64/ld-linux-x86-64.so.2 (0x00002afbcd4b2000)
```

## Gallery
### _Quick Start_
_`kmp` & `sort` need c++11 support while `rbtree` is a standalone source_

```bash
make -j
source env.sh

# then binary was under ./bin
```

### _Concept of Sort_
#### Complexity of Time
| Sort Method | Average | Best | Worst | Stable |
| :--: | :--: | :--: | :--: | :--: |
| Bubble | N<sup>2</sup> | O(N) | N<sup>2</sup> | &radic; |
| Insert | N<sup>2</sup> | O(N) | N<sup>2</sup> | &radic; |
| Bucket | O(N) | O(N) | O(N) | &Chi; |
| Radix | O(N) | O(N) | O(N) | &radic; |
| Shell | N<sup>1.3</sup> |  |  | &Chi; |
| Heap | Nlog<sub>2</sub><sup>N</sup> | Nlog<sub>2</sub><sup>N</sup> | Nlog<sub>2</sub><sup>N</sup> | &Chi; |
| Merge | Nlog<sub>2</sub><sup>N</sup> | Nlog<sub>2</sub><sup>N</sup> | Nlog<sub>2</sub><sup>N</sup> | &radic; |
| Quick | Nlog<sub>2</sub><sup>N</sup> | Nlog<sub>2</sub><sup>N</sup> | N<sup>2</sup> | &Chi; |

#### _Demonstrate_
```bash
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
Input Here:
```

### _Concept of KMP_
#### _next array_
_You may know well about the next array from below two figures._

![next1](http://img1.tuicool.com/2E36nuQ.png!web)
![next2](http://img1.tuicool.com/qYN3u2v.png!web)

#### _Demonstrate_
```bash
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

## License
The [MIT](./LICENSE.txt) License (MIT)
