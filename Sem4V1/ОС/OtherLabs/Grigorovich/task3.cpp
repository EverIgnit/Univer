#include <pthread.h>//семафор 
#include <semaphore.h>
#include <errno.h>

#include <iostream>

using namespace std;

#define N 25

int a[N];

sem_t sync;//тип дпнных

void* ThreadFunc(void*) {
    int pause;

    if (sem_wait(&sync) < 0) {//проверка, если счётчик меньше нуля
        perror("sync wait error");
        return (void*)-1;
    }

    for (int i = 0; i < N; i += 1) {
        cout << " " << a[i] << " ";

        for (long j = 0; j < 1000000; j += 1) {
            pause++;
        }
    }

    cout << endl;

    if (sem_post(&sync) < 0) {//проверка счётчика
        perror("sync post error");
        return (void*)-1;
    }

    return 0;
}

int main(void) {
    pthread_t Thread;
    int pause;
    int res;

    for (int i = 0; i < N; i += 1) {
        a[i]=i;
    }

    if (sem_init(&sync, 0, 1) < 0) {//инициализация семафора 
        perror("sync init error");
        return -1;
    }

    res = pthread_create(
        &Thread,
        NULL,
        ThreadFunc,
        NULL
    );

    if (res != 0) {
        cerr << "Ошибка при создании потока" << endl;
        return 0;
    }

    if (sem_wait(&sync) < 0) {
        perror("sync wait error");
        return -1;
    }

    for (int i = 0; i < N; i +=1 ) {
        cout << " " << a[i] << " ";

        for (long j = 0; j < 1000000; j +=1 ) {
            pause++;
        }
    }

    cout << endl;

    if (sem_post(&sync) < 0) { 
        perror("sync post error");
        return -1;
    }

    pthread_join(Thread, NULL);

    if (sem_destroy(&sync) < 0) {//уничтожение  семафора 
        perror("sync destroy error");
        return -1;
    }

    return 0;
}
// sem_post () увеличивает (разблокирует) семафор, на который указывает sem .
// sem_wait () уменьшает (блокирует) семафор.