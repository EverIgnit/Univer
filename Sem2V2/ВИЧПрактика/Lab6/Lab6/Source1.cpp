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
	cout << "������� ���������� �����, ������� ���������� ��������\n� ����� �����, � ����� ���������� ����������� ����� � ���� �����.\n������� ���������� ��� �������� ������.\nInput:\t";
	for (int i = 0; i < 5; i++) {
		cin >> a[i] >> b[i];
	}
}
void Num2::Calc() {
	cout << "������ ������:\n";
	for (int i = 0; i < 5; i++) {
		if (a[i] == b[i])
			cout << i + 1 << " - �����\n";
		else
			if (a[i] > b[i])
				cout << i + 1 << " - ������\n";
			else
				cout << i + 1 << " - ���������\n";
	}
}
void Num2::Calc2(){
	cout << "������ ������:\n";
	for (int i = 0; i < 5; i++) {
		c[i] = a[i] - b[i];
		if (c[i] == 0)
			cout << i + 1 << " - �����\n";
		else
			if (c[i] > 0)
				cout << i + 1 << " - ������\n";
			else
				cout << i + 1 << " - ���������\n";
	}
}
// 3
Num3::Num3(){
		cout << "������� ���������� ��������� ����������� �������, � ����� � ��� ������,\n��������� �� ��������� ����� �����\nInput: ";
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
	// �������� 2 "��������"
	for (int i1 = 0; i1 < 2; i1++) {
		// � ������ ������������
		for (int j = i1; j < 5 - i1; j++, count++)
			a[i1][j] = count;
		for (int i = i1 + 1; i < 5 - i1; i++, count++)
			a[i][4 - i1] = count;
		for (int j = 3 - i1; j >= i1; j--, count++)
			a[4 - i1][j] = count;
		for (int i = 3 - i1; i > i1; i--, count++)
			a[i][i1] = count;
	}
	// ����������� �������
	a[2][2] = count;
}
