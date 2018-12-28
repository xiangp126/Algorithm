## Illustrate
- This projects aims to implement and utilize basic _**Data Structure and Algorithm**_
- The `economic basis` determines `superstructure`

## Gallery
- `sort` implemented mostly used sort algorighms
- `kmp` Knuth-Morris-Pratt, basic and improved methods
- `conhash` implemented consistent hash, together with `rbtree`
- `kernelList` do an illustration explanation for kernel list as well as an usage demo
- `hashTable` gave an basic example using kernel hlist
- `trieTree` is for Trie Tree
- `mThread` is a summarization for Multi Thread Programming using kernel pthread
- and many other solutions came up with me or modified from the web

### build for all
_then all binaries will be under `./bin`_

```bash
# cd Algorithm
make -j
source env.sh
```
_or you can also compile each demo separately, take `sort` as example_

```bash
# under Algorithm/
cd sort/
make -j

../bin/sort_demo
```

### [Concept of Sort](./sort)
#### Complexity of Time
_Github did not support [style](./history/sort_table.md) label of `html`, so I had to use pic here_
<div align=center><img src="./res/sort_table.png" width=85%></div>

#### Demonstrate
![](./res/sortdemo.gif)

### [Concept of KMP](./kmp)
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

### [Red-Black Tree](./rbtree)
### [Consistent Hash](./conhash)
### [Kernel Hash List](./hashTable)
### [Kernel List](./kernelList)
### [Multi Thread Programming](./mThread)
### [Trie Tree](./trieTree)

## Notice
Need set env variables before execute binary (`Mac` need not do this)

```bash
export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
```
or just

```bash
source env.sh
```

Header directory [Inc](./inc) use soft link, making each template itself can be used as standalone

```bash
# example
ll ./inc

common.h@ -> ../common/common.h
kmp.h@ -> ../kmp/kmp.h
md5.h@ -> ../rbtree/md5.h
rbtree.h@ -> ../rbtree/util_rbtree.h
sort.h@ -> ../sort/sort.h
```

Each template will generate dynamic library, for shared use

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