## Sum of Two Integers
### Illustrate
<https://leetcode.com/problems/sum-of-two-integers>

Calculate the sum of two integers a and b, but you are **not allowed** to use the operator `+` and `-`.

### Example

```c
Input: a = 1, b = 2
Output: 3

Input: a = -2, b = 3
Output: 1
```

### Concept

```c
// _binary number a & b_
0 + 1 = 0 ^ 1
1 + 1 = (1 ^ 1) | ((1 & 1) << 1)

a + b = (a ^ b) | ((a & b) << 1)
          Add          Carry
           |
  (sum without carry)      
```          

For those not understanding this:

Given `14` and `13` (`1110` and `1101` respectively)

```c
// 14 + 13 = 27
First sum = 00011 (3)

    1110 (14)
  ^ 1101 (13)
  ------------
    0011 (3)
    
Next b = 1100 << 1 ---> 11000 (24)

    1110 (14)
  & 1101 (13)
  ------------
    1100 (12)

Notice that 3 + 24 is still the sum we want
```

Next loop:

```c
sum = 11011 (27)

     0011 (3)
  ^ 11000 (24)
  ------------
    11011 (27)
    
b = 000000 << 1 ---> 0

     0011 (3)
  & 11000 (24)
  ------------
    00000 (27)
```

### Code - _Recursive_

```c
class Solution {
public:
    int getSum(int a, int b) {
        return addition(a, b); 
    }
    /*
     * addition: sum of two integers
     * @a: sum without carry
     * @b: the carry
     * @return the add result
     */
    int addition(int a, int b) {
        if (b == 0) {
            // carry is zero, just return the sum(part without carry)
            return a;
        }
        // dfs for sum(without carry) and carry
        return addition(a ^ b, (a & b) << 1);
    }
};
```

### Code - _Iterative_
```c
// correct me
class Solution {
public:
    int getSum(int a, int b) {
        int sum = a;
        while (b != 0) {
            // calculate sum of a and b without thinking the carry
            sum = a ^ b;
            // calculate the carry
            b = (a & b) << 1;
            // add sum(without carry) and carry
            a = sum;
        }
        return sum;
    }
};
```