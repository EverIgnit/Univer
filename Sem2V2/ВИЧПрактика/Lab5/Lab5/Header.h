#pragma once
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;
// ������ 1
class Num1 {
	string s;
	int space;
public:
	Num1(string);
	void EraseTheSame();
	void Calc();
};
bool CheckS(string);
// ������ 2
int Amountofwords(string s);
string AddSpace(string s, int newl, int temp, int templeft);
class Num2 {
	string str;
	int a;
	int d;
public:
	Num2(string s, int newl);
	bool Check();
	void Add();
};
// ������ 3
class Num3 {
public:
	void Calc(string, string);
};
// ������ 4
class Num4 {
public:
	bool prime(int a, int del);
};