#include<pthread.h>
#include<iostream>
#include<unistd.h>

#define N 16
int a[N];

//thread function
void* ThreadFunc(void* arg){
    for (int i = 0; i < N; i++)
    {
        std::cout << " " << a[i] << " ";
        sleep(1);
        std::cout << "\n";
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
    if(pthread_create(&Thread, NULL, ThreadFunc, NULL) != 0){
        std::cerr << "Error creating thread\n";
        std::cin.get();
        return 1;
    }
    for (int i = 0; i < N; i++)
    {
        std::cout << " " << a[i] << " ";
        sleep(1);
        std::cout << "\n";
    }
    
    pthread_join(Thread, NULL);

    return 0;
}