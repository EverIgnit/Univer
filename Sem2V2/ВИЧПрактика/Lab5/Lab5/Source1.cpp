#include "Header.h"
#include <iostream>
#include <string>
using namespace std;
// Задача 1
Num1::Num1(string s) {
	this->s = s;
}
void Num1::EraseTheSame() {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] ==' ')
			continue;
		for (int j = i + 1; j < s.length() && s[j] != ' '; j++) {
			if (s[i] == s[j]) {
				s.erase(j, 1);
				i--;
				j--;
			}
		}
	}
	cout << s << endl;
	int i = 0;
	while (s[i] != ' ') i++;
	space = i;
}
void Num1::Calc() {
	for (int i = 0; i != space; i++) {
		for (int j = space + 1; j < s.length(); j++) {
			if (s[i] == s[j]) {
				cout << "Да ";
				break;
			}
			if (j == s.length() - 1) {
				cout << "Нет ";
			}
		}
	}
}
bool CheckS(string s) {
	for (int i = 0; i <s.size(); i++) {
		if (s[i] == ' ')
			return true;
		if (i == s.size() - 1) {
			cout << "Нужно ввести 2 слова\n";
			return false;
		}
	}
}
//Задача 2 (тест)
Num2::Num2(string s, int newl) {
	str = s;
	a = newl;
	d = a - str.length();
}

bool Num2::Check() {
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ')
			return true;
		if (i == str.size() - 1)
		{
			cout << "В строке нет пробелов\n";
			return false;
		}
	}
}

void Num2::Add() {
	while (d) {
		for (int i = 1; i < str.length(); i++) {
			if ((str[i] == ' ') && (d > 0) && str[i - 1] != ' ') {
				str.insert(i, "*"); // Для наглядности заполняю не пробелами, а полосами.
				d--;
				i++;
			}
		}
	}
	cout << str << endl;
}

// Задача 3
void Num3::Calc(string s1, string s2) {
	int t1 = s1.rfind('ш', s1.size()),
		t2 = s2.rfind('ш', s2.size());
	if (t1 == t2) {
		if (t1 < 1) {
			cout << "\"ш\" не входит ни в одну из строк\n";
		}
		else
			cout << "\"ш\" входит в обе строки в одинаковой позиции\n";
	}
	else
	{
		cout << "\"ш\" имеет больший порядок в ";
		if (t1 > t2)
			cout << "первой строке\n";
		else
			cout << "второй строке\n";
	}
}
// Задача 4
bool Num4::prime(int a, int del)
{
	if (del > a / 2)
		return true;
	if (a%del != 0)
		return prime(a, ++del);
	else return false;
}