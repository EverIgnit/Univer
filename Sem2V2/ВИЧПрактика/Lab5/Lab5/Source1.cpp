#include "Header.h"
#include <iostream>
#include <string>
using namespace std;
// ������ 1
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
				cout << "�� ";
				break;
			}
			if (j == s.length() - 1) {
				cout << "��� ";
			}
		}
	}
}
bool CheckS(string s) {
	for (int i = 0; i <s.size(); i++) {
		if (s[i] == ' ')
			return true;
		if (i == s.size() - 1) {
			cout << "����� ������ 2 �����\n";
			return false;
		}
	}
}
//������ 2 (����)
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
			cout << "� ������ ��� ��������\n";
			return false;
		}
	}
}

void Num2::Add() {
	while (d) {
		for (int i = 1; i < str.length(); i++) {
			if ((str[i] == ' ') && (d > 0) && str[i - 1] != ' ') {
				str.insert(i, "*"); // ��� ����������� �������� �� ���������, � ��������.
				d--;
				i++;
			}
		}
	}
	cout << str << endl;
}

// ������ 3
void Num3::Calc(string s1, string s2) {
	int t1 = s1.rfind('�', s1.size()),
		t2 = s2.rfind('�', s2.size());
	if (t1 == t2) {
		if (t1 < 1) {
			cout << "\"�\" �� ������ �� � ���� �� �����\n";
		}
		else
			cout << "\"�\" ������ � ��� ������ � ���������� �������\n";
	}
	else
	{
		cout << "\"�\" ����� ������� ������� � ";
		if (t1 > t2)
			cout << "������ ������\n";
		else
			cout << "������ ������\n";
	}
}
// ������ 4
bool Num4::prime(int a, int del)
{
	if (del > a / 2)
		return true;
	if (a%del != 0)
		return prime(a, ++del);
	else return false;
}