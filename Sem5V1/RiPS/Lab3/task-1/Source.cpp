#include <windows.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);
	double a, b, c, d, result = 0;
	int m, n, f, k;
	double(*func[])(double, double) = {
		[](double x, double y) {return exp(x) * sin(y); },
		[](double x, double y) {return sin(x + 2 * y); },
		[](double x, double y) {return cos(x * exp(y)); },
		[](double x, double y) {return exp(cos(x * x + y)); }
	};
	cout << "Введите a, b, c, d, n, m, k:\n(-1 для автозаполнения)\n> ";
	cin >> a;
	if (a < 0) { a = 1; b = 2; c = 3; d = 4; n = 5; m = 6; k = 7; }
	else cin >> b >> c >> d >> n >> m >> k;
	cout << "Выберите функцию, введя число [1..4]. По ум. 1\n1) e^x * sin(y)\n2) sin(x + 2y)\n3) cos(x * e^y)\n4) e^(cos(x^2 + y))\n> ";
	cin >> f;

	auto hx = (b - a) / n, hy = (d - c) / m;

	for (auto x = a; x <= b; x += hx)
		for (auto y = c; y <= d; y += hy)
			result += abs(hx * hy * func[f - 1](x + hx / 2, y + hy / 2));
	cout << "In one thread: " << result << endl;
	result = 0;

	omp_set_num_threads(k);
#pragma omp parallel reduction(+:result)
	{
#pragma omp for
		for (int i = 0; i <= n; i++)
			for (double x = a + hx * i, y = c; y <= d; y += hy)
				result += abs(hx * hy * func[f - 1](x + hx / 2, y + hy / 2));
	}
	cout << "In multiple threads: " << result << "\n\n";

	system("pause");
}
