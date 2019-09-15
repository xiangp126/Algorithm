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
