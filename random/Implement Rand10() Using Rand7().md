## Implement Rand10() Using Rand7()
### Illustrate
<https://leetcode.com/problems/implement-rand10-using-rand7/>

Given a function rand7 which generates a uniform random integer in the range 1 to 7, write a function rand10 which generates a uniform random integer in the range 1 to 10.

Do NOT use system's Math.random().

### Concept

> throw `rand7` _2_ times yields _49_ cases, so we could get _2_ number among _[1 - 7]_<br>
use these **_49_** cases to make `rand40` => range [1 - 40]<br>
then `rand10` could be `rand40 % 10` => range [1 - 10]

### Example
```c
Input: 1
Output: [7]

Input: 2
Output: [8,4]

Input: 3
Output: [8,1,10]
```

### Code - Rejection Sampling
```c
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // (rand40() % 10) range [0 - 9]
        return (rand40() % 10) + 1;
    }

    /*
     * rand49(): range [1 - 49]
     * throw rand7() for two times to make rand49
     *
     * (7 * (rand7() - 1)) => [0, 7, 14, 21, 28, 35, 42]
     * rand7() - 1         => [1, 2, 3, 4, 5, 6, 7]
     */
    int rand49() {
        return (7 * (rand7() - 1)) + rand7();
    }

    /*
     * rand40(): range [1 - 40]
     * reject useless sampling [41, 42, 43, 44, 45, 46, 47, 48], re-calculate
     */
    int rand40() {
        int rand = rand49();
        // cout << "rand49 = " << rand << endl;
        while (rand > 40) {
            rand = rand49();
        }
        return rand;
    }
};
```
