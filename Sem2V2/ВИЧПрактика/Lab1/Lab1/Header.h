// Белькевич Глеб - Вар2
#pragma once
#include <iostream>
using namespace std;
// Задача 1
class School {
	int k; // Количество уроков по m минут
	int m;
	int b; //break - длительность перемены между уроками
	int i; //количество пар по информатике
public:
	School(int k, int m, int b, int i) {
		this->k = k;
		this->m = m;
		this->b = b;
		this->i = i;
	} //Конструктор
	int DayLength() {
		return k * m + (k)*b + m * i;
	} //Длительность учебного дня
};
// Задача 2
class Num {
	int value;  // Значение числа
	int M;		// Конечное число
public:
	// Конструктор
	Num(int value) {
		this->value = value;
	}
	// Геттер
	int getM() {
		return M;
	}
	// Вычисление M
	void Calculate() {
		M = value / 1000 * 1000 + value % 10 + value % 100 / 10 * 100 + value / 100 % 10 * 10;
	}
};
// Задача 3:
// Условие в Златопольский, Сборник задач по программированию. 2.25 и 2.42
class XN {
	int value;
public:
	//Конструктор
	XN(int value) {
		this->value = value;
	}
	//Вычисление второго числа
	int Calculate(char a) {
		if (a == 'x')
			return (value % 10 * 1000 + value) / 10;  // n через x
		if (a == 'n')
			return  value / 100 + value % 100 * 10;	// x через n
	}
};
// Задача 4:
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