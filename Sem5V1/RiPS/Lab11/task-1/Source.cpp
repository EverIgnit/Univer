#include <iostream>
#include <Windows.h>
#include <cmath>
#include <ctime>
#include <future>

using namespace std;

double a, b, c, d, hx, hy, *result;
int n, m, k, f, counter = 0;


double(*funcs[]) (double, double) = {
	[](double x, double y) {return exp(x) * sin(y);},
	[](double x, double y) {return sin(x + 2 * y); },
	[](double x, double y) {return cos(x * exp(y)); },
	[](double x, double y) {return exp(cos(x * x + y)); }
};

auto Multi(int param) {
	auto res = 0.0;
	for (auto i = (int)param; i < m * n; i += k)
		res += funcs[f-1](a + (hx / 2) + hx * (i % n), c + (hy / 2) + hy * (i / n));
	return res;
}

auto Single() {
	auto result = 0.0, x = a + hx / 2, y = c + hy / 2;
	for (auto i = 0; i < n; i++)
		for (auto j = 0; j < m; j++)
			result += funcs[f - 1](x + i * hx, y + j * hy);
	return result * hx * hy;
}

int main() {
	cout << "Enter a, b, c, d, n, m k:\n-1 for auto\n> ";
	cin >> a;
	if (a < 0) { a = 1; b = 2; c = 3; d = 4; n = 5; m = 6; k = 7; }
	else cin >> b >> c >> d >> n >> m >> k;

	hx = (b - a) / (double)n;
	hy = (d - c) / (double)m;

	auto result = new future<double>[k];
	for (int i = 0; i < k; i++)
		result[i] = async(launch::async, Multi, i);
	double sum = 0;
	for (int i = 0; i < k; i++)
		sum += result[i].get();
	sum *= hx * hy;

	cout << "\nSinglethread: " << Single() << "\n\nMultithread: " << sum * hx * hy << endl;

	delete[] result;
	system("pause");
}