#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;
// ������ 1
class Num1 {
public:
	void Calc();
};
// ������ 2
class Num2 {
	int a[20], b[20], c[20];
public:
	Num2();
	void Calc();
	void Calc2();
};
// ������ 3
class Num3 {
	int *a, *b, n, left, right;
public:
	Num3();
	void OutP();
	void Calc();
	~Num3();
};
// ������ 4
class Num4 {
	int a[5][5], count;
public:
	Num4();
	void Calc();
	void OutP();
};