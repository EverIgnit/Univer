#pragma once
#include <iostream>
#include <string>
using namespace std;
// Задача 1
class Num1 {
	int m, n, **arr, *a, *b;
public:
	Num1();
	void NumA();
	void NumB();
};
// Задача 2
class Num2 {
	int Fig;
	int Fig2;
	int Cell;
	int Cell2;
	int* d;
	int* Knight(int);
	int* Bishop(int);
	int* Queen(int);
	int* Rook(int);
	int* King(int);
public:
	Num2();
	int getFig();
	int getFig2();
	int getCell();
	int getCell2();
	bool Secure();
	int* FillArray(int, int);
	int* FinalCells(int*, int*);
	void OutP(int*);
	~Num2();
};
// Задача 3
class Num3 {
	int cost, age;
public:
	int getcost();
	int getage();
	Num3();
};
// Задача 4
class Num4 {
	string surname;
	int smtall;
public:
	Num4();
	int getsmtall();
	string getsurname();
};
