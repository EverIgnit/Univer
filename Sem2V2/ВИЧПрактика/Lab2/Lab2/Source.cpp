#include "Header.h"
#include <iostream>
#include <windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Задача 1
	/*
	cout << "Введите K от 1 до 180\nДля остановки программы введите число вне этих рамок\n";
	int k = 1;
	while ((k > 0) && (k < 181)) {
		cout << "Input:\t";
		cin >> k;
		Posl D(k);
		cout << "В " << k << "-й позиции находиться цифра " << D.find() << endl;
		//10111213141516171819202122232425...
	}
	*/
	// Задача 2
	/**/
	cout << "Введите координаты трёх городов на плоскости\n";
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Point A(x1, y1), B(x2, y2), C(x3, y3);
	if (check(A, B, C))
	cout << "Все три пункта можно проехать, не поворачивая\n";
	else
	cout << "Все три пункта невозможно проехать, не поворачивая\n";
	// 1 8 -2 -7 -4 -17    true
	/**/
	// Задача 3
	/*
	// Условие в Златопольский, Сборник задач по программированию 4.108 и 5.66
	cout << "Введите цифры двух двухзначных чисел в виде a2a1, b2b1\n";
	int a2, a1, b2, b1;
	cin >> a2 >> a1 >> b2 >> b1;
	Number A(a2, a1), B(b2, b1);
	cout >> A - B;
	*/
	// Задача 4
	/*
	cout << "Введите натуральное число n\n";
	int n;
	cin >> n;
	NumF a(n);
	a.func();
	*/
	system("pause");
	return 0;
}