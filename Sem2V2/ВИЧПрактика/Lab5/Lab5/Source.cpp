// ��������� ����
#include "Header.h"
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// ������ 1
	/*
	cout << "������� 2 �����\nInput:\t";
	string s1;
	getline(cin, s1);
	if (CheckS(s1)) {
		Num1 A(s1);
		A.EraseTheSame();
		A.Calc();
	}
		cout << endl;
	*/
	// ������ 2
	/*
	cout << "������� ������ ������ ��� ��������� � �������� ��������,\n� ����� ����� - � ����� �����, ������ ����������\nInput:\t";
	string s2; int newl;
	getline(cin, s2);
	cin >> newl;
	Num2 B(s2, newl);
	if (B.Check()==true) {
		B.Add();
	}
	*/
	// ������ 3
	/**/
	cout << "������� ��� ������, ���������� ����� �\nInput:\t";
	string s1, s2;
	getline(cin, s1);
	cout << "Input:\t";
	getline(cin, s2);
	Num3 C;
	C.Calc(s1, s2);
	/**/
	// ������ 4
	/*
	cout << "������� ����������� ����� n\nInput:\t";
	int a;
	cin >> a;
	if (a < 1) {
		cout << "�� ������ ��� ������������ �����!?!?!?\n";
	}
	else
	{
		Num4 D;
		if (D.prime(a, 2))
			cout << "����� �������\n";
		else
			cout << "����� �� �������� �������\n";
	}
	*/
	system("pause");
	return 0;
}

