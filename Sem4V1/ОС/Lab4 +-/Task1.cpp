#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int K = 0;

void* thrfunc(void* arg) {
	cout << ("thread %d  ", *((int*)arg)) << endl;
	while (true) {
		getchar();
		printf("pthread_is_dead");
		pthread_exit(0);
	}
	return 0;
}

int main(int argc, char* argv[]) {
	cout << "Enter threads' amount:\n->\t";
	cin >> K;
	pthread_t tid[K];
	for (int i = 0; i < K; i++) {
		int err = pthread_create(&(tid[i]), NULL, thrfunc, (void*)(new int(i)));
		if (err != 0) {
			errno = err;
			perror("error");
		}
	}
	getchar();
	pthread_exit(0);
}