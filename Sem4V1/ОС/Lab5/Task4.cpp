#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int M;
pthread_mutex_t mutex;
bool bear = false;
int N;  
int cauldron = 0;

void* ThreadFunc(void* arg) {
    int number = *((int*)arg) + 1;
    while (true) {
        sleep(number);
        int code = pthread_mutex_lock(&mutex);
        if (code != 0) {
            cout << "Mutex lock error: " << code << endl;
            return (void*)-1;
        }
        cout << "Bee " << number << " took 1 drop of honey" << endl;

        if (cauldron < N) {
            cout << "The bee has added 1 drop of honey to a pot" << endl;
            cauldron += 1;
            cout << "There are " << cauldron << " drops of honey in the pot" << endl;
            if (cauldron == N) {
                bear = true;
                cout << "The bear woke up" << endl;
                cauldron = 0;
                cout << "The pot was emptied by the bear" << endl;
            }
        }
        code = pthread_mutex_unlock(&mutex);
        if (code != 0) {
            cout << "Mutex unlock error: " << code << endl;
            return (void*)-1;
        }
    }
    return 0;
}

int main(void) {
    cout << "Enter M and N:\n->\t";
    cin >> M >> N;
    cauldron = 0;
    int code = pthread_mutex_init(&mutex, NULL);
    if (code != 0) {
        cout << "Mutex init error: " << code << endl;
        return -1;
    }
    pthread_t* threads = new pthread_t[M];

    for (int i = 0; i < M; i += 1)
    {
        int* number = new int(i);
        int errorCode = pthread_create(
            &threads[i],
            NULL,
            ThreadFunc,
            (void*)number);
        if (errorCode != 0)
        {
            cout << "Error creating thread: " << errorCode << endl;

            delete[] threads;

            return -1;
        }
    }
    for (int i = 0; i < M; i++)
        pthread_join(threads[i], NULL);
    code = pthread_mutex_destroy(&mutex);
    if (code != 0) {
        cout << "Mutex destroy error: " << code << endl;
        return -1;
    }
    return 0;
}