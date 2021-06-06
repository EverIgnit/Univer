#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <iostream>
#include <iomanip>

using namespace std;

struct Calcs{
	int**arr, arr1, mul;
	int*row, N;
	Calcs(int** arr, int** arr1, int* row, int* N, int **mul) {
		this->arr  = arr;
		this->arr1 = arr1;
		this->row = row;
		this->N = N;
		this->mul=mul;
	}
};

void *thr_fn(void *argv) {
	struct Calcs* args = (Calcs*)argv;
	
	int **arr = (args->arr);
	int **arr1 = (args->arr1);
	int row = *(args->row);
	int N = *(args->N);
	
	int buf_mul = 0;

	for (int i = 0; i < N; i++) {	

        buf_mul = 0;

		for (int z = 0; z < N; z++){
            buf_mul += arr[row][z] * arr1[z][i];
        }

        (args->mul[row][i]) = buf_mul;
	}
}


void main(int argc, char *argv[])
{
	int N = -1;
	while(N<0 || N > 1000){
		cout << "Enter N (0<N<1000):\n->\t";
		cin >> N ;
		if (N < 0 || N > 1000) {
			cout << "Wrong input \n";
			return;
		}
	}
	N *= N;

	pthread_t* num = new pthread_t[N];

	int** arr  = new int*[N];
	int** arr1 = new int*[N];

	srand((unsigned)time(NULL));

	for (int i = 0; i < N; i++) {
		arr[i]  = new int[N];
		for (int j = 0; j < N; j++)
		{
			arr[i][j]  = rand() % 5;
			cout << setw(2) << arr[i][j] << ' ';
		}
		cout << endl;
	}

	for (int i = 0; i < N; i++) {
		arr1[i]  = new int[N];
		for (int j = 0; j < N; j++)
		{
			arr1[i][j] = rand() % 5;
			cout << setw(2) << arr1[i][j] << ' ';
		}
		cout << endl;
	}
	
	int** mul = new int*[N];

	for (int i = 0; i < N; i++) {
		mul[i] = new int[N];
		for (int j = 0; j < N; j++)
			mul[i][j] = 0;
	}

	
	for (int i = 0; i < N; i++) {

		struct Calcs* args = new Calcs(arr, arr1, new int(i), new int(N),mul);
		if (int err = pthread_create(&(num[i]), NULL, thr_fn, (void *)args) != 0) {
			errno = err;
			perror("pthread_create");
		}
	}
	for (int i = 0; i < N; i++)
		if (pthread_join(num[i], NULL) == -1)
			perror("pthread_join: ");
	}

	cout << "\nAnswer:\n";

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << mul[i][j] << ' ';
		cout << endl;
	}
	delete arr;
	return;
}
