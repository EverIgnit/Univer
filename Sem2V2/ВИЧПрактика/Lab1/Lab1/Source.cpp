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
	cout << "Enter current time (0 < hours < 13, 0 < m < 61 �����)\nThen type 1 if we need to find perpendicular, 0 if we don't.\nInput:\t";
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