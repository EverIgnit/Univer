// Белькевич Глеб
#include "Header.h"
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Задача 1
	/*
	cout << "Введите 2 слова\nInput:\t";
	string s1;
	getline(cin, s1);
	if (CheckS(s1)) {
		Num1 A(s1);
		A.EraseTheSame();
		A.Calc();
	}
		cout << endl;
	*/
	// Задача 2
	/*
	cout << "Введите строку текста без начальных и конечных пробелов,\nа затем число - её новую длину, больше прыдыдущей\nInput:\t";
	string s2; int newl;
	getline(cin, s2);
	cin >> newl;
	Num2 B(s2, newl);
	if (B.Check()==true) {
		B.Add();
	}
	*/
	// Задача 3
	/**/
	cout << "Введите две строки, содержащие букву ш\nInput:\t";
	string s1, s2;
	getline(cin, s1);
	cout << "Input:\t";
	getline(cin, s2);
	Num3 C;
	C.Calc(s1, s2);
	/**/
	// Задача 4
	/*
	cout << "Введите натуральное число n\nInput:\t";
	int a;
	cin >> a;
	if (a < 1) {
		cout << "По Вашему это натруальрное число!?!?!?\n";
	}
	else
	{
		Num4 D;
		if (D.prime(a, 2))
			cout << "Число простое\n";
		else
			cout << "Число не является простым\n";
	}
	*/
	system("pause");
	return 0;
}

