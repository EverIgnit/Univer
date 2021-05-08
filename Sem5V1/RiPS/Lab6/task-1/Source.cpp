/*
chcp 1251
d
cd D:\Programming\Cpp\CppProj\Debug
mpiexec -np 3 CppProj.exe
pause
*/
#include "mpi.h"
#include <iostream>
#include <ctime>
#include <windows.h>
#include <fstream>
using namespace std;

int k, n, ** matrix1 = NULL, ** matrix2 = NULL, ** matrix = NULL;

auto Calc(int start, int end)
{
	auto *result = new int[end];
	for (auto r = 0, i = start / n, j = start % n; r < end; r++)
	{
		result[r] = 0;
		for (auto k = 0; k < n; k++)
			result[r] += matrix1[i][k] * matrix2[k][j];
		if (++j == n)
		{
			j = 0;
			i++;
		}
	}
	return result;
}
auto Des(int* result, int start, int END)
{
	for (int i = start / n, j = start % n, r = 0; r < END; r++)
	{
		matrix[i][j] = result[r];
		if (++j == n)
		{
			j = 0;
			i++;
		}
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	srand(time(NULL));


	ofstream file1, file2;
	file1.open("withoutThreads.txt");
	file2.open("withThreads.txt");

	cout << "¬ведите N и k\n> ";
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

	int size, rank, count = (n * n) / k, count1 = (n * n) % k, end = count;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	k = size - 1;
	if (rank == 0)
	{
		for (auto i = 1; i < size; i++)
		{
			auto t = i - 1, start = t < count1 ? ++end * t : count1 + count * t, * data = new int[end];
			MPI_Recv(&data[0], end, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			Des(data, start, end);
			delete[]data;
		}
		for (auto i = 0; i < n; i++)
			for (auto j = 0; j < n; j++)
			{
				matrix[i][j] = 0;
				for (auto k = 0; k < n; k++)
					matrix[i][j] += matrix1[i][k] * matrix2[k][j];
			}
	}
	else
	{
		auto t = rank - 1, start = t < count1 ? ++end * t : count1 + count * t, *data = Calc(start, end);
		MPI_Send(&data[0], end, MPI_INT, 0, 0, MPI_COMM_WORLD);
		delete[]data;
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
