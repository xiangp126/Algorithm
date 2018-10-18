#include <iostream>
#include <pthread.h>
#include <string.h>

using namespace std;

// fun to execute in each thread
void *fun(void *);

pthread_mutex_t pLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  pCond = PTHREAD_COND_INITIALIZER;

const char *box = "ABCD";
const int N = strlen(box);
int tCnt = 0;

int main(int argc, char *argv[])
{
    pthread_t tid[N];
    int ticks[N];
    // init each index for certain thread [0-3] => [0-3]
    for (int i = 0; i < N; ++i) {
        ticks[i] = i;
    }
    // create pthread
    for (int i = 0; i < N; ++i) {
        // pthread_create(_Nonnull, _Nullable,  void * _Nullable (_Nonnull)(_Nullable), _Nullable)
        pthread_create(&tid[i], NULL, fun, (void *)&ticks[i]);
    }
    // wait pthread to exit
    for (int i = 0; i < N; ++i) {
        pthread_join(tid[i], NULL);
    }

    cout << endl;

    return 0;
}

void *fun(void *arg) {
    if (arg == NULL) {
        return NULL;
    }
    int *ptr = (int *)arg;
    int index = *ptr;

    // main work
    for (int i = 0; i < 10; ++i) {
        // lock the mutex
        pthread_mutex_lock(&pLock);
        while ((tCnt % N) != index) {
            pthread_cond_wait(&pCond, &pLock);
        }
        cout << box[index] << " ";
        ++tCnt;
        // unlock the mutex
        pthread_mutex_unlock(&pLock);
        // notify other threads that were in queue
        pthread_cond_broadcast(&pCond);
    }

    return NULL;
}
