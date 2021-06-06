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
	cout << "Введите время на часах (h часов, m минут)\nInput:\t";
	int h, m;
	cin >> h >> m;
	Time D(h, m);
	int kjl = 1;
	cout << "Стрелки совпадут через " << D.Calculate(kjl)
		<< " минут\nСтрелки будут противоположно направленны через ";
	cout << D.Calculate(0) << " минут\n";
	/**/
	system("pause");
	return 0;
}