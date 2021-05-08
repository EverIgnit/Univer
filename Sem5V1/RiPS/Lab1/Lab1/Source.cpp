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

DWORD WINAPI ThreadFunc(LPVOID lpStartNumber) {
	auto thr_ind = *((unsigned*)lpStartNumber);
	double thr_res = 0;
	int el = 0, z2 = thr_ind * vector_of_operations[0], z1 = z2 + vector_of_operations[thr_ind];
	for (double x = a; x <= b; x += hx)
		for (auto y = c; y <= d; el++, y += hy)
			if (el < z1 && el >= z2)
				thr_res += abs(hx * hy * func[f - 1](x + hx / 2, y + hy / 2));
			else if (el > z1) {
				result += thr_res;
				return 0;
			}
	result += thr_res;
	return 0;
}

auto main()
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

	for (auto x = a; x <= b; x += hx)
			for (auto y = c; y <= d; y += hy)
				result += abs(hx * hy * func[f - 1](x + hx / 2, y + hy / 2));
		cout << "In one thread: " << result << endl;
		result = 0;

	vector_of_operations = vector<int>(k, 0);
	for (auto x = a; x <= b; x += hx)
		for (double y = c, tmp = 0; y <= d; vector_of_operations[tmp]++, tmp++, y += hy)
			if (tmp == k)
				tmp = 0;

	auto hThreads = new HANDLE[k];
	for (auto i = 0u; i < k; i++)
		hThreads[i] = CreateThread(NULL, 0, ThreadFunc, (LPVOID)new unsigned(i), 0, NULL);

	WaitForMultipleObjects(k, hThreads, TRUE, INFINITE);

	cout << "\nIn multiple threads: " << result << "\n\n";

	for (auto i = 0u; i < k; i++)
		if (hThreads[i] != 0)
			CloseHandle(hThreads[i]);

	delete[] hThreads;
	system("pause");
	return 0;
}