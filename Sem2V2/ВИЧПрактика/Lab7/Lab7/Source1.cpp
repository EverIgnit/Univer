#include "Header.h"
#include <iostream>
#include <windows.h>
using namespace std;
// 1
Num1::Num1() {
	cout << "Введите размер двумерного массива (m x n), а затем сам массив(int)\nInput: ";
	cin >> m >> n;
	arr = new int*[m], a = new int[m], b = new int[n];
	for (int i = 0; i < m; i++) {
		arr[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}
void Num1::NumA(){
	int imax = 0;
	double max = 0.0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (fabs(arr[i][j]) > max) {
				max = fabs(arr[i][j]);
				imax = j;
			}
		}
		max = 0;
		a[i] = arr[i][imax];
	}
	cout << "a)";
	for (int i = 0; i < m; i++) {
		cout << ' ' << a[i];
	}
}
void Num1::NumB() {
	int imax = 0;
	double max = 0.0;
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			if (fabs(arr[i][j]) > max) {
				max = fabs(arr[i][j]);
				imax = i;
			}
		}
		max = 0;
		b[j] = arr[imax][j];
	}
	cout << "\nb)";
	for (int j = 0; j < n; j++) {
		cout << ' ' << b[j];
	}
	cout << endl;
}
// 2
Num2::Num2() {
	cin >> Fig >> Cell >> Fig2 >> Cell2;
}
int Num2::getFig() {
	return Fig;
}
int Num2::getFig2() {
	return Fig2;
}
int Num2::getCell() {
	return Cell;
}
int Num2::getCell2() {
	return Cell2;
}
bool Num2::Secure() {
	if (Fig < 1 || Fig>4 || Fig2 < 1 || Fig2>5 || Cell < 11 || Cell>88 || Cell2 < 11 || Cell2>88 || Cell % 10 > 8 || Cell2 % 10 > 8 || Cell == Cell2)
		return false;
	return true;
}
int* Num2::FillArray(int a, int b) {
	int *c;
	if (a == 1)
		c = Knight(b);
	else
		if (a == 3)
			c = Queen(b);
		else
			if (a == 4)
				c = Rook(b);
			else
				if (a == 5)
					c = King(b);
				else
					c = Bishop(b);
	return c;
}
int* Num2::Rook(int b) {
	int *a=new int[16];
	a[0] = 14;
	int counter = 1;
	for (int i = 1; i <= 8; i++) {
		if (i != b % 10) {
			a[counter] = b / 10 * 10 + i;
			counter++;
		}
		if (i != b / 10) {
			a[counter] = i*10 + b % 10;
			counter++;
		}
	}
	return a;
}
int* Num2::Bishop(int b) {
	int *a = new int[17];
	a[0] = 0;
	int counter = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if ((abs(j - b / 10) == abs(i - b % 10)) && j * 10 + i != b) {
				counter++;
				a[counter] = j * 10 + i;
				a[0]++;
			}
		}
	}
	return a;
}
int* Num2::King(int b) {
	int counter = 0, *a=new int[10];
	a[0] = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if ((abs(j - b / 10) <= 1 && abs(i - b % 10) <= 1) && j * 10 + i != b) {
				counter++;
				a[counter] = j * 10 + i;
				a[0]++;
			}
		}
	}
	return a;
}
int* Num2::Queen(int b) {
	int *a = new int[30];
	int counter = 0;
	a[0] = 0;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if ((i == b % 10 || j == b / 10 || abs(i - b % 10) == abs(j - b / 10)) && (j * 10 + i != b)) {
				counter++;
				a[counter] = j * 10 + i;
				a[0]++;
			}
		}
	}
	return a;
}
int* Num2::Knight(int b) {
	int *a = new int[9];
	a[0] = 0;
	int counter = 0;
	for (int i = 1; i<=8; i++) {
		for (int j = 1; j <= 8; j++) {
			if ((abs(j - b / 10) == 2 && abs(i - b % 10) == 1) || (abs(j - b / 10) == 1 && abs(i - b % 10) == 2)) {
				counter++;
				a[counter] = j * 10 + i;
				a[0]++;
			}
		}
	}
	return a;
}
int* Num2::FinalCells(int*b, int*c) {
	int *a = new int[b[0]];
	int counter = 0; a[0] = 0;
	for (int i = 1; i <= b[0]; i++) {
		for (int j = 1; j <= c[0]; j++) {
			if (b[i] == c[j]) {
				break;
			}
			if (j == c[0]) {
				counter++;
				a[counter] = b[i];
				a[0]++;
			}
		}
	}
	return a;
}
void Num2::OutP(int*r) {
	int j, k;
	for (int i = 8; i >= 1; i--) {
		for (j = 1; j <= 8; j++) {
			for (k = 1; k <= r[0]; k++) {
				if (j * 10 + i == r[k]) {
					cout << "+ ";
					break;
				}
				if (k == r[0])
					cout << "= ";
			}
		}
		cout << endl;
	}
}
Num2::~Num2() {
	delete[]d;
}
// 3
int Num3::getcost() {
	return cost;
}
int Num3::getage() {
	return age;
}
Num3::Num3() {
	cin >> cost >> age;
}
// 4
Num4::Num4(){
	cin >> surname >> smtall;
}
int Num4::getsmtall() {
	return smtall;
}
string Num4::getsurname() {
	return surname;
}