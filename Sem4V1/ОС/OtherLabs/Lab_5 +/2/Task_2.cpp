#include <pthread.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include<ctime>

using namespace std;

#define N 25
int a[N];

pthread_mutex_t mutex; 

void* ThreadFunc(void* arg){
    int pause;

    pthread_mutex_lock(&mutex);

    for (int i = 0; i < N; i++) {
		cout << a[i] << ' ';
		for (long j = 0; j < 1000000; j++) {
			pause++;
		}
	}

	cout << endl;

	pthread_mutex_unlock(&mutex);
	return 0;
}

int main(){
    pthread_t Thread;

    pthread_mutex_init(&mutex,NULL);

    int pause;
    int res;

    for(int i=0;i<N;i++){
        a[i]=i;
    }

    res=pthread_create(&Thread,NULL,ThreadFunc,NULL);

    if(res!=0){
        cerr<<"Ошибка при создании потока"<<endl;
        return 0;
    }

    pthread_mutex_lock(&mutex);

    for (int i = 0; i < N; i++) {
		cout << a[i] << ' ';
		for (long j = 0; j < 1000000; j++) {
			pause++;
		}
	}
    
    cout<<endl;

    pthread_mutex_unlock(&mutex);
    pthread_join(Thread,NULL); 
    pthread_mutex_destroy(&mutex);

    return 0;
}
