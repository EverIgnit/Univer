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

struct Args {
	int** arr;
	int* row;
	int* n;
	int* m;
	int* mini;
	Args(int** arr, int* row, int* n, int* m, int* mini) {
		this->arr  = arr;
		this->row  = row;
		this->n    = n;
		this->m    = m;
		this->mini = mini;
	}
	~Args() {
		delete[] row;
		delete[] n;
		delete[] m;
		delete[] mini;
	}
};

// Thdread function
void* func(void* argv) {
	struct Args* args = (Args*)argv;
	int row = *(args->row);
	int n = *(args->n);
	int m = *(args->m);
	int** arr = (args->arr);
	int mini = *(args->mini);
	int minim = arr[row][0];
	// Min search
	for (int i = 1; i < n; i++) {
		if (arr[row][i] < minim)
			minim = arr[row][i];
	}
	(args->mini[row]) = minim;
	delete[] args;
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

	// Threads' id
	pthread_t* ntid = new pthread_t[M];

	// Fill array
	srand((unsigned)time(NULL));
	int** arr = new int* [M];
	for (int i = 0; i < M; i++) {
		arr[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	// Defining mini arr
	int* mini = new int[M];
	for (int j = 0; j < M; j++)
		mini[j] = 0;


	for (int i = 0; i < M; i++) {
		struct Args* args = new Args(arr, new int(i), new int(N), new int(M), mini);
		int err = pthread_create(&(ntid[i]), NULL, func, (void*)args);
		if (err != 0) {
			errno = err;
			perror("pthread_create");
		}
	}

	//ждем конец работы потоков
	for (int i = 0; i < M; i++) {
		if (pthread_join(ntid[i], NULL) == -1) {
			perror("pthread_join: ");
		}
	}

	cout << endl << "Минимальные значение с троках" << endl;
	for (int j = 0; j < M; j++)
		cout << mini[j] << ' ';
	cout << endl;

	for (int i = 0; i < M; i++)
		delete[] arr[i];
	delete arr;
	delete[] mini;

	return 0;
}