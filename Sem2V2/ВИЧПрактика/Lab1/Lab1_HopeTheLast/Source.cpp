// ��������� ����
#include "Header.h"
#include <iostream>
#include <windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// ������ 1
	/*
	cout << "������� ���-�� ������, ��\n ������������, � ����� ������������ ��������, � ���� ���������� ������ �� �����������\n";
	int k, m, b, i;
	cin >> k >> m >> b >> i;
	School A(k, m, b, i);
	cout << "� ���� ���� ������ ����� " << A.DayLength()/60 <<" ����� "<<A.DayLength()%60<<" ����� � �����\n";
	*/
	//������ 2
	/*
	cout << "������� ����������� ������������� �����\nInput:\t";
	int value;
	cin >> value;
	Num B(value);
	B.Calculate();
	cout << "���������� �����: " << B.getM() << endl;
	*/
	// ������ 3
	/*
	cout << "�� ������� ���������� ����������� ����� x ��� ����� ����� n?\nInput:\t";
	char xn;
	cin >> xn;
	cout << "������ ������� �������� ����� �����\nInput:\t";
	int val;
	cin >> val;
	XN C(val);
	cout << "���������� �����: " << C.Calculate(xn) << endl;
	*/
	// ������ 4
	/**/
	cout << "������� ����� �� ����� (h �����, m �����)\nInput:\t";
	int h, m;
	cin >> h >> m;
	Time D(h, m);
	int kjl = 1;
	cout << "������� �������� ����� " << D.Calculate(kjl)
		<< " �����\n������� ����� �������������� ����������� ����� ";
	cout << D.Calculate(0) << " �����\n";
	/**/
	system("pause");
	return 0;
}