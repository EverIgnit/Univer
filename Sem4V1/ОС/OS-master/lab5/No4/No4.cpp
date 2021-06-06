#include<pthread.h>
#include<iostream>
#include<unistd.h>
#include<semaphore.h>

void/***/ Bear(void* arg);
int N, M, drops = 0;
// sem_t semaphore;
pthread_mutex_t mutex;
//bees fillin' the pot
/*void* Bees(void* arg){
    while(true)
    {
        //fill untill sem value == 0 (pot is full)
        while(sem_trywait(&semaphore) == 0) {
            pthread_mutex_lock(&mutex);
            drops++;
            std::cout << "Bee drops honey in a pot (#" << drops << "/" << M << ") ";        
            std::cout << "\n";
            //sem_post(&semaphore);
            //sleep(0);
            pthread_mutex_unlock(&mutex);
            sleep(0);
        }
        if(drops==M){
        pthread_mutex_lock(&mutex);
        //wake the bear up
        Bear(NULL);
        pthread_mutex_unlock(&mutex); 
        sleep(0);
        }
    }
    // return 0;
}*/

void* Bees(void* arg){
    while(true)
    {
        pthread_mutex_lock(&mutex);
        drops++;
        std::cout << "Bee drops honey in a pot (#" << drops << "/" << M << ") ";        
        std::cout << "\n";
        // sleep(1);
        //wake up the bear (last bee to drop off the honey)
        if(drops == M){
            Bear(NULL);
        }
        pthread_mutex_unlock(&mutex);
        //let the bee rest for a bit
        sleep(1);
        // sleep(0);
    }
}


void Bear(void* arg){
    //the bear doesn't do much
    std::cout << "Bear is eating the honey...\n";  
    sleep(2);
    drops = 0;
    std::cout << "the pot is empty\n--------------\n";
}

int main(void){
    // std::cout << "There are N bees in the forest, whose sole purpise is to fill up the pot with M drops of honey\n" <<
    // "Once done, the last bee to drop off the honey is the one to awaken the bear, the one to feast upon the fruit of their labour\n";
    std::cout <<"Input N (amount of bees), and M (Pot volume in droplets) (N>0, M>0)\nN:";
    std::cin >> N;
    std::cout << "M:";
    std::cin >> M;
    if(N < 0 || M < 0){
        std::cout << "invalid input\n";
        return 1;
    }
    pthread_mutex_init(&mutex, NULL);
    pthread_t threads[N];
    for(int i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, Bees, NULL);
    }

    
    /*for(int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }*/

    sleep(10);
    pthread_mutex_destroy(&mutex);

    std::cout << "The bees are tired now and will no longer work\n";
    for(int i = 0; i < N; i++) {
        pthread_cancel(threads[i]);
    }

    // pthread_t bear_thread;
    // pthread_create(&bear_thread, NULL, Bear, NULL);
    // sem_destroy(&semaphore);
    return 0;
}