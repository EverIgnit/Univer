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

// Stuct with arguments for the func()
struct Args {
	int* arr;
	int i;
	int N;
	int* max_in_parts;
	Args(int* arr, int i, int N, int max_in_parts;{
		this->arr = arr;
		this->i = i;
		this->N = N;
		this->max_in_parts;= max_in_parts;
	}
	~Args() {
		delete[]arr;
		delete[]max_in_parts;
	}
};

// Thdread function
void* func(void* argv) {
	// To get the direct access
	Args* args = (Args)argv;
	int submax = args->arr[0];
	// Calc max in a row
	for (int j = 0; j < args->N; j++)
		if (args->arr[j] > max)
			max = args->arr[j];
	args->max_in_parts[args->i] = max;
	delete[]args;
}


int main(int argc, char* argv[])
{
	//Input
	int N, M;
	cout << "Enter size (M x N)" << endl;
	do {
		cout << "M:\n->\t";
		cin >> M;
		cout << "N:\n->\t";
		cin >> N;
		if (N < 1 || M < 1) {
			cout << "Invalid data\n";
			continue;
		}
	} while (false);

	// Fill array
	srand((unsigned)time(NULL));
	int** arr = new int* [M];
	for (int i = 0; i < M; i++) {
		arr[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = rand() % 100;
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	// Create threads
	int* max_in_parts= new int[M];
	pthread_t* threads = new pthread_t[M];
	for (int i = 0; i < M; i++) {
		Args* args = new Args(arr[i], i, N, max_in_parts);
		// Function call
		int err = pthread_create(&(tid[i]), NULL, func, (void*)(args));
		if (err != 0) {
			errno = err;
			perror("error");
		}
	}
	int max = max_in_parts[0];
	for(int i = 1; i < M; i++)
		if(max_in_parts[i]>max)
			max = max_in_parts[i];
	cout << "Max element: " << max < , endl;
	for (int i = 0; i < M; i++)
		delete[] arr[i];
	delete arr;

	return 0;
}