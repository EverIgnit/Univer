#include <pthread.h>

#include <iostream>

using namespace std;

#define N 25

int a[N];

void* ThreadFunc(void*) {
    int pause;
    for (int i = 0; i < N; i += 1) {
        cout << " " << a[i] << " ";

        for (long j = 0; j < 1000000; j += 1) {
            pause++;
        }
    }

    cout << endl;

    return 0;
}

int main(void) {
    pthread_t Thread;
    int pause;
    int res;

    for (int i = 0; i < N; i += 1) {
        a[i]=i;
    }

    res = pthread_create(
        &Thread,
        NULL,
        ThreadFunc,
        NULL
    );

    if (res != 0) {
        cerr << "Ошибка при создании потока" << endl;
        cin.get();
        return 0;
    }

    for (int i = 0; i < N; i +=1 ) {
        cout << " " << a[i] << " ";

        for (long j = 0; j < 1000000; j +=1 ) {
            pause++;
        }
    }

    cout << endl;

    pthread_join(Thread, NULL);

    return 0;
}
//Данные выводятся в данном порядке, то есть чередование 0 0 1 1 2 2 и т.д, так как присутствует задержка, то есть пауза, поэтому выводится данный результат