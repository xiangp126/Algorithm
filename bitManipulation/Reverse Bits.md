## Reverse Bits
### Illustrate
<https://leetcode.com/problems/reverse-bits/>

Reverse bits of a given 32 bits unsigned integer.

**Hint**

```c
    00000010100101000001111010011100
 &  00000000000000000000000000000001
 EQ

Take use of
(n >> i) & 0x1)
```

### Code
C++

```c++
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for (int i = 0; i < 32; ++i) {
            ret |= ((n >> i) & 0x1) << (31 - i);
        }
        return ret;
    }
};
```

or

```cpp
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for (int i = 0; i < 32; ++i) {
            ret = ret << 1;
            ret |= ((n >> i) & 0x1);
        }
        return ret;
    }
};
```

Java

```java
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int ret = 0;
        for (int i = 0; i < 32; ++i) {
            ret |= ((n >> i) & 0x01) << (31 - i);
        }
        return ret;
    }
}
```
