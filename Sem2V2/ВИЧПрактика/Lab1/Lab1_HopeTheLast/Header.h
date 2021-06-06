#pragma once
#include <iostream>
using namespace std;
// ��������� ���� - ���2
// ������ 1
class School {
	int k; // ���������� ������ �� m �����
	int m;
	int b; //break - ������������ �������� ����� �������
	int i; //���������� ��� �� �����������
public:
	School(int k, int m, int b, int i) {
		this->k = k;
		this->m = m;
		this->b = b;
		this->i = i;
	} //�����������
	int DayLength() {
		return k * m + (k)*b + m * i;
	} //������������ �������� ���
};
// ������ 2
class Num {
	int value;  // �������� �����
	int M;		// �������� �����
public:
	// �����������
	Num(int value) {
		this->value = value;
	}
	// ������
	int getM() {
		return M;
	}
	// ���������� M
	void Calculate() {
		M = value / 1000 * 1000 + value % 10 + value % 100 / 10 * 100 + value / 100 % 10 * 10;
	}
};
// ������ 3:
// ������� � �������������, ������� ����� �� ����������������. 2.25 � 2.42
class XN {
	int value;
public:
	//�����������
	XN(int value) {
		this->value = value;
	}
	//���������� ������� �����
	int Calculate(char a) {
		if (a == 'x')
			return (value % 10 * 1000 + value) / 10;  // n ����� x
		if (a == 'n')
			return  value / 100 + value % 100 * 10;	// x ����� n
	}
};
// ������ 4:
class Time {
	int h; // ���������� �����
	int m; // ���������� �����
public:
	// �����������
	Time(int h, int m) {
		this->h = h;
		this->m = m;
	}
	// ����������
	int Calculate(int a) { // ��� ���������� ���������������� �����������
		// �������� � ������� �������
		if (a == 0)
			h += 3;
		if (h > 12)
			h %= 12;
		int	mh = h * 5 - m;
		// ���������
		if (mh > 0)
			return mh;
		if (mh == 0)
			return 0;
		return mh + 65;
	}
};