## Illustrate
- This projects aims to implement and utilize basic _**Data Structure and Algorithm**_
- Some Thoughts come from the Web and classical books with modification

## Gallery

> `kmp` & `sort` need c++11 support<br>
`consistent hash` uses `rbtree` which is a standalone source<br>
`Multi Thread Programming` is a simple demo and summarization

### build for all
```bash
# cd Algorithm
make -j
source env.sh

# then all binary were under ./bin
```
_you can also compile each demo separately, take `sort` as example_

```bash
# under Algorithm/
cd sort/
make -j

../bin/sort_demo
```

### Concept of Sort
#### Complexity of Time
_Github did not support [style](./history/sort_table.md) `label` of `html`, so I had to use pic here_
<div align=center><img src="./res/sort_table.png"/ width=85%></div>

#### Demonstrate
![](./res/sortdemo.gif)

### Concept of KMP
#### Next Array
_you may know well about the `next` array from this figure_

![](./res/next.png)

#### Demonstrate
```bash
cd kmp/
make -j

../bin/kmpdemo
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

### Red-Black Tree
_[Red-Black Tree](./rbtree) for detail_

###  Consistent Hash
_[Consistent Hash](./conhash) for detail_

### Multi Thread Programming
_[Multi Thread Programming](./mThread) for detail_

#### Demonstrate
```bash
cd mthread/
make -j

../bin/mthread_demo
A B C D A B C D A B C D A B C D A B C D A B C D A B C D A B C D A B C D A B C D
```

## Notice
_Need set env variables before execute binary (`Mac` need not do this)_

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
        libcommon.so => ./lib/libcommon.so (0x00002afbcd8e0000)     --> mylib
        libstdc++.so.6 => /lib64/libstdc++.so.6 (0x00002afbcdae3000)
        libm.so.6 => /lib64/libm.so.6 (0x00002afbcddeb000)
        libgcc_s.so.1 => /lib64/libgcc_s.so.1 (0x00002afbce0ed000)
        libc.so.6 => /lib64/libc.so.6 (0x00002afbce303000)
        /lib64/ld-linux-x86-64.so.2 (0x00002afbcd4b2000)
```

## License
The [MIT](./LICENSE.txt) License (MIT)
