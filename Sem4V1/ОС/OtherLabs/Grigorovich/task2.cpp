#include <pthread.h>//Использование мьютекса 

#include <iostream>

using namespace std;

#define N 25

int a[N];

pthread_mutex_t sync;//тип данных

void* ThreadFunc(void*) {
    int pause;

    int code = pthread_mutex_lock(&sync);//захват
    if (code != 0) {
        cout << "Mutex lock error: " << code << endl;
            return (void*)-1;
    }

    for (int i = 0; i < N; i += 1) {
        cout << " " << a[i] << " ";

        for (long j = 0; j < 1000000; j += 1) {
            pause++;
        }
    }

    cout << endl;

    code = pthread_mutex_unlock(&sync);//освобождение
    if (code != 0) {
        cout << "Mutex unlock error: " << code <<  endl;
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

    int code = pthread_mutex_init(&sync, NULL);//инициализация мьютекса
    if (code != 0) {
        cout << "Mutex init error: " << code << endl;
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

    code = pthread_mutex_lock(&sync);//Блокировка
    if (code != 0) {
        cout << "Mutex lock error: " << code << endl;
        return -1;
    }

    for (int i = 0; i < N; i +=1 ) {
        cout << " " << a[i] << " ";

        for (long j = 0; j < 1000000; j +=1 ) {
            pause++;
        }
    }

    cout << endl;

    code = pthread_mutex_unlock(&sync);//освобождает объект мьютекса, на который ссылается мьютекс
    if (code != 0) {
        cout << "Mutex unlock error: " << code << endl;
        return -1;
    }

    pthread_join(Thread, NULL);

    code = pthread_mutex_destroy(&sync);//уничтожение объекта мьютекса
    if (code != 0) {
        cout << "Mutex destroy error: " << code << endl;
        return -1;
    }

    return 0;
}