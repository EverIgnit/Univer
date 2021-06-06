#include <pthread.h>
#include <iostream>
#include <semaphore.h>
using namespace std;

#define N 25
int a[N];

sem_t sem; 

void* ThreadFunc(void* arg) {
	int pause;

	sem_wait(&sem);

	for (int i = 0; i < N; i++) {
		cout << a[i] << ' ';
		for (long j = 0; j < 1000000; j++) {
			pause++;
		}
	}

	cout << endl;

	sem_post(&sem);
	return 0;
}

int main() {
	pthread_t Thread;
   
    sem_init(&sem,0,1);


	int pause;
	int res;

	for (int i = 0; i < N; i++) {
		a[i] = i;
	}

	res = pthread_create(&Thread, NULL, ThreadFunc, NULL);

	if (res != 0) {
		cerr << "Ошибка при создании потока";
		return 0;
	}
	
	sem_wait(&sem); 

	for (int i = 0; i < N; i++) {
		cout << a[i] << '.';
		for (long j = 0; j < 1000000; j++) {
			pause++;
		}
	}

	cout << endl;
	
	sem_post(&sem);

	pthread_join(Thread, NULL);
	sem_destroy(&sem); 

	return 0;
}
