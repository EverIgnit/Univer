// Белькевич Глеб
#include "Header.h"
#include <iostream>
#include <windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Задача 1
	/*
	cout << "Введите кол-во уроков, их\n длительность, а также длительность перерыва, а зтем количество уроков по информатике\n";
	int k, m, b, i;
	cin >> k >> m >> b >> i;
	School A(k, m, b, i);
	cout << "В этот день ученик провёл " << A.DayLength()/60 <<" часов "<<A.DayLength()%60<<" минут в школе\n";
	*/
	//Задача 2
	/*
	cout << "Введите натуральное четырёхзначное число\nInput:\t";
	int value;
	cin >> value;
	Num B(value);
	B.Calculate();
	cout << "Полученное число: " << B.getM() << endl;
	*/
	// Задача 3
	/*
	cout << "Вы вводите трёхзначное натуральное число x или целое число n?\nInput:\t";
	char xn;
	cin >> xn;
	cout << "Теперь введите значение этого числа\nInput:\t";
	int val;
	cin >> val;
	XN C(val);
	cout << "Полученное число: " << C.Calculate(xn) << endl;
	*/
	// Задача 4
	/**/
	cout << "Enter current time (0 < hours < 13, 0 < m < 61 минут)\nThen type 1 if we need to find perpendicular, 0 if we don't.\nInput:\t";
	int H, M;
	bool WeNeedToFindPerpendicular;
	cin >> H >> M >> WeNeedToFindPerpendicular;
	if (1 > H || H > 12 || 1 > M || M > 60) {
		cout << "Uncorrect data!\n";
		system("pause");
		return 0;
	}
	Minutes m(M);
	if (M != 60)
		H = H * 5 + M / 12;
	else
		H = H * 5;
	Minutes h(H);
	int counter = 0;
	if (WeNeedToFindPerpendicular) {
		while (m-15 != h.getmin() && h.getmin() != m+15) {
			m.setmin(m + 1);
			if (m.getmin() % 12 == 0)
				h.setmin(h + 1);
			counter++;
		}
	}
	else
		while (m.getmin() != h.getmin()) {
			m.setmin(m + 1);
			if (m.getmin() % 12 == 0)
				h.setmin(h + 1);
			counter++;
		}
	cout << "The answer is " << counter << endl;
	/**/
	system("pause");
	return 0;
}