#pragma once
#include <iostream>
#include <Windows.h>
#include <string.h>
using namespace std;
//Задача 1
/*Один программист познакомился с девушкой, которая увлекалась математикой.
На вопрос о номере телефона она ответила: "Номер моего телефона - три одинаковых двузначных числа, а произведение суммы и разности цифр этого числа то
же самое двузначное число". По какой программе был найден номер телефона?*/
class Number {
public:
	Number() {
		for (int i = 10; i < 99; i++)
			if ((i % 10 + i / 10)*(i % 10 - i / 10) == i)
				cout << i << endl;
	}
};
//Задача 2
/*Оля решила связать полосатый (красно - бело - синий) шарф. Причем полосы
должны были быть разной ширины : каждая следующая на треть шире предыдущей.
Сколько и какого цвета надо купить пряжи, если Оля решила связать шарф
не менее 1.5 м и первая полоса - 3 ряда красного цвета ?
На один ряд идет 5 м пряжи, а плотность вязания составляет 2,2 ряда на 1 см.
В одном мотке 200 м пряжи.*/
class Scarf {
public:
	Scarf() {
		int ir = 1, iw = 2, ib = 3;		// i - индекс полосы, l - длина, r,w,b - red, white, blue
		float rows, lr = 0, lw = 0, lb = 0, l = 0;
		// Подсчёт длины пряжи, необходимой для шарфа
		for (int i = 1;; i++) {
			rows = ceil(pow(4, (i - 1)) / pow(3, i - 2));
			//cout << rows << '\n';
			l += rows;
			// Проверка, какого цвета нужна нить
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
		// Подсчёт количества мотков пряжи для покупки
		cout << "Нужно купить\n" << ceil(lr / 40) << " красных моткa(ов)";
		cout << ",\n" << ceil(lw / 40) << " белых мотка(ов)";
		cout << ",\n" << ceil(lb / 40) << " синих мотка(ов)\n";
	}
};
// Задача 3
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
// Задача 4
class CheckSorersh {
public:
	CheckSorersh(int a) {
		int sum = 0;
		for (int i = 1; i < a; i++) {
			if (a%i == 0)
				sum += i;
		}
		if (sum == a)
			cout << "Число совершенное\n";
		else
			cout << "Число не является соверенным\n";
	}
};