## Number of 1 Bits
### Illustrate
<https://leetcode.com/problems/number-of-1-bits/>

### Concept
**`num & (num - 1)`**

remove the last *1* bit

```
10 & (10 - 1) =
        0000 1010
(+)     0000 1001
    -------------
        0000 1000
             ^
```

### Code

C++

```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n) {
            n &= (n - 1);
            ++cnt;
        }
        return cnt;
    }
};
```

Java

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int cnt = 0;
        while (n != 0) {
            n &= n - 1;
            ++cnt;
        }
        return cnt;
    }
}
```