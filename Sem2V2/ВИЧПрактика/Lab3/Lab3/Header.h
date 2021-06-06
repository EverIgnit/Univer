#pragma once
#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;
//������ 1
/*���� ����������� ������������ � ��������, ������� ���������� �����������.
�� ������ � ������ �������� ��� ��������: "����� ����� �������� - ��� ���������� ���������� �����, � ������������ ����� � �������� ���� ����� ����� ��
�� ����� ���������� �����". �� ����� ��������� ��� ������ ����� ��������?*/
class Number {
public:
	Number() {
		for (int i = 10; i < 99; i++)
			if ((i % 10 + i / 10)*(i % 10 - i / 10) == i)
				cout << i << endl;
	}
};
//������ 2
/*��� ������ ������� ��������� (������ - ���� - �����) ����. ������ ������
������ ���� ���� ������ ������ : ������ ��������� �� ����� ���� ����������.
������� � ������ ����� ���� ������ �����, ���� ��� ������ ������� ����
�� ����� 1.5 � � ������ ������ - 3 ���� �������� ����� ?
�� ���� ��� ���� 5 � �����, � ��������� ������� ���������� 2,2 ���� �� 1 ��.
� ����� ����� 200 � �����.*/
class Scarf {
public:
	Scarf() {
		int ir = 1, iw = 2, ib = 3;		// i - ������ ������, l - �����, r,w,b - red, white, blue
		float rows, lr = 0, lw = 0, lb = 0, l = 0;
		// ������� ����� �����, ����������� ��� �����
		for (int i = 1;; i++) {
			rows = ceil(pow(4, (i - 1)) / pow(3, i - 2));
			//cout << rows << '\n';
			l += rows;
			// ��������, ������ ����� ����� ����
			if (i == ir) {
				lr += rows;
				ir += 3;

			}
			if (i == iw) {
				lw += rows;
				iw += 3;
			}
			if (i == ib) {
				lb += rows;
				ib += 3;
			}
			if (l > ceil(150 * 2.2))
				break;
		}
		// ������� ���������� ������ ����� ��� �������
		cout << "����� ������\n" << ceil(lr / 40) << " ������� ����a(��)";
		cout << ",\n" << ceil(lw / 40) << " ����� �����(��)";
		cout << ",\n" << ceil(lb / 40) << " ����� �����(��)\n";
	}
};
// ������ 3
class Num {
	int x;
	int X; // Copy
	int tens; // 10^(amount of digits-1)
	int Tens; // Copy
	int result;
public:
	Num(int x) {
		this->x = x;
		X = x;
		tens = 1;
		while (X) {
			X /= 10;
			tens *= 10;
		}
		tens /= 10;
		Tens = tens;
	}
	int numa() {
		X = x;
		result = 0;
		while (X) {
			result += Tens*(X % 10);
			X /= 10;
			Tens /= 10;
		}
		X = x;
		return result;
	}
	int numb() {
		if (!x) {
			return result = 202;
		}
		result= 2 * tens * 100 + 10 * x + 2;
		return result;
	}
	int numv(int a) {
		result = 0;
		X = x;
		Tens = 1;
		while (X) {
			if (X % 10 != a) {
				result += Tens*(X % 10);
			}
			else
				Tens /= 10;
			X /= 10;
			Tens *= 10;
		}
		return result;
	}
	int numg() {
		if (!x)
			return 0;
		result = (x % 10)*tens + ((x%tens) / 10) * 10 + x / tens;
		if (tens > 1)
			return result;
		return result - x;
	}
	int numd() {
		result = x + x*tens * 10;
		return result;
	}
};
// ������ 4
class CheckSorersh {
public:
	CheckSorersh(int a) {
		int sum = 0;
		for (int i = 1; i < a; i++) {
			if (a%i == 0)
				sum += i;
		}
		if (sum == a)
			cout << "����� �����������\n";
		else
			cout << "����� �� �������� ����������\n";
	}
};