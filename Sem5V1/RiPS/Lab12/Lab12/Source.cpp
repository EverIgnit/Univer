#include <Windows.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <future>
#include <thread>

using namespace std;

struct futureData {
	int n, futureNumber, count, ** firstMatrix, ** secondMatrix, ** resultMatrix;
	promise<void> promiseObject;
	futureData(int n, int futureNumber, int count, int** firstMatrix, int** secondMatrix, int** resultMatrix) {
		this->firstMatrix = firstMatrix;
		this->secondMatrix = secondMatrix;
		this->resultMatrix = resultMatrix;
		this->n = n;
		this->futureNumber = futureNumber;
		this->count = count;
		this->promiseObject = promise<void>();
	}
};

auto future_process(futureData* data) {
	
	for (auto start = data->futureNumber * data->count, end = (data->futureNumber + 1) * data->count, end1 = end / data->n, end2 = end % data->n, i = start / data->n, j = start % data->n;
		i <= end1 && i < data->n; j = 0, i++) {
		auto  n = i == end1 ? end2 : data->n;

		for (; j < n; j += 1) {
			auto sum = 0;
			for (auto k = 0; k < data->n; k += 1)
				sum += data->firstMatrix[i][k] * data->secondMatrix[k][j];
			data->resultMatrix[i][j] = sum;
		}
	}

	// выполняем promise (синхронизируемся с полученным future)
	data->promiseObject.set_value();

	delete data;
}

auto outp(int** matrix, int n, const char* filename) {
	auto fout = ofstream(filename);
	for (auto i = 0; i < n; fout << endl, i++)
		for (auto j = 0; j < n; j += 1)
			fout << matrix[i][j] << ' ';
	fout.close();
}

auto calc_mult(int** firstMatrix, int** secondMatrix, int** resultMatrix, int n, int k) {
	auto startTime = time(0);
	auto count = n * n / k + 1;
	auto futures = new future<void>[k];
	auto threads = new thread[k];

	for (auto i = 0; i < k; i++) {
		auto data = new futureData(n, i, count, firstMatrix, secondMatrix, resultMatrix);
		futures[i] = data->promiseObject.get_future();
		threads[i] = thread(future_process, data);
	}

	for (auto i = 0; i < k; i++) {
		futures[i].get();
		threads[i].join();
	}

	delete[] futures, threads;
	return time(0) - startTime;
}

int main() {
	srand(time(NULL));
	int n, k;
	cout << "Enter n, k:\n> ";
	cin >> n >> k;

	auto matrix1 = new int* [n], matrix2 = new int* [n], matrix = new int* [n];

	for (auto i = 0; i < n; i++) {
		matrix[i] = new int[n];
		matrix1[i] = new int[n];
		matrix2[i] = new int[n];
		for (auto j = 0; j < n; j += 1) {
			matrix[i][j] = 0;
			matrix1[i][j] = rand() % 9 + 1;
			matrix2[i][j] = rand() % 9 + 1;
		}
	}

	auto startTime = time(0);
	for (auto i = 0; i < n; i++)
		for (auto j = 0; j < n; j += 1)
			for (auto sum = 0, k = 0; k < n; matrix[i][j] = sum, k += 1)
				sum += matrix1[i][k] * matrix2[k][j];
	cout << "Single thread time: " << time(0) - startTime << endl;

	outp(matrix, n, "single.txt");

	cout << "Multiple threads time: " << calc_mult(matrix1, matrix2, matrix, n, k) << endl;

	outp(matrix, n, "mult.txt");

	for (auto i = 0; i < n; i++)
		delete[] matrix[i], matrix1[i], matrix2[i];
	delete[] matrix, matrix1, matrix2;
	system("pause");
}
