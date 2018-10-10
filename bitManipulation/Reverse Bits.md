## Reverse Bits
### Illustrate
<https://leetcode.com/problems/reverse-bits/>

### Code
```c
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        for (int i = 0; i < 32; ++i) {
            ret += ((n >> i) & 0x1) << (31 - i);
        }
        return ret;
    }
};
```