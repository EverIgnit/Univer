#include<pthread.h>
#include<iostream>
#include<unistd.h>

#define N 10
int a[N];
pthread_mutex_t mutex;
//thread function
void* ThreadFunc(void* arg){
    for (int i = 0; i < N; i++)
    {
        while(pthread_mutex_trylock(&mutex) == EBUSY){}
        std::cout << "Thread: " << a[i] << " ";
        sleep(1);
        std::cout << "\n";
        pthread_mutex_unlock(&mutex);
    }
    return 0;
}


int main(void){
    pthread_t Thread;
    int pause, res;  
    //filling global array
    for (int i = 0; i < N; i++)
    {
        a[i]=i;
    }

    pthread_mutex_init(&mutex, NULL);

    if(pthread_create(&Thread, NULL, ThreadFunc, NULL) != 0){
        std::cerr << "Error creating thread\n";
        std::cin.get();
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        while(pthread_mutex_trylock(&mutex) == EBUSY){}
        std::cout << "Main: " << a[i] << " ";
        sleep(1);
        std::cout << "\n";        
        pthread_mutex_unlock(&mutex);        
    }
    
    pthread_join(Thread, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
