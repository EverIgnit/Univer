#include "Header.h"
#include <iostream>
#include <windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// ������ 1
	/*
	cout << "������� K �� 1 �� 180\n��� ��������� ��������� ������� ����� ��� ���� �����\n";
	int k = 1;
	while ((k > 0) && (k < 181)) {
		cout << "Input:\t";
		cin >> k;
		Posl D(k);
		cout << "� " << k << "-� ������� ���������� ����� " << D.find() << endl;
		//10111213141516171819202122232425...
	}
	*/
	// ������ 2
	/**/
	cout << "������� ���������� ��� ������� �� ���������\n";
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	Point A(x1, y1), B(x2, y2), C(x3, y3);
	if (check(A, B, C))
	cout << "��� ��� ������ ����� ��������, �� �����������\n";
	else
	cout << "��� ��� ������ ���������� ��������, �� �����������\n";
	// 1 8 -2 -7 -4 -17    true
	/**/
	// ������ 3
	/*
	// ������� � �������������, ������� ����� �� ���������������� 4.108 � 5.66
	cout << "������� ����� ���� ����������� ����� � ���� a2a1, b2b1\n";
	int a2, a1, b2, b1;
	cin >> a2 >> a1 >> b2 >> b1;
	Number A(a2, a1), B(b2, b1);
	cout >> A - B;
	*/
	// ������ 4
	/*
	cout << "������� ����������� ����� n\n";
	int n;
	cin >> n;
	NumF a(n);
	a.func();
	*/
	system("pause");
	return 0;
}