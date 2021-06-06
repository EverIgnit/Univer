#include<pthread.h>
#include<iostream>
#include<unistd.h>
#include<semaphore.h>

#define N 10
int a[N];
sem_t semaphore;
//thread function
void* ThreadFunc(void* arg){
    for (int i = 0; i < N; i++)
    {
        while(sem_trywait(&semaphore) != 0) {} 
        std::cout << "Thread: " << a[i] << " ";
        sleep(1);
        std::cout << "\n";
        sem_post(&semaphore);
        sleep(0);
    }
    return 0;
}

int main(void){
    pthread_t Thread;
    //filling global array
    for (int i = 0; i < N; i++)
    {
        a[i]=i;
    }

    sem_init(&semaphore, 0, 1);

    if(pthread_create(&Thread, NULL, ThreadFunc, NULL) != 0){
        std::cerr << "Error creating thread\n";
        std::cin.get();
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        while(sem_trywait(&semaphore) != 0) {} 
        std::cout << "Main: " << a[i] << " ";
        sleep(1);
        std::cout << "\n";     
        sem_post(&semaphore);
        sleep(0);    
    }
    
    pthread_join(Thread, NULL);
    sem_destroy(&semaphore);
    return 0;
}