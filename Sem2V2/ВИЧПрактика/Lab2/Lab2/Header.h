#pragma once
#include <iostream>
using namespace std;
// Задача 1
class Posl {
	int k; // Номер искомого числа
public:
	// Конструктор
	Posl(int k) {
		this->k = k;
	}
	// Поиск цифры по номеру
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
// Задача 2
class Point {
	int x;
	int y;
public:
	// Конструктор
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	// Get'ты
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};
//Математическая проверка "лежат ли три точки на одной прямой"
bool check(Point A, Point B, Point C) {
	if ((((A.getX() - C.getX())*(B.getY() - C.getY()) - (B.getX() - C.getX())*(A.getY() - C.getY()))/2)==0)
		return true;
	return false;
}
// Задача 3
// Условие в Златопольский, Сборник задач по программированию 4.108 и 5.66
class Number {
	int a;
	int b;
public:
	// Конструктор
	Number(int a, int b) {
		this->a = a;
		this->b = b;
	}
	// get'ты
	int getA() {
		return a;
	}
	int getB() {
		return b;
	}
};
//Разность двух чисел
Number operator-(Number A, Number B) {
	if (A.getB() < B.getB())
		return Number(A.getA() - 1 - B.getA(), A.getB() - B.getB() + 10);
	return Number(A.getA() - B.getA(), A.getB() - B.getB());
}
void operator>> (ostream& out,Number A) {
	out << A.getA() << ' ' << A.getB() << endl;
}
// Задача 4
class NumF {
	int n; // Искомый номер элемента в последовательности Фибоначи
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
			cout << "Сумма чётная\n";
		else
			cout << "Сумма нечётная\m";
	};
};