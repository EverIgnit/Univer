#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <unistd.h>
#include <iostream>

using namespace std;


int M;
pthread_mutex_t syncCCC;
bool bear = false;
int N;  
int kotel = 0;
void* ThreadFunc(void *arg) {
    int number = *((int *)arg) + 1;
    for(;;){
        sleep(number);
   int code = pthread_mutex_lock(&syncCCC);
    if (code != 0) {
        cout << "Mutex lock error: " << code << endl;
            return (void*)-1;
    }
        cout<<"Пчела номер "<<number<<" взяла 1 каплю меда"<<endl;

        
        if(kotel < N){
            cout<<"Пчела добавила 1 каплю мёда в горшок"<<endl;
            kotel+=1;
            cout<<"В горшке "<<kotel<<" капель мёда"<<endl;
            if(kotel == N){
                bear = true;
                cout<<"Медведь проснулся"<<endl;
                kotel = 0;
                cout<<"Медведь опустошил горшок"<<endl;
            }
        } 
    code = pthread_mutex_unlock(&syncCCC);
    if (code != 0) {
        cout << "Mutex unlock error: " << code <<  endl;
        return (void*)-1;
    }
    }
    return 0;
}

int main(void) {
    cout << "Enter M" << endl;
    cin >> M;
    cout << "Enter N" << endl;
    cin >> N ;
    kotel = 0;
    int code = pthread_mutex_init(&syncCCC, NULL);
    if (code != 0) {
        cout << "Mutex init error: " << code << endl;
        return -1;
    }
   pthread_t *threads = new pthread_t[M];

    for (int i = 0; i < M; i += 1)
    {
        int *number = new int(i);
        int errorCode = pthread_create(
            &threads[i],
            NULL,
            ThreadFunc,
            (void *)number);
        if (errorCode != 0)
        {
            cout << "Error creating thread: " << errorCode << endl;

            delete[] threads;

            return -1;
        }
    }
    for (int i = 0; i < M; i++)
    {
        pthread_join(threads[i],NULL);
    }
    code = pthread_mutex_destroy(&syncCCC);
    if (code != 0) {
        cout << "Mutex destroy error: " << code << endl;
        return -1;
    }

    return 0;
}