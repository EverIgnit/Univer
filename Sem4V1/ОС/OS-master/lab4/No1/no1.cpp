#include<iostream>
#include<pthread.h>
#include<unistd.h>

void* thread_func1(void* arg){
    while(true){
        std::cout << "1 ";
        sleep(0);
    }
}

void* thread_func2(void* arg){
    while(true){
        std::cout << "2 ";
        sleep(0);
    }
}

int main(){
    pthread_t thread1, thread2;
    
    //creating threads
    pthread_create(&thread1, NULL, &thread_func1, NULL);
    pthread_create(&thread2, NULL, &thread_func2, NULL);
    
    //delay to show threads working
    sleep(15);
    //closing threads
    pthread_cancel(thread1);
    pthread_cancel(thread2);

    return 0;
}