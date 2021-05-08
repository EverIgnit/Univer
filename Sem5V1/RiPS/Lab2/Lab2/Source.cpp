#include <iostream>
#include <ctime>
#include <windows.h>
#include <fstream>
using namespace std;

int k, n, ** matrix1 = NULL, ** matrix2 = NULL, ** matrix = NULL;

DWORD WINAPI Mult(CONST LPVOID lpParam)
{
	auto start = n * (int)lpParam / k, end = start + n / k;
	if (k - k / n < end)
		end = n - 1;

	for (int i = start; i < end; i++)
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = 0;
			for (int z = 0; z < n; z++)
				matrix[i][j] += matrix1[i][z] * matrix2[z][j];
		}

	return 0;
}

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

	auto hThreads = new HANDLE[k];
	for (auto i = 0; i < k; i++)
		hThreads[i] = CreateThread(NULL, 0, Mult, (LPVOID)i, 0, NULL);

	WaitForMultipleObjects(k, hThreads, TRUE, INFINITE);

	for (auto i = 0; i < n; file2 << endl, i++)
		for (auto j = 0; j < n; j++)
			file2 << matrix[i][j] << ' ';

	for (auto i = 0u; i < k; i++)
		if (hThreads[i] != 0)
			CloseHandle(hThreads[i]);
	delete[] hThreads;
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

/*
#include <cstdlib>
CRITICAL_SECTION ci;
InitializeCriticalSection(&ci);
EnterCriticalSection(&ci);
cout << "id: " << id << " start: " << start << " end: " << end << endl;
LeaveCriticalSection(&ci);
*/
