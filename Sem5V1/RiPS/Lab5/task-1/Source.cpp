/*
chcp 1251
d
cd D:\Programming\Cpp\CppProj\Debug
mpiexec -np 3 CppProj.exe
pause
*/
#include "mpi.h"
#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> vector_of_operations;
double a, b, c, d, hx, hy, result = 0;
int m, n, f;

double(*func[])(double, double) = {
		[](double x, double y) {return exp(x) * sin(y); },
		[](double x, double y) {return sin(x + 2 * y); },
		[](double x, double y) {return cos(x * exp(y)); },
		[](double x, double y) {return exp(cos(x * x + y)); }
};

double calculation(int i)
{
	int start = i * vector_of_operations[0],
		end = start + vector_of_operations[i],
		curr_ind = 0;
	double answer = 0;
	for (double x = a; x <= b; x += hx)
		for (double y = c; y <= d; curr_ind++, y += hy)
			if (curr_ind < end && curr_ind >= start)
				answer += hx * hy * func[f - 1](x + hx / 2, y + hy / 2);
			else if (curr_ind > end)
				return answer;
	return answer;
}

int main()
{
	SetConsoleOutputCP(1251);

	auto k = 0, count = 0;
	cout << "Введите a, b, c, d, n, m, k:\n(-1 для автозаполнения)\n> ";
	cin >> a;
	if (a < 0) { a = 1; b = 2; c = 3; d = 4; n = 5; m = 6; k = 7; }
	else cin >> b >> c >> d >> n >> m >> k;
	cout << "Выберите функцию, введя число [1..4]. По ум. 1\n1) e^x * sin(y)\n2) sin(x + 2y)\n3) cos(x * e^y)\n4) e^(cos(x^2 + y))\n> ";
	cin >> f;

	hx = (b - a) / n, hy = (d - c) / m;

	vector_of_operations = vector<int>(k, 0);
	for (auto x = a; x <= b; x += hx)
		for (double y = c, tmp = 0; y <= d; vector_of_operations[tmp]++, tmp++, y += hy)
			if (tmp == k)
				tmp = 0;

	MPI_Status status;
	MPI_Init(argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	m = calculation(rank);
	if (rank == 0)
	{
		for (double temp = 0, int i = 0; i < size - 1; m += temp, i++)
			MPI_Recv(&temp, 1, MPI_DOUBLE, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
		cout << "\nIn multiple threads: " << result << "\n\n";
	}
	else
		MPI_Send(&m, 1, MPI_DOUBLE, 0, rank + 10, MPI_COMM_WORLD);
	MPI_Finalize();

	system("pause");
}
