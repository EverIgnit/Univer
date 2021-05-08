// 1
// stdin
// stdout
// Launch.bat:
/*
chcp 1251
d
cd D:\Programming\Cpp\CppProj\Debug
mpiexec -np 3 CppProj.exe
pause
*/
#include <iostream>
using namespace std;

int main(int* argc, char** argv)
{
	// Инициализация
	int N, rank, size;
	cout << "Enter N:\n> ";
	cin >> N;
	N++;
	auto arr = new double*[N + 1];
	for (auto i = 1; i <= N; i++)
		arr[i] = new double[N + 1];

	// Ввод элементов
	cout << "Enter matrix elements:\n";
	for (auto i = 1; i <= N; i++)
		for (auto j = 1; j <= N; j++)
			cin >> arr[i][j];

	// MPI инициализация
	MPI_Status status;
	MPI_Init(argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	// Распределяем строки
	int* rowsam = new int[size];
	for (auto minam = size / N, i = 0; i < size; i++)
		rowsam[i] = minam;
	if (size < N)
		for (auto lackam = size % N, i = 0; lackam > 0 && i < size; lackam--, i++)
			rowsam[i]++;

	// Вычисление
	double res = 0;
	if (rank > 0 && rank < N)
		for (auto i = 0; i < rowsam[rank]; i++)
			for (auto j = 2; j < N; j += 2)
				res += arr[i][j];
	delete[]rowsam;
	// Подсчёт результата
	if (rank != 0)
		MPI_Send(&res, 1, MPI_DOUBLE, 0, rank + 10, MPI_COMM_WORLD);
	else
	{
		for (double temp = 0, int i = 0; i < size - 1; i++) {
			MPI_Recv(&temp, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
			if (temp < res)
				res = temp;
		}
		cout << res;
	}
	
	// Завершение работы с MPI
	MPI_Finalize();

	// Сборка мусора
	for (auto i = 0; i < N; i++)
		delete[]arr[i];
	delete[]arr;
}