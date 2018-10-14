## 变态跳台阶
### Illustrate
<https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking>

一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。

### Concept
2<sup>n-1</sup> = C<sub>n-1</sub><sup>0</sup> + C<sub>n-1</sub><sup>1</sup> + C<sub>n-1</sub><sup>2</sup> + ... C<sub>n-1</sub><sup>n-1</sup>

```c
1 << (n - 1)
```
### Code
```c
class Solution {
public:
    int jumpFloorII(int number) {
        return 1 << (number - 1);
    }
};
```