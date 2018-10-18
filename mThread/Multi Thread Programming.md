## Multi Thread Programming

#### _Classical Routine_
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