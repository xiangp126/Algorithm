## Single Number II
### Illustrate
<https://leetcode.com/problems/single-number-ii/>

```
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99
```

### Core Concept

assume `22` appears only one time (the wanted number), but `35` appears **three** times.<br>
we calculate each bit of the `wanted number`. The `int` type contains 32 bits.

```bash
   7654 3210   th
0x 0010 0011   (35)
+  0010 0011   (35)
+  0010 0011   (35)
+  0001 0110   (22)
-------------
   0031 0143
% 3
-------------
   0001 0110   yields 22
```

The modulo

```
(1 + 1 + 1) % 3 = 0
```

### Code

```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // or you can safely assign it as 32.
        const int bitOfInt = sizeof(int) * 8;
        int array[bitOfInt] = {0};
        for (int i = 0; i < bitOfInt; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                array[i] += ((nums[j] >> i) & 0x1);
            }
            array[i] %= 3;
        }

        int ret = 0;
        for (int i = 0; i < bitOfInt; ++i) {
            ret |= (array[i] << i);
        }
        return ret;
    }
};
```

### Code

Similarly, there is is no **sizeof()** operator in Java. All primitive values have a predefined size, e.g. int is 4 bytes, char is 2 byte, short is 2 byte, long and float is 8 byte, and so on.

```java
class Solution {
    public int singleNumber(int[] nums) {
        int ret = 0;
        int[] mark = new int[32];
        for (int i = 0; i < 32; ++i) {
            for (int j = 0; j < nums.length; ++j) {
                mark[i] += (nums[j] >> i) & 0x01;
            }
        }

        for (int i = 0; i < 32; ++i) {
            ret |= (mark[i] % 3) << i;
        }
        return ret;
    }
}
```
