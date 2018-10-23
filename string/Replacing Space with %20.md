## 替换空格
### Illustrate
<https://leetcode.com/problems/remove-duplicates-from-sorted-array>

请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

### Concept

> copy char of `str` from backwards

### Code

* assume `str` hash enough space, need not malloc more
* `str` not terminated with '\0'
* `length` was true length of str
        
```c
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int cnt = 0;
        char *ptr = str;
        while (ptr < str + length) {
            if (*ptr == ' ') {
                ++cnt;
            }
            ++ptr;
        }
        
        const int N = length + 2 * cnt;
        // go to the last char of new position
        char *out = str + N - 1;
        // go to the last char of original position
        --ptr;
        while (ptr >= str) {
            if (*ptr != ' ') {
                *out-- = *ptr--;
            } else {
                *out-- = '0';
                *out-- = '2';
                *out-- = '%';
                // also back one pointer step with ptr
                --ptr;
            }
        }
	}
};
```