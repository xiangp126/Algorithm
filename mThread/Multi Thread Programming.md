## Multi Thread Programming

### _Classical Routine_
* Lock the mutex

```c
pthread_mutex_lock(&pLock);
```

* Check condition

> _should use `while` not `if`_

```c
while ((tCnt % N) != index) {
    pthread_cond_wait(&pCond, &pLock);
}
```

* Do main job

```c
cout << box[index] << endl;
++tCnt;
```

* Unlock the mutex

```c
pthread_mutex_unlock(&pLock);
```

* Notify other threads that were waiting

```c
pthread_cond_broadcast(&pCond);
```

### _Dead Lock_

```java
// simple demo
public class DeadLock {
    private static Object lock1 = new Object();
    private static Object lock2 = new Object();

    public static void main(String[] args) {
        new Thread(() -> {
            synchronized (lock1) {
                sleep(2000);
                System.out.println("thread 1, wait for lock2");
                synchronized (lock2) {
                    System.out.println("job of thread 1 done");
                }
            }
        }).start();

        new Thread(() -> {
            synchronized (lock2) {
                sleep(2000);
                System.out.println("thread 2, wait for lock1");
                synchronized (lock1) {
                    System.out.println("job of thread 2 done");
                }
            }
        }).start();
    }

    private static void sleep(long time) {
        try {
            Thread.sleep(time);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}
```

### Explain for Lambda expression above
```java
/**
 * 测试lambda表达式
 *
 * @author benhail
 */
public class TestLambda {

    public static void runThreadUseLambda() {
        //Runnable是一个函数接口，只包含了有个无参数的，返回void的run方法；
        //所以lambda表达式左边没有参数，右边也没有return，只是单纯的打印一句话
        new Thread(() ->System.out.println("lambda实现的线程")).start(); 
    }

    public static void runThreadUseInnerClass() {
        //这种方式就不多讲了，以前旧版本比较常见的做法
        new Thread(new Runnable() {
            @Override
            public void run() {
                System.out.println("内部类实现的线程");
            }
        }).start();
    }

    public static void main(String[] args) {
        TestLambda.runThreadUseLambda();
        TestLambda.runThreadUseInnerClass();
    }
}
```