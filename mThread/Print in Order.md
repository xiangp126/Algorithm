## Print in Order
### Illustrate
<https://leetcode.com/problems/print-in-order/>

Suppose we have a class:

```c
public class Foo {
  public void first() { print("first"); }
  public void second() { print("second"); }
  public void third() { print("third"); }
}
```
The same instance of **Foo** will be passed to three different threads. Thread A will call first(), thread B will call second(), and thread C will call third(). Design a mechanism and modify the program to ensure that second() is executed after first(), and third() is executed after second().

### Example
Example 1:

```c
Input: [1,2,3]
Output: "firstsecondthird"
```

Explanation: There are three threads being fired asynchronously. The input [1,2,3] means thread A calls first(), thread B calls second(), and thread C calls third(). "firstsecondthird" is the correct output.
Example 2:

```c
Input: [1,3,2]
Output: "firstsecondthird"
Explanation: The input [1,3,2] means thread A calls first(), thread B calls third(), and thread C calls second(). "firstsecondthird" is the correct output.
```

Note:

We do not know how the threads will be scheduled in the operating system, even though the numbers in the input seems to imply the ordering. The input format you see is mainly to ensure our tests' comprehensiveness.

### Code
```c++
class Foo {
public:
    Foo() {
        pLock = PTHREAD_MUTEX_INITIALIZER;
        pCond = PTHREAD_COND_INITIALIZER;
        flag = 0;
    }

    void first(function<void()> printFirst) {
        pthread_mutex_lock(&pLock);
        while ((flag % TOTAL) != FIRST) {
            pthread_cond_wait(&pCond, &pLock);
        }

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ++flag;

        pthread_mutex_unlock(&pLock);
        pthread_cond_broadcast(&pCond);
    }

    void second(function<void()> printSecond) {
        pthread_mutex_lock(&pLock);
        while ((flag % TOTAL) != SECOND) {
            pthread_cond_wait(&pCond, &pLock);
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        ++flag;

        pthread_mutex_unlock(&pLock);
        pthread_cond_broadcast(&pCond);
    }

    void third(function<void()> printThird) {
        pthread_mutex_lock(&pLock);
        while ((flag % TOTAL) != THIRD) {
            pthread_cond_wait(&pCond, &pLock);
        }

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        ++flag;

        pthread_mutex_unlock(&pLock);
        pthread_cond_broadcast(&pCond);
    }

private:
    pthread_mutex_t pLock;
    pthread_cond_t  pCond;
    enum {FIRST = 0, SECOND, THIRD, TOTAL};
    int flag;
};
```
