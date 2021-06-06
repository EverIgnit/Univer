#pragma once
#include <iostream>
using namespace std;
// ������ 1
class Posl {
	int k; // ����� �������� �����
public:
	// �����������
	Posl(int k) {
		this->k = k;
	}
	// ����� ����� �� ������
	int find() {
		int answer;
		if (k % 2 == 0)
			answer = (k - 2) / 2;
		else
			answer = k / 20 + 1;
		if (answer > 9)
			return answer % 10;
		return answer;
	}
};
// ������ 2
class Point {
	int x;
	int y;
public:
	// �����������
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	// Get'��
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};
//�������������� �������� "����� �� ��� ����� �� ����� ������"
bool check(Point A, Point B, Point C) {
	if ((((A.getX() - C.getX())*(B.getY() - C.getY()) - (B.getX() - C.getX())*(A.getY() - C.getY()))/2)==0)
		return true;
	return false;
}
// ������ 3
// ������� � �������������, ������� ����� �� ���������������� 4.108 � 5.66
class Number {
	int a;
	int b;
public:
	// �����������
	Number(int a, int b) {
		this->a = a;
		this->b = b;
	}
	// get'��
	int getA() {
		return a;
	}
	int getB() {
		return b;
	}
};
//�������� ���� �����
Number operator-(Number A, Number B) {
	if (A.getB() < B.getB())
		return Number(A.getA() - 1 - B.getA(), A.getB() - B.getB() + 10);
	return Number(A.getA() - B.getA(), A.getB() - B.getB());
}
void operator>> (ostream& out,Number A) {
	out << A.getA() << ' ' << A.getB() << endl;
}
// ������ 4
class NumF {
	int n; // ������� ����� �������� � ������������������ ��������
public:
	NumF(int n) {
		this->n = n;
	}
	void func() {
		int i = 1, j = 1, sum = 2, count = 2;
		cout << "1. - 1\n";
		do {
			cout << count << ". - " << j << endl;
			i += j;
			count++;
			sum += i;
			cout << count << ". - " << i << endl;
			j += i;
			count++;
			sum += j;
		} while (count < n);
		if (sum % 2 == 0)
			cout << "����� ������\n";
		else
			cout << "����� ��������\m";
	};
};