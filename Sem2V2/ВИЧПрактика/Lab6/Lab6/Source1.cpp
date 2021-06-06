#include "Header.h"
#include <iostream>
#include <Windows.h>
using namespace std;
// 1
void Num1::Calc() {
	string s;
	double long k = 2;
	for (int i = 1; i < 100; i++)
	{
		k *= 2;
	}
	s = to_string(k);
	for (int i = 0; s[i] != '.'; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}
// 2
Num2::Num2(){
	cout << "Введите количество мячей, забитых футбольной командой\nв одном матче, а затем количество пропущенных мячей в этом матче.\nВнесите информацию для двадцати матчей.\nInput:\t";
	for (int i = 0; i < 5; i++) {
		cin >> a[i] >> b[i];
	}
}
void Num2::Calc() {
	cout << "Первый способ:\n";
	for (int i = 0; i < 5; i++) {
		if (a[i] == b[i])
			cout << i + 1 << " - Ничья\n";
		else
			if (a[i] > b[i])
				cout << i + 1 << " - Победа\n";
			else
				cout << i + 1 << " - Поражение\n";
	}
}
void Num2::Calc2(){
	cout << "Второй способ:\n";
	for (int i = 0; i < 5; i++) {
		c[i] = a[i] - b[i];
		if (c[i] == 0)
			cout << i + 1 << " - Ничья\n";
		else
			if (c[i] > 0)
				cout << i + 1 << " - Победа\n";
			else
				cout << i + 1 << " - Поражение\n";
	}
}
// 3
Num3::Num3(){
		cout << "Введите количество элементов одномерного массива, а затем и сам массив,\nсостоящий из ненулевых целых чисел\nInput: ";
		cin >> n;
		right = n - 1;
		left = 0;
		a = new int[n];
		b = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
}
void Num3::OutP(){
	for (int i = 0; i < n; i++) {
		cout << b[i] << ' ';
	}
	cout << endl;
}
void Num3::Calc() {
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			b[left] = a[i];
			left++;
		}
		else
		{
			b[right] = a[i];
			right--;
		}
	}
}
Num3::~Num3(){
	delete[]a;
	delete[]b;
}
// 4
void Num4::OutP(){
	for (int i = 0; i < 5; i++) {
		{
			for (int j = 0; j < 5; j++) {
				cout << a[i][j] << '\t';
			}
			cout << endl;
		}
	}
}
Num4::Num4() {
	count = 1;
}
void Num4::Calc() {
	// Проходим 2 "квадрата"
	for (int i1 = 0; i1 < 2; i1++) {
		// В четырёх направлениях
		for (int j = i1; j < 5 - i1; j++, count++)
			a[i1][j] = count;
		for (int i = i1 + 1; i < 5 - i1; i++, count++)
			a[i][4 - i1] = count;
		for (int j = 3 - i1; j >= i1; j--, count++)
			a[4 - i1][j] = count;
		for (int i = 3 - i1; i > i1; i--, count++)
			a[i][i1] = count;
	}
	// Центральный элемент
	a[2][2] = count;
}
