// ��������� ���� - ���2
#pragma once
#include <iostream>
using namespace std;
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
class Minutes {
	int min;
public:
	Minutes(int min) {
		this->min = min;
	}
	friend int operator+(Minutes m, int m2) {
		int result = m.min + m2;
		if (result > 60)
			result -= 60;
		return result;
	}
	friend int operator-(Minutes m, int m2) {
		int result = m.min - m2;
		if (result > 60)
			result -= 60;
		if (result < 0)
			result += 60;
		return result;
	}
	int getmin() {
		return min;
	}
	void setmin(int min) {
		this->min = min;
	}
};