#include <iostream>
#include <windows.h>
#include <fstream>
#include <ctime>
#include <omp.h>
using namespace std;

int k, n, ** matrix1 = NULL, ** matrix2 = NULL, ** matrix = NULL;

int main()
{
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	ofstream file1, file2;
	file1.open("withoutThreads.txt");
	file2.open("withThreads.txt");

	cout << "¬ведите N и K\n> ";
	cin >> n >> k;

	cout << "\n»сходные матрицы:\n";

	matrix1 = new int* [n];
	matrix2 = new int* [n];
	matrix = new int* [n];
	for (auto i = 0; i < n; i++) {
		matrix1[i] = new int[n];
		matrix2[i] = new int[n];
		matrix[i] = new int[n];
		for (auto j = 0; j < n; j++) {
			matrix[i][j] = 0;
			matrix1[i][j] = rand() % 9 + 1;
			matrix2[i][j] = rand() % 9 + 1;
			cout << matrix1[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (auto i = 0; i < n; cout << endl, i++)
		for (auto j = 0; j < n; j++)
			cout << matrix2[i][j] << ' ';
	cout << endl;

	for (auto i = 0; i < n; file1 << endl, i++)
		for (auto j = 0; j < n; file1 << matrix[i][j] << ' ', j++)
			for (auto k = 0; k < n; k++)
				matrix[i][j] += matrix1[i][k] * matrix2[k][j];

	omp_set_num_threads(k);

#pragma omp parallel
	{
#pragma omp for
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				matrix[i][j] = 0;
				for (int k = 0; k < n; k++)
					matrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
	}

	for (auto i = 0; i < n; file2 << endl, i++)
		for (auto j = 0; j < n; j++)
			file2 << matrix[i][j] << ' ';

	file1.close();
	file2.close();
	for (auto i = 0; i < n; i++)
	{
		delete[]matrix[i];
		delete[]matrix1[i];
		delete[]matrix2[i];
	}
	delete[]matrix;
	delete[]matrix1;
	delete[]matrix2;
	system("pause");
}
